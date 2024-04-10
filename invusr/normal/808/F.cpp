#include <bits/stdc++.h>
using namespace std;

const int MaxN = 105;
const int MaxM = 100005;
const int MaxNV = MaxN + 2;
const int MaxNE = MaxN * MaxN;
const int INF = 0x3f3f3f3f;

int n, nK;
int val[MaxN], mag[MaxN], lev[MaxN];

int pri_n = 0, pri[MaxM];
bool book[MaxM * 2];

inline void init_sieve(int n)
{
	for (int i = 2; i <= n; ++i)
	{
		if (!book[i])
			pri[pri_n++] = i;

		for (int j = 0; j < pri_n; ++j)
		{
			int prod = i * pri[j];
			if (prod > n)
				break;
			book[prod] = true;
			if (i % pri[j] == 0)
				break;
		}
	}
}

struct halfEdge
{
	int v, w;
	halfEdge *next;
};
halfEdge adj_pool[MaxNE * 2], *adj_tail = adj_pool;
halfEdge *adj[MaxNV];

inline void addEdge(const int &u, const int &v, const int &w)
{
	adj_tail->v = v, adj_tail->w = w, adj_tail->next = adj[u], adj[u] = adj_tail++;
	adj_tail->v = u, adj_tail->w = 0, adj_tail->next = adj[v], adj[v] = adj_tail++;
}

inline halfEdge *oppo(const halfEdge *e)
{
	return adj_pool + ((e - adj_pool) ^ 1);
}

int vS, vT;

halfEdge *dfs_cur[MaxNV];
int dist[MaxNV];

int q_n, q[MaxNV];

inline bool calc_dist()
{
	for (int u = vS; u <= vT; ++u)
		dist[u] = -1, dfs_cur[u] = adj[u];

	dist[q[q_n = 1] = vS] = 0;
	for (int i = 1; i <= q_n; ++i)
	{
		int u = q[i];
		for (halfEdge *e = adj[u]; e; e = e->next)
			if (e->w && !~dist[e->v])
			{
				dist[e->v] = dist[u] + 1;
				if (e->v == vT)
					return true;
				q[++q_n] = e->v;
			}
	}
	return false;
}

int dfs(const int &u, const int &flow)
{
	if (u == vT || !flow)
		return flow;

	int res = 0;
	for (halfEdge *&e = dfs_cur[u]; e; e = e->next)
	{
		if (!e->w || dist[e->v] <= dist[u])
			continue;

		int delta = dfs(e->v, min(e->w, flow - res));
		if (delta > 0)
		{
			e->w -= delta, oppo(e)->w += delta;
			if ((res += delta) == flow)
				break;
		}
	}
	if (res < flow)
		dist[u] = -1;

	return res;
}

inline bool check(int limit)
{
	adj_tail = adj_pool;
	for (int i = 0; i <= n + 1; ++i)
		adj[i] = NULL;

	int idx = -1;
	for (int i = 1; i <= n; ++i)
	{
		if (mag[i] != 1 || lev[i] > limit)
			continue;
		if (!~idx || val[i] > val[idx])
			idx = i;
	}

	vS = 0, vT = n + 1;

	int sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (lev[i] > limit)
			continue;

		if (mag[i] & 1)
		{
			if (mag[i] == 1 && i != idx)
				continue;
			addEdge(i, vT, val[i]);
			sum += val[i];
		}
		else
		{
			addEdge(vS, i, val[i]);
			sum += val[i];
			for (int j = 1; j <= n; ++j)
			{
				if (~mag[j] & 1 || lev[j] > limit)
					continue;
				if (!book[mag[i] + mag[j]])
					addEdge(i, j, INF);
			}
		}
	}

	while (calc_dist())
		sum -= dfs(vS, INF);

	return sum >= nK;
}

int main()
{
	init_sieve(200000);

	cin >> n >> nK;
	for (int i = 1; i <= n; ++i)
		cin >> val[i] >> mag[i] >> lev[i];

	int l = 1, r = 200000;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (check(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}

	if (l <= 200000)
		cout << l << endl;
	else
		puts("-1");

	return 0;
}