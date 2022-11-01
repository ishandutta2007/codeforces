#include <iostream>
#include <algorithm>

typedef long long int ll;

int main(int argc, char** argv)
{
	ll n, m, a, b;

	std::cin >> n >> m >> a >> b;

	ll x = n % m;

	std::cout << std::min(a * (m - x), b * x) << std::endl;

	return 0;
}