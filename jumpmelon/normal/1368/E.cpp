#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	typedef pair<int, int> pa;

	const int MAXN = 200000, MAXM = MAXN << 1;
	vector<int> G[MAXN + 1];
	bool Vis[MAXN + 1];
	pa E[MAXM];

	void work()
	{
		int kase;
		scanf("%d", &kase);
		while (kase--)
		{
			int n, m;
			scanf("%d%d", &n, &m);
			memset(Vis + 1, 0, sizeof(bool[n]));
			for (int i = 1; i <= n; i++)
				G[i].clear();
			for (int i = 0; i < m; i++)
			{
				scanf("%d%d", &E[i].second, &E[i].first);
				G[E[i].second].push_back(E[i].first);
			}
			sort(E, E + m);
			for (int i = 0; i < m; i++)
				if (!Vis[E[i].first] && !Vis[E[i].second])
					for (int v : G[E[i].first])
						Vis[v] = 1;
			int k = 0;
			for (int i = 1; i <= n; i++)
				if (Vis[i])
					k++;
			printf("%d\n", k);
			for (int i = 1; i <= n; i++)
				if (Vis[i])
					printf("%d ", i);
			putchar('\n');
		}
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}