#include <bits/stdc++.h>
using namespace std;

using s64 = long long;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int MaxN = 200000;
const int NLet = 20;

int n;
char s[MaxN + 2];

int bit[1 << NLet];

vector<int> adj[MaxN + 1];

int mask[MaxN + 1];

bool deleted[MaxN + 1];

int q_n, q[MaxN + 1];
int weight[MaxN + 1], heavy[MaxN + 1];
int fa[MaxN + 1];

inline void bfs(const int &sv)
{
	q[q_n = 1] = sv, fa[sv] = 0;
	for (int i = 1; i <= q_n; ++i)
	{
		int u = q[i];
		for (int v : adj[u])
			if (!deleted[v] && v != fa[u])
			{
				q[++q_n] = v;
				fa[v] = u;
			}
	}

	for (int i = 0; i <= q_n; ++i)
		weight[q[i]] = 1;
	for (int i = q_n; i >= 1; --i)
		weight[fa[q[i]]] += weight[q[i]];
}

inline int centroid(const int &sv)
{
	bfs(sv);

	int vC = -1, wC = q_n + 1;
	for (int i = 1; i <= q_n; ++i)
		heavy[q[i]] = 1;
	for (int i = q_n; i >= 1; --i)
	{
		int u = q[i];
		int v = fa[q[i]];
		heavy[v] = max(heavy[v], weight[u]);

		int vW = max(heavy[u], q_n - weight[u]);
		if (vW < wC)
			wC = vW, vC = u;
	}

	return vC;
}

int dfn_l[MaxN + 1];
int dfn_r[MaxN + 1];
int seq[MaxN + 1];

inline void get_dfs_sequence(const int &sv)
{
	bfs(sv);

	mask[0] = 0;
	for (int i = 1; i <= q_n; ++i)
	{
		int u = q[i], v = fa[u];
		mask[u] = mask[v];
		mask[u] ^= 1 << (s[u] - 'a');
	}

	dfn_l[sv] = 1;
	dfn_r[sv] = q_n;
	for (int i = 1; i <= q_n; ++i)
	{
		int u = q[i];
		int k = dfn_l[u];
		seq[k] = u;

		for (int v : adj[u])
		{
			if (deleted[v] || v == fa[u])
				continue;
			dfn_l[v] = k + 1;
			dfn_r[v] = k + weight[v];
			k += weight[v];
		}
	}
}

int cnt[1 << NLet];

s64 sum[MaxN + 1];
s64 out[MaxN + 1];

inline void add(int u, int d)
{
	cnt[mask[u]] += d;
	for (int i = 0; i < NLet; ++i)
		cnt[mask[u] ^ (1 << i)] += d;
}

void build_lev(const int &u, const int &lev)
{
	int vC = centroid(u);

	deleted[vC] = true;

	get_dfs_sequence(vC);

	int w = 1 << (s[vC] - 'a');
	s64 t = 0;
	for (int i = 2; i <= q_n; ++i)
		add(q[i], 1);
	for (int v : adj[vC])
		if (!deleted[v])
		{
			int l = dfn_l[v];
			int r = dfn_r[v];
			for (int i = l; i <= r; ++i)
				add(seq[i], -1);

			for (int i = l; i <= r; ++i)
				sum[seq[i]] = cnt[mask[seq[i]] ^ w];
			for (int i = r; i > l; --i)
			{
				int u = seq[i];
				sum[fa[u]] += sum[u];
			}

			t += sum[v];
			for (int i = l; i <= r; ++i)
				out[seq[i]] += sum[seq[i]];

			for (int i = l; i <= r; ++i)
				add(seq[i], 1), sum[seq[i]] = 0;
		}
	for (int i = 2; i <= q_n; ++i)
		add(q[i], -1);

	for (int i = 1; i <= q_n; ++i)
		sum[q[i]] += bit[mask[q[i]]] <= 1;
	for (int i = q_n; i > 1; --i)
		sum[fa[q[i]]] += sum[q[i]];

	out[vC] += t / 2;
	for (int i = 1; i <= q_n; ++i)
		out[q[i]] += sum[q[i]], sum[q[i]] = 0;

	for (int v : adj[vC])
		if (!deleted[v])
			build_lev(v, lev + 1);
}

int main()
{
	bit[0] = 0;
	for (int i = 1; i < 1 << NLet; ++i)
		bit[i] = bit[i >> 1] + (i & 1);

	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		int u = getint(), v = getint();
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	scanf("%s", s + 1);

	build_lev(1, 0);

	for (int u = 1; u <= n; ++u)
		printf("%lld ", out[u]);
	printf("\n");

	return 0;
}