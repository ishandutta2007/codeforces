#include <iostream>
#include <algorithm>


int main(int argc, char** argv)
{
	int a[1000];
	int n;

	std::cin >> n;

	for(int i = 0; i < n; ++i)
		std::cin >> a[i];

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < i; ++j)
		{
			if(a[j] > a[i])
				std::swap(a[i], a[j]);
		}
	}

	if(n % 2 == 1)
	{
		std::cout << a[(n - 1) / 2] << std::endl;
	}
	else
	{
		std::cout << a[n / 2 - 1] << std::endl;
	}

	return 0;
}