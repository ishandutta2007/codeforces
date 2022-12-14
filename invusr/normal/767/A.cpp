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

const int MaxN = 100005;

int n, a[MaxN], b[MaxN];
bool c[MaxN];

int main()
{
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], b[i] = a[i];

	sort(b + 1, b + n + 1);
	int m = unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; ++i)
		a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;

	int now = n + 1;
	c[now] = true;
	for (int i = 1; i <= n; ++i)
	{
		c[a[i]] = true;
		while (c[now - 1])
			cout << b[--now] << ' ';

		cout << endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}