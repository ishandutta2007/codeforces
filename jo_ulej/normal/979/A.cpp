#include <bits/stdc++.h>

typedef long long int ll;

int main(int argc, char** argv)
{
	ll n;
	std::cin >> n;
	++n;

	if(n == 1)
	{
		std::cout << "0" << std::endl;

		return 0;
	}

	if(n % 2 == 1)
	{
		std::cout << n << std::endl;

		return 0;
	}

	n /= 2;

	std::cout << n << std::endl;

	return 0;
}