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

const int MaxN = 200005;
const int MaxLogN = 20;
const int M = 1000000007;

int n, a[MaxN];

struct halfEdge
{
	int v;
	halfEdge *next;
};
halfEdge adj_pool[MaxN * 2], *adj_tail = adj_pool;
halfEdge *adj[MaxN];

inline void addEdge(const int &u, const int &v)
{
	adj_tail->v = v, adj_tail->next = adj[u];
	adj[u] = adj_tail++;
}

int pri_n = 0, pri[MaxN / 8];
bool book[MaxN];

int phi[MaxN], mu[MaxN];

int inv[MaxN];

inline void init_sieve()
{
	inv[1] = 1;
	for (int i = 2; i <= n; ++i)
		inv[i] = (s64)(M - M / i) * inv[M % i] % M;

	phi[1] = mu[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (!book[i])
		{
			pri[pri_n++] = i;
			phi[i] = i - 1, mu[i] = -1;
		}

		for (int j = 0; j < pri_n; ++j)
		{
			int p = pri[j], d = i * p;
			if (d > n)
				break;
			book[d] = true;

			phi[d] = phi[i];
			if (i % p)
				phi[d] *= p - 1, mu[d] = -mu[i];
			else
			{
				phi[d] *= p;
				break;
			}
		}
	}
}

int seq_n = 0;
int dfn[MaxN], seq[MaxLogN][MaxN * 2];
int dep[MaxN];

int log_tab[MaxN * 2];

vector<int> divs[MaxN];
vector<int> vertex[MaxN];

inline bool comparator(int u, int v)
{
	return dep[u] < dep[v];
}

void dfs(const int &u, const int &pred)
{
	seq[0][++seq_n] = u;
	dfn[u] = seq_n;

	for (int d : divs[a[u]])
		vertex[d].emplace_back(u);

	for (halfEdge *e = adj[u]; e; e = e->next)
		if (e->v != pred)
		{
			dep[e->v] = dep[u] + 1;
			dfs(e->v, u);
			seq[0][++seq_n] = u;
		}
}

int f[MaxN];

inline int get_lca(int u, int v)
{
	if ((u = dfn[u]) > (v = dfn[v]))
		swap(u, v);
	int l = log_tab[v - u + 1];
	return min(seq[l][u], seq[l][v - (1 << l) + 1], comparator);
}

int sta_n, sta[MaxN];

inline void pop_stack()
{
	addEdge(sta[sta_n - 1], sta[sta_n]);
	--sta_n;
}

inline void build(vector<int> &vertex)
{
	adj[1] = NULL, adj_tail = adj_pool;
	for (int u : vertex)
		adj[u] = NULL;

	sta[sta_n = 1] = 1;

	int l = vertex.size();
	for (int i = vertex[0] == 1; i < l; ++i)
	{
		int u = vertex[i];
		int lca = get_lca(u, sta[sta_n]);

		while (sta_n > 1 && dep[sta[sta_n - 1]] >= dep[lca])
			pop_stack();

		if (sta[sta_n] != lca)
		{
			adj[lca] = NULL;
			addEdge(lca, sta[sta_n--]);
			sta[++sta_n] = lca;
			vertex.emplace_back(lca);
		}

		sta[++sta_n] = u;
	}

	while (sta_n > 1)
		pop_stack();
}

int cur[MaxN];

int dfs2(const int &u, const int &d)
{
	int ret = 0, sum = 0;
	cur[u] = a[u] % d ? 0 : phi[a[u]];
	for (halfEdge *e = adj[u]; e; e = e->next)
	{
		ret = (ret + dfs2(e->v, d)) % M;
		sum = (sum + (s64)cur[u] * cur[e->v]) % M;
		cur[u] = (cur[u] + cur[e->v]) % M;
	}

	sum = (s64)sum * (M - 4) % M * dep[u] % M;
	sum = (sum + ret) % M;
	if (a[u] % d == 0)
		sum = (sum + (s64)phi[a[u]] * phi[a[u]] % M * (M - 2) % M * dep[u]) % M;
	return sum;
}

int main()
{
	n = getint();
	for (int i = 1; i <= n; ++i)
		a[i] = getint();
	for (int i = 1; i < n; ++i)
	{
		int u = getint(), v = getint();
		addEdge(u, v);
		addEdge(v, u);
	}

	init_sieve();

	for (int d = 1; d <= n; ++d)
		for (int i = d; i <= n; i += d)
			divs[i].emplace_back(d);

	dfs(1, 0);

	for (int l = 1; 1 << l <= seq_n; ++l)
	{
		int *s = seq[l], *t = seq[l - 1];
		int k = 1 << l;
		int d = 1 << l - 1;
		for (int i = 1; i + k - 1 <= seq_n; ++i)
			s[i] = min(t[i], t[i + d], comparator);
	}

	log_tab[1] = 0;
	for (int i = 2; i <= seq_n; ++i)
		log_tab[i] = log_tab[i >> 1] + 1;

	int res = 0;
	for (int d = n; d >= 1; --d)
	{
		int sum = 0, now = 0;
		for (int u : vertex[d])
			sum = (sum + phi[a[u]]) % M;
		for (int u : vertex[d])
			now = (now + phi[a[u]] * (s64)dep[u]) % M;
		now = (s64)now * sum % M;
		now = (s64)now * 2 % M;

		build(vertex[d]);
		now = (now + dfs2(1, d)) % M;

		f[d] = now;

		int l = n / d;
		sum = 0;
		for (int i = 1; i <= l; ++i)
			sum = (sum + (s64)mu[i] * f[i * d]) % M;
		sum = (s64)sum * d % M;
		sum = (s64)sum * inv[phi[d]] % M;
		res = (res + sum) % M;
	}

	res = (s64)res * inv[n] % M;
	res = (s64)res * inv[n - 1] % M;
	printf("%d\n", (res + M) % M);

	return 0;
}