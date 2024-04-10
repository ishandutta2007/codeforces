#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 150005, mod = 998244353;
ll bit[maxn];
std::vector<int> G[maxn];
int top[maxn], deep[maxn], fa[maxn], size[maxn], son[maxn];
ll tag[maxn];

inline ll power (ll x, int k) {
	if (k < 0) k += mod - 1;
	ll res = 1;
	while (k) {
		if (k & 1) (res *= x) %= mod;
		(x *= x) %= mod;
		k >>= 1;
	}
	return res;
}

void modify (int l, int r, ll x) {
	for (int k = r; k; k -= k & -k) bit[k] += x;
	for (int k = l - 1; k; k -= k & -k) bit[k] -= x;
}

ll query (int p) {
	ll res = 0;
	for (int k = p; k < maxn; k += k & -k) res += bit[k];
	return res % mod;
}

void dfs1 (int u) {
	deep[u] = deep[fa[u]] + 1;
	size[u] = 1;
	for (int v : G[u])
		if (v != fa[u]) {
			fa[v] = u;
			dfs1(v);
			size[u] += size[v];
			if (size[v] > size[son[u]])
				son[u] = v;
		}
}

int id[maxn], iid[maxn], ip;
void dfs2 (int u) {
	if (!top[u]) top[u] = u;
	id[u] = ++ ip;
	if (son[u]) {
		top[son[u]] = top[u];
		dfs2(son[u]);
		for (int v : G[u])
			if (v != fa[u] and v != son[u])
				dfs2(v);
	}
}

int main () {
	int n = read, q = read;
	for (int i = 1; i < n; i ++) {
		int u = read, v = read;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	dfs1(1);
	dfs2(1);

	ll inv = power(n, -1);

	while (q --) {
		int o = read;
		if (o == 1) {
			int u = read, s = son[u];
			ll x = read * inv % mod;
			modify(1, n, x * n % mod);
			if (s) modify(id[s], id[s] + size[s] - 1, size[s] * (mod - x) % mod);
			modify(1, n, (n - size[u]) * (mod - x) % mod);
			modify(id[u], id[u] + size[u] - 1, (n - size[u]) * x % mod);
			tag[u] += x;
		}
		if (o == 2) {
			int u = read;
			ll ans = query(id[u]);
			while (u) {
				u = top[u];
				(ans += size[u] * (mod - tag[fa[u]])) %= mod;
				u = fa[u];
			}
			printf("%lld\n", ans);
		}
	}
}