#include <bits/stdc++.h>
using namespace std;

namespace TYC
{
	typedef long long ll;
	typedef pair<int, int> pii;
	const int N = 2e5 + 5;

	int n, m, tim, tot, top, val[N], Head[N], dfn[N], low[N], bel[N], sta[N], vis[N];
	ll V[N], dp[N][2];
	struct edge { int to, next; } E[N << 1];
	vector<int> T[N], node[N];

	inline void add(const int u, const int v)
	{
		static int ecnt = 1;
		E[++ecnt] = (edge){v, Head[u]};
		Head[u] = ecnt;
	}

	void Tarjan(const int u, const int pre)
	{
		sta[++top] = u;
		dfn[u] = low[u] = ++tim;
		for (int i = Head[u]; i; i = E[i].next)
			if ((i ^ 1) != pre)
			{
				int v = E[i].to;
				if (!dfn[v])
					Tarjan(v, i), low[u] = min(low[u], low[v]);
				else if (!bel[v]) 
					low[u] = min(low[u], dfn[v]);
			}
		if (dfn[u] <= low[u])
		{
			++tot;
			int x;
			do
			{
				bel[x = sta[top--]] = tot;
				V[tot] += val[x];
				node[tot].push_back(x);
			}
			while (x != u);
		}

	}

	void rebuild()
	{
		for (int x = 1; x <= tot; x++)
			for (int u : node[x])
				for (int i = Head[u]; i; i = E[i].next)
				{
					int v = E[i].to;
					if (x != bel[v] && vis[bel[v]] != x)
					{
						T[x].push_back(bel[v]);
						vis[bel[v]] = x;
					}
				}
	}

	bool dfs(const int u, const int f)
	{
		bool flag = node[u].size() == 1;
		for (int v : T[u])
			if (v != f)
			{
				flag &= dfs(v, u);
				dp[u][1] = max(dp[u][1], max(dp[u][0] + dp[v][1], dp[u][1] + dp[v][0])); 
				dp[u][0] += dp[v][0];
			}
		dp[u][1] += V[u];
		if (!flag)
			dp[u][0] += V[u];
		return flag;
	}

	void work()
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%d", &val[i]);
		for (int i = 1, u, v; i <= m; i++)
		{
			scanf("%d%d", &u, &v);
			add(u, v), add(v, u);
		}
		for (int i = 1; i <= n; i++)
			if (!dfn[i])
				Tarjan(i, 0);
		rebuild();
		int rot;
		scanf("%d", &rot);
		dfs(rot = bel[rot], 0);
		printf("%lld\n", max(dp[rot][0], dp[rot][1]));
	}
}

int main()
{
	TYC::work();
	return 0;
}