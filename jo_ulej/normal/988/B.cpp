#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

bool is_substr(const std::string& a, const std::string& b)
{
	for(int i = 0; i < b.size() - a.size() + 1; ++i)
	{
		bool flag = true;

		for(int j = 0; j < a.size(); ++j)
		{
			if(b[i + j] != a[j])
			{
				flag = false;
				break;
			}
		}

		if(flag)
			return true;
	}

	return false;
}

int main(int argc, char** argv)
{
	int n;
	bool success = true;
	std::vector<std::string> data;

	std::cin >> n;
	data.resize(n);

	for(int i = 0; i < n; ++i)
		std::cin >> data[i];

	std::sort(data.begin(), data.end(), [](const std::string& a, const std::string& b) { return a.size() < b.size(); });

	for(int i = 0; i < data.size() - 1; ++i)
	{
		if(!is_substr(data[i], data[i + 1]))
		{
			success = false;
			break;
		}
	}

	if(!success)
	{
		std::cout << "NO" << std::endl;

		return 0;
	}
	else
	{
		std::cout << "YES" << std::endl;
	}

	for(int i = 0; i < n; ++i)
		std::cout << data[i] << std::endl;

	return 0;
}