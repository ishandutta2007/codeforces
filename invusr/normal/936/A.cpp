#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

s64 k, d, t;

int main()
{
	cin >> k >> d >> t;

	d *= (k - 1) / d + 1;

	s64 p = k + d;
	s64 a = t * 2;

	s64 u = a / p * d;
	s64 r = a % p;
	if (r <= k * 2)
	{
		cout << u + r / 2 << ".";
		cout << (r & 1 ? '5' : '0');
		cout << endl;
	}
	else
	{
		r -= k * 2;
		cout << u + k + r;
		cout << endl;
	}

	return 0;
}