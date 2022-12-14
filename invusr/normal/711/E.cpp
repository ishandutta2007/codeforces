#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

const int M = 1000003;

inline int modpow(int a, const s64 &n)
{
	int res = 1;
	for (int i = n % (M - 1); i; i >>= 1)
	{
		if (i & 1)
			res = (s64)res * a % M;
		a = (s64)a * a % M;
	}
	return res;
}

inline int modinv(const int &a)
{
	return modpow(a, M - 2);
}

s64 n, k;

inline int calc_lowbit_sum(const s64 &k)
{
	int ret = 0;
	for (int i = 0; 1ll << i <= k; ++i)
	{
		s64 up_to = k >> i + 1;
		if (k >> i & 1)
			++up_to;
		ret = (ret + up_to * i) % (M - 1);
	}
	return (ret + n) % (M - 1);
}

inline void get_fraction(int &num, int &den)
{
	int days = modpow(2, n);
	num = 0;
	den = modpow(days, k);
	if (k >= M)
		return;

	num = 1;
	for (int i = 0; i < k; ++i)
	{
		int ways = days + M - i;
		num = (s64)num * ways % M;
	}
}

int main()
{
	cin >> n >> k;

	if (n <= 60 && 1ll << n < k)
	{
		cout << 1 << ' ' << 1 << endl;
		return 0;
	}

	int num, den, invGcd;
	get_fraction(num, den);
	invGcd = modinv(modpow(2, calc_lowbit_sum(k - 1)));
	num = (s64)num * invGcd % M;
	den = (s64)den * invGcd % M;
	num = (den - num + M) % M;
	cout << num << ' ' << den << endl;

	return 0;
}