#include <bits/stdc++.h>
using namespace std;

typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;

typedef double r32;
typedef long double r64;

template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tense(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

inline int getint()
{
	static char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');

	if (c == '-')
	{
		int res = 0;
		while ((c = getchar()) >= '0' && c <= '9')
			res = res * 10 + c - '0';
		return -res;
	}
	else
	{
		int res = c - '0';
		while ((c = getchar()) >= '0' && c <= '9')
			res = res * 10 + c - '0';
		return res;
	}
}
inline s64 gets64()
{
	static char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');

	if (c == '-')
	{
		s64 res = 0;
		while ((c = getchar()) >= '0' && c <= '9')
			res = res * 10 + c - '0';
		return -res;
	}
	else
	{
		s64 res = c - '0';
		while ((c = getchar()) >= '0' && c <= '9')
			res = res * 10 + c - '0';
		return res;
	}
}

int n, b, d, sum, cnt = 0;

int main()
{
	cin >> n >> b >> d;
	while (n--)
	{
		int x = getint();
		if (x <= b)
			sum += x;
		if (sum > d)
			sum = 0, ++cnt;
	}

	cout << cnt;

	return 0;
}