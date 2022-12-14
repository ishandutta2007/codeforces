#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

const int MaxN = 300005;

int n, a[MaxN];
int outcome[MaxN];

inline int get_o(int x)
{
	return min(a[x], max(a[x - 1], a[x + 1]));
}
inline int expand_o(int x, int d, int l)
{
	int y = x + d;
	if (y - l < 1)
		return x;
	if (y + l > n)
		return x;
	return y;
}

inline void solve_all_o(int st)
{
	int len = st / 2;
	int now = 0, l = 0, r;
	for (int i = 1; i <= n; ++i)
	{
		if (i - len < 1 || i + len > n)
			continue;
		l = (r = i, !l) ? i : l;
		relax(now, get_o(i));
	}

	for (int i = st; i > 1; i -= 2)
	{
		outcome[i] = now;
		l = expand_o(l, -1, i / 2 - 1);
		r = expand_o(r, +1, i / 2 - 1);
		relax(now, get_o(l));
		relax(now, get_o(r));
	}
}

inline int get_e(int x)
{
	return max(a[x], a[x + 1]);
}
inline int expand_e(int x, int d, int l)
{
	int y = x + d;
	if (y - l + 1 < 1)
		return x;
	if (y + l > n)
		return x;
	return y;
}

inline void solve_all_e(int st) // oushu
{
	int len = st / 2;
	int now = 0, l = 0, r;
	for (int i = 1; i <= n; ++i)
	{
		if (i - len < 0 || i + len > n)
			continue;
		l = (r = i, !l) ? i : l;
		relax(now, get_e(i));
	}

	for (int i = st; i > 1; i -= 2)
	{
		outcome[i] = now;
		l = expand_e(l, -1, i / 2 - 1);
		r = expand_e(r, +1, i / 2 - 1);
		relax(now, get_e(l));
		relax(now, get_e(r));
	}
}

int main()
{
	n = getint();
	for (int i = 1; i <= n; ++i)
		a[i] = getint();

	outcome[1] = *max_element(a + 1, a + n + 1);
	solve_all_o(n - (n % 2 ? 0 : 1));
	solve_all_e(n - (n % 2 ? 1 : 0));

	for (int i = n; i; --i)
		printf("%d ", outcome[i]);

	return 0;
}