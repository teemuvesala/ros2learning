#include "rclcpp/rclcpp.hpp"

class MyFirstNode : public rclcpp::Node {
public:
  MyFirstNode() : Node("cpp_test"),counter_(0) {
    RCLCPP_INFO(this->get_logger(), "Hello, world!");
    timer_ = this->create_wall_timer(std::chrono::seconds(1), 
        std::bind(&MyFirstNode::timer_callback, this));
  }
private:
  rclcpp::TimerBase::SharedPtr timer_;
  void timer_callback() {
    counter_++;
    RCLCPP_INFO(this->get_logger(), "Hello, world %d!", counter_);
  }
  int counter_;

};

int main(int argc, char **argv) {
  // Initialize the ROS node
  rclcpp::init(argc, argv);
  auto node = std::make_shared<MyFirstNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}