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
const r32 PI = acos(-1.0);
const s64 INF = 0x3f3f3f3f3f3f3fll;

int n, x[MaxN], y[MaxN], r[MaxN];
s64 e[MaxN];
vector<int> adj[MaxN], rt;

inline s64 dist(int i, int j)
{
	int u = x[i] - x[j], v = y[i] - y[j];
	return (s64)u * u + (s64)v * v;
}

inline s64 get(int s, s64 w)
{
	return s ? -w : w;
}

s64 sum = 0;

s64 f[MaxN][2][2][2];

void dfs(int u)
{
	for (int b = 0; b < 2; ++b)
		for (int c = 0; c < 2; ++c)
		{
			f[u][0][b][c] = get(b, e[u]);
			f[u][1][b][c] = get(c, e[u]);
		}

	for (int v : adj[u])
	{
		dfs(v);

		for (int b = 0; b < 2; ++b)
			for (int c = 0; c < 2; ++c)
			{
				f[u][0][b][c] += max(f[v][0][!b][c], f[v][1][!b][c]);
				f[u][1][b][c] += max(f[v][1][b][!c], f[v][0][b][!c]);
			}
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i] >> r[i];

	for (int i = 1; i <= n; ++i)
	{
		e[i] = (s64)r[i] * r[i];

		int k = 0;
		for (int j = 1; j <= n; ++j)
		{
			if (i == j)
				continue;
			s64 d = dist(i, j);
			if (d <= (s64)r[j] * r[j] && r[j] > r[i])
			{
				if (!k)
					k = j;
				else if (r[j] < r[k])
					k = j;
			}
		}

		if (!k)
			rt.push_back(i);
		else
			adj[k].push_back(i);
	}

	for (int i = 1; i <= n; ++i)
		for (int a = 0; a < 2; ++a)
			for (int b = 0; b < 2; ++b)
				for (int c = 0; c < 2; ++c)
					f[i][a][b][c] = -INF;

	for (int i : rt)
	{
		dfs(i);
		sum += f[i][0][0][0];
	}

	r32 res = PI * sum;
	printf("%.8f\n", res);

	return 0;
}