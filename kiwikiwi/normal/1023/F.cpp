#include <bits/stdc++.h>
using namespace std;

const int N = 567890;
const int inf = 1 << 30;

int n, m, k, u, v;
int dep[N], par[N][21], tag[N][21], tye[N];
int f[N], U[N], V[N], W[N];

vector<int> nt;
vector<pair<int, int>> e[N];

int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}

void dfs(int u, int f) {
	dep[u] = dep[f] + 1;
	par[u][0] = f;
	for (auto p : e[u]) {
		int v = p.first;
		if (v != f) {
			tye[v] = p.second;
			dfs(v, u);
		}
	}
}

int lca(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);
	for (int j = 19; j >= 0; j--) {
		if (dep[par[v][j]] >= dep[u]) v = par[v][j];
	}
	if (u == v) return u;
	for (int j = 19; j >= 0; j--) {
		if (par[v][j] != par[u][j]) {
			u = par[u][j];
			v = par[v][j];
		}
	}
	return par[u][0];
}

void add(int u, int v, int w) {
	for (int j = 19; j >= 0; j--) {
		if (dep[par[u][j]] >= dep[v]) {
			tag[u][j] = min(tag[u][j], w);
			u = par[u][j];
		}
	}
	assert(u == v);
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &u, &v);
		f[find(u)] = find(v);
		e[u].push_back(make_pair(v, 0));
		e[v].push_back(make_pair(u, 0));
	}
	static int p[N];
	for (int i = 1; i <= k; i++) {
		scanf("%d%d%d", &U[i], &V[i], &W[i]);
		p[i] = i;
	}
	sort(p + 1, p + k + 1, [&](int a, int b) {
		return W[a] < W[b];
	});
	for (int i = 1; i <= k; i++) {
		u = U[p[i]], v = V[p[i]];
		if (find(u) != find(v)) {
			f[find(u)] = find(v);
			e[u].push_back(make_pair(v, 1));
			e[v].push_back(make_pair(u, 1));
		} else {
			nt.push_back(p[i]);
		}
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 20; j++)
			tag[i][j] = inf;
	for (int j = 1; j < 20; j++)
		for (int i = 1; i <= n; i++)
			par[i][j] = par[par[i][j - 1]][j - 1];
	for (auto p : nt) {
		u = U[p], v = V[p];
		int x = lca(u, v);
		add(u, x, W[p]);
		add(v, x, W[p]);
	}
	for (int j = 19; j >= 1; j--) {
		for (int i = 1; i <= n; i++) {
			tag[i][j - 1] = min(tag[i][j - 1], tag[i][j]);
			tag[par[i][j - 1]][j - 1] = min(tag[par[i][j - 1]][j - 1], tag[i][j]);
		}
	}
	long long ans = 0;
	for (int i = 2; i <= n; i++)
		if (tye[i] == 0) {
			if (tag[i][0] == inf) {
				puts("-1");
				return 0;
			}
			ans += tag[i][0];
		}
	printf("%lld\n", ans);
}