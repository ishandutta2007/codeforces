#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
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

const int MaxN = 300005;
const int MaxM = 300005;
const int P1 = 27, M1 = 998244353;
const int P2 = 31, M2 = 1000000007;

int n, m;
int eu[MaxM], ev[MaxM];

vector<int> adj[MaxN];

struct hash_t
{
	int u, v;
	hash_t() {}
	hash_t(const int &_u, const int &_v)
		: u(_u), v(_v) {}

	friend inline hash_t operator+(const hash_t &lhs, const int &rhs)
	{
		hash_t res;
		res.u = ((s64)lhs.u * P1 + rhs) % M1;
		res.v = ((s64)lhs.v * P2 + rhs) % M2;
		return res;
	}

	friend inline bool operator<(const hash_t &lhs, const hash_t &rhs)
	{
		if (lhs.u != rhs.u)
			return lhs.u < rhs.u;
		return lhs.v < rhs.v;
	}
	friend inline bool operator==(const hash_t &lhs, const hash_t &rhs)
	{
		return lhs.u == rhs.u && lhs.v == rhs.v;
	}
};
hash_t vh[MaxN];

int idx[MaxN];
int nG = 0, group[MaxN];

inline bool comparator(int u, int v)
{
	return vh[u] < vh[v];
}

struct edge
{
	int u, v;
	edge() {}
	edge(const int &_u, const int &_v)
		: u(_u), v(_v) {}

	friend inline bool operator<(const edge &lhs, const edge &rhs)
	{
		if (lhs.u != rhs.u)
			return lhs.u < rhs.u;
		return lhs.v < rhs.v;
	}
	friend inline bool operator==(const edge &lhs, const edge &rhs)
	{
		return lhs.u == rhs.u && lhs.v == rhs.v;
	}
};

int nE = 0;
edge allE[MaxM];

int deg[MaxN];
int lab[MaxN];

int q_n = 0, q[MaxN];

inline void bfs(const int &sv)
{
	lab[q[q_n++] = sv] = 1;
	for (int i = 0; i < q_n; ++i)
	{
		int u = q[i];
		for (int v : adj[u])
			if (!lab[v])
			{
				lab[v] = lab[u] + 1;
				q[q_n++] = v;
			}
	}
}

int main()
{
	n = getint(), m = getint();
	for (int u = 1; u <= n; ++u)
		adj[u].push_back(u);
	for (int i = 0; i < m; ++i)
	{
		eu[i] = getint(), ev[i] = getint();
		adj[eu[i]].push_back(ev[i]);
		adj[ev[i]].push_back(eu[i]);
	}

	for (int u = 1; u <= n; ++u)
	{
		sort(adj[u].begin(), adj[u].end());

		vh[u] = hash_t(0, 0);
		for (int v : adj[u])
			vh[u] = vh[u] + v;
	}

	for (int u = 1; u <= n; ++u)
		idx[u] = u;
	sort(idx + 1, idx + n + 1, comparator);

	group[idx[1]] = 1;
	for (int i = 2; i <= n; ++i)
	{
		int u = idx[i], v = idx[i - 1];
		group[u] = group[v] + !(vh[u] == vh[v]);
	}
	nG = group[idx[n]];

	for (int u = 1; u <= nG; ++u)
		adj[u].clear();
	for (int i = 0; i < m; ++i)
	{
		int u = group[eu[i]];
		int v = group[ev[i]];
		if (u > v)
			swap(u, v);
		if (u < v)
			allE[nE++] = edge(u, v);
	}

	sort(allE, allE + nE);
	nE = unique(allE, allE + nE) - allE;
	for (int i = 0; i < nE; ++i)
	{
		int u = allE[i].u;
		int v = allE[i].v;
		adj[u].push_back(v), ++deg[v];
		adj[v].push_back(u), ++deg[u];
	}

	int cnt = 0;
	for (int u = 1; u <= nG; ++u)
	{
		if (deg[u] == 1)
			++cnt;
		else if (deg[u] > 2)
		{
			puts("NO");
			return 0;
		}
	}

	if (nG > 1 && cnt < 2)
		puts("NO");
	else
	{
		int sv = 0;
		for (int u = 1; !sv; ++u)
			if (deg[u] <= 1)
				sv = u;
		bfs(sv);

		puts("YES");
		for (int u = 1; u <= n; ++u)
			printf("%d ", lab[group[u]]);
	}

	return 0;
}