#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	typedef long long big;

	const int MAXN = 300000, P = 998244353;
	bool Vis[MAXN + 1];
	int tim, Col[MAXN + 1], Dfn[MAXN + 1], Fa[MAXN + 1], Dep[MAXN + 1];
	int F[MAXN + 1][2];
	struct edge { int u, v; } E[MAXN];
	vector<int> G[MAXN + 1], G1[MAXN + 1], V[MAXN + 1];

	inline bool cmp(int i, int j) { return Dfn[i] < Dfn[j]; }

	void DFS(int u, int fa)
	{
		Dfn[u] = ++tim;
		Fa[u] = fa;
		Dep[u] = Dep[fa] + 1;
		for (int v : G[u])
			if (v != fa)
				DFS(v, u);
	}

	void DFS2(int u, int fa)
	{
		F[u][Col[u] ? 1 : 0] = 1;
		for (int v : G1[u])
			if (v != fa)
			{
				DFS2(v, u);
				F[u][1] = int(((big)F[u][1] * (F[v][0] + F[v][1]) + (big)F[u][0] * F[v][1]) % P);
				F[u][0] = int((big)F[u][0] * (F[v][0] + F[v][1]) % P);
			}
	}

	void work()
	{
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &Col[i]);
			V[Col[i]].push_back(i);
		}
		for (int i = 1; i < n; i++)
		{
			scanf("%d%d", &E[i].u, &E[i].v);
			G[E[i].u].push_back(E[i].v);
			G[E[i].v].push_back(E[i].u);
		}
		DFS(1, 0);
		for (int i = 1; i <= k; i++)
		{
			sort(V[i].begin(), V[i].end(), cmp);
			for (int j = 0; j < (int)V[i].size(); j++)
			{
				int u = V[i][j], v = V[i][(j + 1) % V[i].size()];
				while (u != v)
				{
					if (Dep[u] < Dep[v])
						swap(u, v);
					u = Fa[u];
					if (Col[u] && Col[u] != i)
					{
						puts("0");
						return;
					}
					Col[u] = i;
				}
			}
		}
		for (int i = 1; i < n; i++)
		{
			int uu = Col[E[i].u] ? V[Col[E[i].u]][0] : E[i].u;
			int vv = Col[E[i].v] ? V[Col[E[i].v]][0] : E[i].v;
			if (uu != vv)
			{
				G1[uu].push_back(vv);
				G1[vv].push_back(uu);
			}
		}
		DFS2(V[1][0], 0);
		printf("%d\n", F[V[1][0]][1]);
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}