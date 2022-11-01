#include <iostream>
#include <algorithm>
#include <cmath>

int main(int argc, char** argv)
{
	int x, y;
	std::cin >> x >> y;

	if((std::min(x, y) == 2 && std::max(x, y) == 4) || x == y)
	{
		std::cout << "=" << std::endl;

		return 0;
	}

	double a = y * std::log(x);
	double b = x * std::log(y);

	if(a < b)
		std::cout << "<" << std::endl;
	else
		std::cout << ">" << std::endl;

	return 0;
}