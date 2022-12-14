#include <bits/stdc++.h>
using namespace std;

typedef long long s64;

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
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}

const int MaxN = 100005;
const int MaxM = 300005;
const int T = 3;

int n, m;
int cnt[T], cost[T][MaxM];

s64 f[MaxM];

int main()
{
	n = getint(), m = getint();
	for (int i = 1; i <= n; ++i)
	{
		int w = getint() - 1;
		int c = getint();
		cost[w][++cnt[w]] = c;
	}

	for (int i = 0; i < 3; ++i)
	{
		sort(cost[i] + 1, cost[i] + cnt[i] + 1, greater<int>());
		while (cnt[i] < m + 4)
			cost[i][++cnt[i]] = 0;
	}

	int v0 = 1, v1 = 1;
	for (int i = 2; i <= m; i += 2)
	{
		int c0 = cost[0][v0] + cost[0][v0 + 1];
		int c1 = cost[1][v1];
		f[i] = f[i - 2] + (c0 > c1 ? (v0 += 2, c0) : (++v1, c1));
	}

	f[1] = cost[0][v0 = 2, v1 = 1];
	for (int i = 3; i <= m; i += 2)
	{
		int c0 = cost[0][v0] + cost[0][v0 + 1];
		int c1 = cost[1][v1];
		f[i] = f[i - 2] + (c0 > c1 ? (v0 += 2, c0) : (++v1, c1));
	}

	s64 sum = 0, res = 0;
	for (int i = 0; i <= cnt[2] && i * 3 <= m; ++i)
	{
		sum += cost[2][i];
		relax(res, sum + f[m - i * 3]);
	}

	cout << res << endl;

	return 0;
}