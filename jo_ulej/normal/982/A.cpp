#include <iostream>
#include <string>


int main(int argc, char** argv)
{
	int n;
	std::string s;

	std::cin >> n >> s;

	if(s == "0")
	{
		std::cout << "No" << std::endl;

		return 0;
	}

	if(n > 1)
	{
		if(s[0] == '0' && s[1] == '0')
		{
			std::cout << "No" << std::endl;

			return 0;
		}

		if(s[n - 2] == '0' && s[n - 1] == '0')
		{
			std::cout << "No" << std::endl;

			return 0;
		}
	}

	if(s.find("11") != std::string::npos)
	{
		std::cout << "No" << std::endl;

		return 0;
	}

	if(s.find("000") != std::string::npos)
	{
		std::cout << "No" << std::endl;

		return 0;
	}

	std::cout << "Yes" << std::endl;

	return 0;
}