#include <bits/stdc++.h>
using namespace std;

typedef long long s64;

int main()
{
	s64 n;
	cin >> n;
	if (n == 1 || n == 2)
	{
		puts("-1");
		return 0;
	}

	if (n & 1)
	{
		s64 m = n * n / 2;
		cout << m << ' ' << m + 1;
	}
	else if (n >> 1 & 1)
	{
		n >>= 1;
		s64 m = n * n / 2;
		cout << m * 2 << ' ' << m * 2 + 2;
	}
	else
	{
		n >>= 2;
		cout << n * 3 << ' ' << n * 5;
	}

	return 0;
}