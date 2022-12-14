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

const int MaxN = 1005;

int n, a[MaxN], b[MaxN];
int li_n = 0, li[5];

bool book[MaxN];

inline void check()
{
	for (int i = 1; i <= n; ++i)
		book[i] = false;
	for (int i = 1; i <= n; ++i)
	{
		if (book[a[i]])
			return;
		book[a[i]] = true;
	}

	for (int i = 1; i <= n; ++i)
		cout << a[i] << ' ';
	exit(0);
}

int o[MaxN];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];

	for (int i = 1; i <= n; ++i)
		if (a[i] != b[i])
			li[li_n++] = i;

	if (li_n == 2)
	{
		int u = li[0], v = li[1];
		swap(a[u], b[u]), check(), swap(a[u], b[u]);
		swap(a[v], b[v]), check();
	}
	else if (li_n == 0)
	{
		for (int i = 1; i <= n; ++i)
			++o[a[i]];

		int x = 0, y = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (!o[i])
				x = i;
			else if (o[i] == 2)
				y = i;
		}

		int p = 0;
		for (int i = 1; i <= n; ++i)
			if (a[i] == y)
				p = i;

		a[p] = x;
		for (int i = 1; i <= n; ++i)
			cout << a[i] << ' ';
	}
	else if (li_n == 1)
	{
		for (int i = 1; i <= n; ++i)
			book[a[i]] = book[b[i]] = true;

		int v = 0;
		for (int i = 1; i <= n; ++i)
			if (!book[i])
				v = i;
		a[li[0]] = v;

		for (int i = 1; i <= n; ++i)
			cout << a[i] << ' ';
	}

	return 0;
}