#include <bits/stdc++.h>

using namespace std;

namespace program
{
	typedef long long big;
	typedef pair<big, int> pa;
	
	const int MAXN = 10000, MAXM = 10000, MAXK = 100;
	struct edge { int v, w, next; } E[MAXM + MAXK + 10];
	int n, m, k, s1, s2, t, ec, Head[MAXN + 10];
	int U[MAXK + 10], L[MAXK + 10];
	big Dis1[MAXN + 10], Dis2[MAXN + 10];
	
	inline void add_edge(int u, int v, int w)
	{
		E[++ec] = (edge){v, w, Head[u]};
		Head[u] = ec;
	}
	
	void Dijkstra(int s, big *Dis)
	{
		priority_queue<pa, vector<pa>, greater<pa> > Q;
		memset(Dis + 1, 0x3f, sizeof(big) * n);
		Q.push(pa(Dis[s] = 0, s));
		while(!Q.empty())
		{
			int u = Q.top().second;
			big d = Q.top().first;
			Q.pop();
			if(d == Dis[u])
				for(int p = Head[u]; p; p = E[p].next)
					if(d + E[p].w < Dis[E[p].v])
						Q.push(pa(Dis[E[p].v] = d + E[p].w, E[p].v));
		}
	}
	
	template <typename T>
	bool check(T cmp)
	{
		bool flag = 1;
		while(flag)
		{
			flag = 0;
			Dijkstra(s1, Dis1);
			Dijkstra(s2, Dis2);
			if(cmp(Dis1[t], Dis2[t]))
				return 1;
			for(int i = 1; i <= k; i++)
				if(cmp(Dis1[U[i]], Dis2[U[i]]) && E[m + i].w != L[i])
				{
					E[m + i].w = L[i];
					flag = 1;
				}
		}
		return 0;
	}
	
	void work()
	{
		scanf("%d%d%d%d%d%d", &n, &m, &k, &s1, &s2, &t);
		for(int i = 1; i <= m; i++)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			add_edge(u, v, w);
		}
		for(int i = 1; i <= k; i++)
		{
			int v, w;
			scanf("%d%d%d%d", &U[i], &v, &L[i], &w);
			add_edge(U[i], v, w);
		}
		if(check(less<big>()))
			puts("WIN");
		else if(check(less_equal<big>()))
			puts("DRAW");
		else
		{
			puts("LOSE");
			return;
		}
		for(int i = 1; i <= k; i++)
			printf("%d ", E[m + i].w);
		putchar('\n');
	}
}

int main()
{
	program::work();
	return 0;
}