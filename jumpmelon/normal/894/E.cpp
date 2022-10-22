#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	typedef long long big;

	const int MAXN = 1000000, MAXW = 100000000, MAXC = 20000;
	int *top, tim, scc, St[MAXN + 1], Dfn[MAXN + 1], Low[MAXN + 1], Bel[MAXN + 1], V[MAXC + 1];
	big NW[MAXN + 1], F[MAXN + 1], SV[MAXC + 1];
	struct edge { int v, w; };
	vector<edge> G[MAXN + 1], NG[MAXN + 1];

	void Tarjan(int u)
	{
		Dfn[u] = Low[u] = ++tim;
		*++top = u;
		for (auto &&p: G[u])
			if (!Dfn[p.v])
			{
				Tarjan(p.v);
				Low[u] = min(Low[u], Low[p.v]);
			}
			else if (!Bel[p.v])
				Low[u] = min(Low[u], Dfn[p.v]);
		if (Dfn[u] == Low[u])
		{
			scc++;
			do
				Bel[*top] = scc;
			while (*top-- != u);
		}
	}

	inline big calc(int w)
	{
		int p = upper_bound(V + 1, V + MAXC + 1, w) - V - 1;
		return (big)w * p - SV[p];
	}

	big f(int u)
	{
		big &ans = F[u];
		if (ans == -1)
		{
			ans = NW[u];
			for (auto &&p : NG[u])
				ans = max(ans, NW[u] + f(p.v) + p.w);
		}
		return ans;
	}

	void work()
	{
		int n, m, s;
		scanf("%d%d", &n, &m);
		while (m--)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			G[u].push_back({v, w});
		}
		scanf("%d", &s);
		top = St;
		for (int i = 1; i <= MAXC; i++)
		{
			V[i] = i * (i - 1) / 2;
			SV[i] = SV[i - 1] + V[i];
		}
		for (int i = 1; i <= n; i++)
			if (!Dfn[i])
				Tarjan(i);
		for (int u = 1; u <= n; u++)
			for (auto &&p : G[u])
				if (Bel[u] == Bel[p.v])
					NW[Bel[u]] += calc(p.w);
				else
					NG[Bel[u]].push_back({Bel[p.v], p.w});
		memset(F + 1, -1, sizeof(big[n]));
		printf("%lld\n", f(Bel[s]));
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}