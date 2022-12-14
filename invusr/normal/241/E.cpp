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

const int MaxN = 1005;
const int MaxM = 5005;
const int QN = 65535;
const int INF = 100000000;

int n, m;
int eu[MaxM], ev[MaxM];

struct halfEdge
{
	int v, w;
	halfEdge *next;
};
halfEdge adj_pool[MaxM * 2], *adj_tail = adj_pool;
halfEdge *adj[MaxN];

inline void addEdge(const int &u, const int &v, const int &w)
{
	adj_tail->v = v, adj_tail->w = w;
	adj_tail->next = adj[u], adj[u] = adj_tail++;
}

bool vis[MaxN], del[MaxN];

void dfs(const int &u)
{
	if (vis[u])
		return;
	vis[u] = true;
	for (halfEdge *e = adj[u]; e; e = e->next)
		if (e->w == 2)
		{
			dfs(e->v);
			del[u] &= del[e->v];
		}
}

int q_l = 0, q_r = 0;
int q[QN + 1];

int dist[MaxN];
int occur[MaxN];

inline bool solve()
{
	for (int u = 1; u <= n; ++u)
		dist[u] = INF, vis[u] = false;
	dist[1] = 0;

	occur[q[++q_r] = 1] = 1;
	while (q_l != q_r)
	{
		int u = q[++q_l &= QN];

		for (halfEdge *e = adj[u]; e; e = e->next)
		{
			int l = dist[u] + e->w;
			if (!del[e->v] && l < dist[e->v])
			{
				dist[e->v] = l;
				if (!vis[e->v])
				{
					vis[e->v] = true;
					q[++q_r &= QN] = e->v;

					if (++occur[e->v] > n)
						return false;
				}
			}
		}
		vis[u] = false;
	}

	return true;
}

int main()
{
	n = getint(), m = getint();
	for (int i = 0; i < m; ++i)
	{
		int u = eu[i] = getint();
		int v = ev[i] = getint();
		addEdge(u, v, 2);
		addEdge(v, u, -1);
	}

	fill(vis + 1, vis + n + 1, false);
	fill(del + 1, del + n + 1, true);
	vis[n] = true, del[n] = false, dfs(1);

	if (!solve())
		puts("No");
	else
	{
		puts("Yes");
		for (int i = 0; i < m; ++i)
		{
			int u = eu[i], v = ev[i];
			if (!del[u] && !del[v] && dist[v] - dist[u] == 2)
				puts("2");
			else
				puts("1");
		}
	}

	return 0;
}