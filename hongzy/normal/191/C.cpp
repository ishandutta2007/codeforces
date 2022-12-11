#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 1e5 + 10;

int n, m, c[N], fr[N], to[N];
int f[N][20], d[N];
vector<int> G[N];

void dfs(int u, int fa) {
	d[u] = d[f[u][0] = fa] + 1;
	for(int i = 1; i < 20; i ++)
		f[u][i] = f[f[u][i - 1]][i - 1];
	for(int & v : G[u]) if(v ^ fa) dfs(v, u);
}

int lca(int u, int v) {
	if(d[u] < d[v]) swap(u, v);
	int c = d[u] - d[v];
	for(int i = 0; i < 20; i ++)
		if(c >> i & 1) u = f[u][i];
	if(u == v) return u;
	for(int i = 19; i >= 0; i --)
		if(f[u][i] ^ f[v][i]) u = f[u][i], v = f[v][i];
	return f[u][0];
}

int dfs2(int u) {
	for(int & v : G[u]) if(v ^ f[u][0]) c[u] += dfs2(v);
	return c[u];
}

int main() {
	scanf("%d", &n);
	for(int i = 1, u, v; i < n; i ++) {
		scanf("%d%d", &u, &v); fr[i] = u; to[i] = v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	scanf("%d", &m);
	for(int i = 1, u, v; i <= m; i ++) {
		scanf("%d%d", &u, &v);
		int f = lca(u, v);
		c[f] -= 2, c[u] ++, c[v] ++;
	}
	dfs2(1);
	for(int i = 1; i < n; i ++)
		printf("%d ", c[f[fr[i]][0] == to[i] ? fr[i] : to[i]]);
	return 0;
}