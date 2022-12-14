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
template <class T>
inline void tense(T &a, const T &b)
{
	if (b < a)
		a = b;
}

const int MaxN = 105;
const int MaxNK = 105;
const int INF = 100000000;

int n, m, vS, vT;
int mat[MaxN][MaxN];

inline void floyd()
{
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				tense(mat[i][j], mat[i][k] + mat[k][j]);
}

int nK, fr[MaxNK], to[MaxNK];
bool must[MaxNK][MaxN];

int f[MaxN], g[MaxN];

int book_mark = 0;
int book[MaxN];

int dfs(const int &u, const int &to)
{
	if (u == to)
		return f[u];
	if (book[u] == book_mark)
		return g[u];
	book[u] = book_mark;

	g[u] = 0;
	for (int v = 1; v <= n; ++v)
	{
		if (mat[u][v] != 1)
			continue;
		if (mat[v][to] + 1 == mat[u][to])
			relax(g[u], dfs(v, to));
	}
	tense(g[u], f[u]);
	return g[u];
}

inline bool solve()
{
	bool over = true;
	for (int i = 0; i < nK; ++i)
	{
		++book_mark;
		for (int u = 1; u <= n; ++u)
			if (must[i][u])
			{
				int l = dfs(u, to[i]) + 1;
				if (l < f[u])
					f[u] = l, over = false;
			}
	}
	return over;
}

int main()
{
	cin >> n >> m >> vS >> vT;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			mat[i][j] = INF;
	for (int i = 1; i <= n; ++i)
		mat[i][i] = 0;
	for (int i = 1; i <= m; ++i)
	{
		int u = getint(), v = getint();
		mat[u][v] = 1;
	}

	floyd();

	cin >> nK;
	for (int i = 0; i < nK; ++i)
	{
		int sv = fr[i] = getint();
		int tv = to[i] = getint();
		if (mat[sv][tv] == INF)
			continue;

		for (int u = 1; u <= n; ++u)
		{
			if (mat[sv][tv] != mat[sv][u] + mat[u][tv])
				continue;

			must[i][u] = true;
			for (int v = 1; v <= n; ++v)
				if (mat[sv][u] == mat[sv][v] && mat[u][tv] == mat[v][tv])
					must[i][u] &= (u == v);
		}
	}

	for (int u = 1; u <= n; ++u)
		f[u] = INF;
	f[vT] = 0;

	while (!solve());

	cout << (f[vS] == INF ? -1 : f[vS]);
	cout << endl;

	return 0;
}