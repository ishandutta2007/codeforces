#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int MaxN = 200005;
const int MaxLogN = 19;

int n;
int value[MaxN];

struct halfEdge
{
	int v, w;
	halfEdge *next;
};
halfEdge adj_pool[MaxN], *adj_tail = adj_pool;
halfEdge *adj[MaxN];

inline void addEdge(const int &u, const int &v, const int &w)
{
	adj_tail->v = v, adj_tail->w = w;
	adj_tail->next = adj[u], adj[u] = adj_tail++;
}

s64 dep[MaxN];
int anc[MaxN][MaxLogN];

int mark[MaxN];

void dfs(const int &u)
{
	for (int i = 0; anc[u][i]; ++i)
		anc[u][i + 1] = anc[anc[u][i]][i];

	for (halfEdge *e = adj[u]; e; e = e->next)
	{
		anc[e->v][0] = u;
		dep[e->v] = dep[u] + e->w;
		dfs(e->v);
	}
}

inline void go_up(int u)
{
	int sv = u;
	for (int i = 17; i >= 0; --i)
	{
		int v = anc[u][i];
		if (dep[sv] - dep[v] <= value[sv])
			u = v;
	}
	++mark[anc[sv][0]];
	--mark[anc[u][0]];
}

int dfs_count(const int &u)
{
	for (halfEdge *e = adj[u]; e; e = e->next)
		mark[u] += dfs_count(e->v);
	return mark[u];
}

int main()
{
	n = getint();
	for (int u = 1; u <= n; ++u)
		value[u] = getint();
	for (int u = 2; u <= n; ++u)
	{
		int v = getint(), w = getint();
		addEdge(v, u, w);
	}

	dfs(1);

	for (int u = 2; u <= n; ++u)
		go_up(u);

	dfs_count(1);
	for (int u = 1; u <= n; ++u)
		printf("%d ", mark[u]);

	return 0;
}