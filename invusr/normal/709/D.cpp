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

const int MaxN = 1000005;

s64 a, b, c, d;
int cur = 0;
char s[MaxN];

inline void orz(char c)
{
	s[cur++] = c;
}

int main()
{
	cin >> a >> b >> c >> d;
	s64 tot = a + b + c + d, n = -1;
	for (int i = 1; i <= 1000000; ++i)
		if ((s64)i * (i - 1) / 2 == tot)
		{
			n = i;
			break;
		}
	if (n == -1)
	{
		puts("Impossible");
		return 0;
	}

	if (a == tot)
	{
		for (int i = 0; i < n; ++i)
			orz('0');
	}
	else if (d == tot)
	{
		for (int i = 0; i < n; ++i)
			orz('1');
	}
	else
	{
		int n0 = -1;
		for (int i = 1; i <= 1000000; ++i)
			if ((s64)i * (i - 1) / 2 == a)
			{
				n0 = i;
				break;
			}
		int n1 = -1;
		for (int i = 1; i <= 1000000; ++i)
			if ((s64)i * (i - 1) / 2 == d)
			{
				n1 = i;
				break;
			}
		if (n0 == -1 || n1 == -1 || b + c != (s64)n0 * n1)
		{
			puts("Impossible");
			return 0;
		}

		s64 u = b / n0 + (b % n0 > 0);
		if (u > n1)
		{
			puts("Impossible");
			return 0;
		}

		for (int i = 0; i < n1 - u; ++i)
			orz('1');
		for (int i = 1; i <= n0; ++i)
		{
			orz('0');
			if (b % n0 == i)
				orz('1');
		}
		for (int i = 0; i < b / n0; ++i)
			orz('1');
	}

	puts(s);

	return 0;
}