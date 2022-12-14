#include <bits/stdc++.h>
using namespace std;

typedef long long s64;

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

const int MaxN = 5005;
const s64 INF = 0x3f3f3f3f3f3f3f3fll;

int n, s, t;
s64 x[MaxN], a[MaxN], b[MaxN];
s64 c[MaxN], d[MaxN];
s64 dist[MaxN][MaxN], outcome;

int next[MaxN];

int main()
{
	ios::sync_with_stdio(false);

	cin >> n >> s >> t;
	for (int i = 1; i <= n; ++i)
		cin >> x[i];
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	for (int i = 1; i <= n; ++i)
		cin >> d[i];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			if (i == j)
				continue;
			if (j < i)
				dist[i][j] = (s64)x[i] - x[j] + c[i] + b[j];
			else if (j > i)
				dist[i][j] = (s64)x[j] - x[i] + d[i] + a[j];
		}

	next[s] = t;
	outcome = dist[s][t];
	for (int i = 1; i <= n; ++i)
	{
		if (i == s || i == t)
			continue;

		s64 res = INF;
		int pos = -1;
		for (int u = s; u != t; u = next[u])
		{
			int v = next[u];
			s64 delta = dist[u][i] + dist[i][v] - dist[u][v];
			if (delta < res)
				res = delta, pos = u;
		}
		outcome += res;
		next[i] = next[pos];
		next[pos] = i;
	}

	cout << outcome;

	return 0;
}