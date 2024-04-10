#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100005;
const int MaxM = 100005;

int n, m, k;
bool book[MaxN];

struct halfEdge
{
	int v, w;
	halfEdge *next;
};
halfEdge adj_pool[MaxM * 2], *adj_tail = adj_pool;
halfEdge *adj[MaxN];

inline void addEdge(int u, int v, int w)
{
	adj_tail->v = v, adj_tail->w = w, adj_tail->next = adj[u], adj[u] = adj_tail++;
	adj_tail->v = u, adj_tail->w = w, adj_tail->next = adj[v], adj[v] = adj_tail++;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1, u, v, w; i <= m; ++i)
	{
		scanf("%d%d%d", &u, &v, &w);
		addEdge(u, v, w);
	}

	bool found = false;
	int res = 1111111111;
	for (int i = 1, u; i <= k; ++i)
	{
		scanf("%d", &u);
		book[u] = true;
	}
	for (int u = 1; u <= n; ++u)
		if (book[u])
		{
			for (halfEdge *e = adj[u]; e; e = e->next)
				if (!book[e->v])
				{
					found = true;
					res = min(res, e->w);
				}
		}

	if (!found)
		puts("-1");
	else
		cout << res;

	return 0;
}