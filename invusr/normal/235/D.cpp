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

const int MaxN = 3005;

int n;
int cir_l = 0;

struct halfEdge
{
	int v, w;
	halfEdge *next;
};
halfEdge adj_pool[MaxN * 2], *adj_tail = adj_pool;
halfEdge *adj[MaxN];

inline void addEdge(const int &u, const int &v)
{
	adj_tail->v = v, adj_tail->w = 0;
	adj_tail->next = adj[u], adj[u] = adj_tail++;
}

inline halfEdge *oppo(const halfEdge *e)
{
	return adj_pool + ((e - adj_pool) ^ 1);
}

inline void set_circle(halfEdge *e, const int &w)
{
	e->w = oppo(e)->w = w;
}

int fa[MaxN];
int dfs_clock = 0, dfn[MaxN];

int sta_n = 0;
halfEdge *sta[MaxN];

void dfs(const int &u)
{
	dfn[u] = ++dfs_clock;

	for (halfEdge *e = adj[u]; e; e = e->next)
	{
		if (e->v == fa[u])
			continue;

		if (!dfn[e->v])
		{
			sta[++sta_n] = e;
			fa[e->v] = u, dfs(e->v);
			sta[sta_n--] = NULL;
		}
		else if (dfn[e->v] < dfn[u])
		{
			++cir_l;
			int now = u;
			int cur = sta_n;
			while (now != e->v)
			{
				set_circle(sta[cur--], 1);
				now = fa[now];
				++cir_l;
			}
			set_circle(e, -1);
		}
	}
}

int sum[MaxN];
int cir[MaxN];

int q_n = 0, q[MaxN];

double res = 0.0;

inline void bfs(const int &sv)
{
	for (int u = 1; u <= n; ++u)
		sum[u] = cir[u] = -1;
	sum[sv] = cir[sv] = 0;

	q[q_n = 1] = sv;
	for (int i = 1; i <= q_n; ++i)
	{
		int u = q[i];

		if (!cir[u])
			res += 1.0 / (sum[u] + 1.0);
		else
		{
			int cir_vl = cir[u] - 1;
			int cir_vr = cir_l - cir[u] - 1;
			int l = sum[u] - cir[u] + 2;
			res += 1.0 / (l + cir_vl);
			res += 1.0 / (l + cir_vr);
			res -= 1.0 / (l + cir_vl + cir_vr);
		}

		for (halfEdge *e = adj[u]; e; e = e->next)
		{
			if (e->w == -1 || sum[e->v] != -1)
				continue;
			sum[e->v] = sum[u] + 1;
			cir[e->v] = cir[u] + e->w;
			q[++q_n] = e->v;
		}
	}
}

int main()
{
	n = getint();
	for (int i = 1; i <= n; ++i)
	{
		int u = getint() + 1, v = getint() + 1;
		addEdge(u, v);
		addEdge(v, u);
	}

	dfs(1);

	for (int u = 1; u <= n; ++u)
		bfs(u);

	printf("%.16f\n", res);

	return 0;
}