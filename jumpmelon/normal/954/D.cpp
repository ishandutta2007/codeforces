#include <bits/stdc++.h>

using namespace std;

namespace program
{
	const int MAXN = 1000;
	vector<int> G[MAXN + 10];
	int Dis1[MAXN + 10], Dis2[MAXN + 10], Q[MAXN + 10];

	void bfs(int n, int s, int *Dis)
	{
		int *head = Q, *tail = Q;
		memset(Dis + 1, -1, sizeof(int) * n);
		Dis[*tail++ = s] = 0;
		while(head < tail)
		{
			int u = *head++;
			for(int v : G[u])
				if(Dis[v] == -1)
					Dis[*tail++ = v] = Dis[u] + 1;
		}
	}

	void work()
	{
		int n, m, s, t, tot = 0;
		scanf("%d%d%d%d", &n, &m, &s, &t);
		while(m--)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		bfs(n, s, Dis1);
		bfs(n, t, Dis2);
		for(int u = 1; u <= n; u++)
		{
			for(int v = u + 1; v <= n; v++)
				if(min(Dis1[u] + Dis2[v] + 1, Dis2[u] + Dis1[v] + 1) >= Dis1[t])
					tot++;
			for(int v : G[u])
				if(u < v && min(Dis1[u] + Dis2[v] + 1, Dis2[u] + Dis1[v] + 1) >= Dis1[t])
					tot--;
		}
		printf("%d\n", tot);
	}
}

int main()
{
	program::work();
	return 0;
}