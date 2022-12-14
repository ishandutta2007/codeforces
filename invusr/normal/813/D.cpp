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

const int MaxN = 5005;
const int MaxM = 100005;
const int G = 5;
const int MaxNV = MaxN * 2 + 2;
const int MaxNE = MaxN * (3 + G * 2);
const int QN = 65535;
const int INF = 0x3f3f3f3f;

int n;
int a[MaxN];

struct halfEdge
{
	int v, w, c;
	halfEdge *next;
};
halfEdge adj_pool[MaxNE * 2], *adj_tail = adj_pool;
halfEdge *adj[MaxNV];

inline void addEdge(const int &u, const int &v, const int &w, const int &c)
{
	adj_tail->v = v, adj_tail->w = w, adj_tail->c = c;
	adj_tail->next = adj[u], adj[u] = adj_tail++;
	adj_tail->v = u, adj_tail->w = 0, adj_tail->c = -c;
	adj_tail->next = adj[v], adj[v] = adj_tail++;
}
inline halfEdge *oppo(const halfEdge *e)
{
	return adj_pool + ((e - adj_pool) ^ 1);
}

int vS, vT;

halfEdge *dfs_cur[MaxNV];
int dist[MaxNV];
bool book[MaxNV];

int q_l, q_r;
int q[QN + 1];

bool vis[MaxNV];

int outcome = 0;

inline bool calc_dist()
{
	for (int i = vS; i <= vT; ++i)
		dfs_cur[i] = adj[i], dist[i] = INF, vis[i] = true;
	dist[vS] = 0;

	q_l = 0, q_r = 0;
	q[++q_r] = vS;
	while (q_l != q_r)
	{
		int u = q[++q_l &= QN];
		book[u] = false;

		for (halfEdge *e = adj[u]; e; e = e->next)
		{
			int l = dist[u] + e->c;
			if (l < dist[e->v] && e->w)
			{
				dist[e->v] = l;
				if (!book[e->v])
				{
					book[e->v] = true;
					q[++q_r &= QN] = e->v;
				}
			}
		}
	}

	return dist[vT] < INF;
}

int dfs(int u, int flow)
{
	if (u == vT || !flow)
	{
		outcome -= flow * dist[u];
		return flow;
	}

	vis[u] = false;
	int res = 0;
	for (halfEdge *&e = dfs_cur[u]; e; e = e->next)
	{
		if (!e->w || !vis[e->v])
			continue;
		if (dist[e->v] != dist[u] + e->c)
			continue;

		int delta = dfs(e->v, min(e->w, flow - res));
		if (delta > 0)
		{
			e->w -= delta, oppo(e)->w += delta;
			if ((res += delta) == flow)
				break;
		}
	}

	return res;
}

template <class T>
inline void link_previous(int x, T validator)
{
	int now = 0;
	for (int i = x - 1; i; --i)
		if (validator(a[i], a[x]))
		{
			addEdge(i + n, x, 1, 0);
			if (++now == G)
				break;
		}
}

inline bool validator1(int a, int b)
{
	return abs(a - b) == 1;
}
inline bool validator2(int a, int b)
{
	return a % 7 == b % 7;
}

int main()
{
	n = getint();
	for (int i = 1; i <= n; ++i)
		a[i] = getint();

	vS = 0, vT = n + n + 1;
	for (int i = 1; i <= n; ++i)
	{
		int u = i, v = i + n;
		addEdge(vS, u, 1, 0);
		addEdge(v, vT, 1, 0);
		addEdge(u, v, 1, -1);
		link_previous(i, validator1);
		link_previous(i, validator2);
	}

	addEdge(vT, vT + 1, 2, 0), ++vT;

	while (calc_dist())
		while (dfs(vS, INF));

	cout << outcome << endl;

	return 0;
}