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

int n, p;
int x[MaxN];

int main()
{
	cin >> n >> p;
	for (int i = 1; i <= n; ++i)
		x[i] = getint();

	sort(x + 1, x + n + 1);

	int pos = 0;
	while (pos < n && x[pos + 1] <= p)
		++pos;

	if (n == 1)
		cout << 0;
	else if (!pos)
		cout << (n == 1 ? x[n] : x[n - 1]) - p;
	else if (pos == n)
		cout << p - (n == 1 ? x[1] : x[2]);
	else if (n == 2)
		cout << min(abs(p - x[1]), abs(p - x[2]));
	else
		cout << min(min(abs(p - x[2]), abs(x[n] - p)) + abs(x[2] - x[n]), min(abs(p - x[1]), abs(p - x[n - 1])) + abs(x[1] - x[n - 1]));

	return 0;
}