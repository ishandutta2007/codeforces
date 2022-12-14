#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1001;
const int MaxM = 1001;
const int MaxQ = 100005;

int n, m, q;

int outcome = 0;
bool shelf[MaxN][MaxN];

int type[MaxQ], qL[MaxQ], qR[MaxQ];
int res[MaxQ];

inline bool add(int i, int j)
{
	if (!shelf[i][j])
	{
		shelf[i][j] = true;
		++outcome;
		return true;
	}
	return false;
}
inline bool remove(int i, int j)
{
	if (shelf[i][j])
	{
		shelf[i][j] = false;
		--outcome;
		return true;
	}
	return false;
}

inline void invert(int i)
{
	for (int j = 1; j <= m; ++j)
	{
		if (shelf[i][j])
			remove(i, j);
		else
			add(i, j);
	}
}

struct halfEdge
{
	int v;
	halfEdge *next;
};
halfEdge adj_pool[MaxQ], *adj_tail = adj_pool;
halfEdge *adj[MaxQ];

inline void addEdge(int u, int v)
{
	adj_tail->v = v, adj_tail->next = adj[u];
	adj[u] = adj_tail++;
}

void dfs(int u)
{
	bool ok;
	if (u > 0)
	{
		if (type[u] == 1)
			ok = add(qL[u], qR[u]);
		else if (type[u] == 2)
			ok = remove(qL[u], qR[u]);
		else if (type[u] == 3)
			invert(qL[u]);
	}

	res[u] = outcome;

	for (halfEdge *e = adj[u]; e; e = e->next)
		dfs(e->v);

	if (u > 0)
	{
		if (type[u] == 1)
		{
			if (ok)
				remove(qL[u], qR[u]);
		}
		else if (type[u] == 2)
		{
			if (ok)
				add(qL[u], qR[u]);
		}
		else if (type[u] == 3)
			invert(qL[u]);
	}
}

int main()
{
	cin >> n >> m >> q;
	for (int i = 1; i <= q; ++i)
	{
		scanf("%d%d", &type[i], &qL[i]);
		if (type[i] == 1)
		{
			scanf("%d", &qR[i]);
			addEdge(i - 1, i);
		}
		else if (type[i] == 2)
		{
			scanf("%d", &qR[i]);
			addEdge(i - 1, i);
		}
		else if (type[i] == 3)
			addEdge(i - 1, i);
		else
			addEdge(qL[i], i);
	}

	dfs(0);

	for (int i = 1; i <= q; ++i)
		printf("%d\n", res[i]);

	return 0;
}