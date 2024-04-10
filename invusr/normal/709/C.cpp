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

int n;
char s[100001];

inline bool check()
{
	for (int i = 1; i <= n; ++i)
		if (s[i] != 'a')
			return false;
	return true;
}

int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);

	if (check())
	{
		for (int i = 1; i < n; ++i)
			putchar('a');
		putchar('z');
		return 0;
	}

	int p = 0;
	while (s[p + 1] == 'a')
		++p;
	for (int i = 1; i <= p; ++i)
		putchar('a');
	bool ok = true;
	for (int i = p + 1; i <= n; ++i)
	{
		if (s[i] == 'a')
			ok = false;
		putchar(s[i] - ok);
	}

	return 0;
}