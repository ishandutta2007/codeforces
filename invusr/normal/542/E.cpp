#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
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

const int MaxN = 1000;
const int MaxM = 100000;

int n, m;
vector<int> adj[MaxN + 1];

bool vis[MaxN + 1];

int col[MaxN + 1];

int seq_n;
int seq[MaxN + 1];

bool dfs(int u, int now)
{
	vis[u] = true;
	col[u] = now;
	seq[++seq_n] = u;

	bool ok = true;
	for (int i = 0; i < adj[u].size() && ok; ++i)
	{
		int v = adj[u][i];
		if (!vis[v])
			ok &= dfs(v, !now);
		else
			ok &= now != col[v];
	}

	return ok;
}

int q_n, q[MaxN + 1];
int lev[MaxN + 1];

inline int bfs(int sv)
{
	for (int i = 1; i <= seq_n; ++i)
		lev[seq[i]] = -1;

	lev[sv] = 0, q[q_n = 1] = sv;
	for (int i = 1; i <= q_n; ++i)
	{
		int u = q[i];
		for (int v : adj[u])
			if (!~lev[v])
				lev[q[++q_n] = v] = lev[u] + 1;
	}

	int l = 0;
	for (int i = 1; i <= seq_n; ++i)
		l = max(l, lev[seq[i]]);
	return l;
}

inline int solve()
{
	int res = 0;
	for (int u = 1; u <= n; ++u)
		if (!vis[u])
		{
			seq_n = 0;
			if (!dfs(u, 0))
				return -1;


			int l = 0;
			for (int i = 1; i <= seq_n; ++i)
				l = max(l, bfs(seq[i]));
			res += l;
		}

	return res;
}

int main()
{
	n = getint(), m = getint();
	for (int i = 0; i < m; ++i)
	{
		int u = getint(), v = getint();
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	printf("%d\n", solve());

	return 0;
}