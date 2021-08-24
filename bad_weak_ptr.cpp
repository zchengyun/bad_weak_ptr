//std::bad_weak_ptr是当std::weak_ptr引用已删除的对象时，以std::weak_ptr作为参数的std::shared_ptr构造函数作为异常抛出的对象类型。
#include <iostream>
#include <memory>
int main()
{
	std::shared_ptr<int> p1(new int(10));
	std::weak_ptr<int> p2(p1); //std::weak_ptr引用已删除的对象
	p1.reset();
	try
	{
		std::shared_ptr<int> p3(p2);//std::weak_ptr作为参数的std::shared_ptr构造函数
	}
	catch (const std::bad_weak_ptr& e)
	{
		std::cout << e.what();
	}
}
