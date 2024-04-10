#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

#define pb push_back

const int N = 1e5 + 10;

int n, m, a[N], f[N], g[N];
vector<int> G[N];

void dfs(int u, int fa = 0) {
	f[u] = a[u] ? f[fa] + 1 : 0;
	g[u] = max(f[u], g[fa]);
	for(int v : G[u]) if(v != fa) dfs(v, u);
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	for(int i = 1; i < n; i ++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].pb(v); G[v].pb(u);
	}
	dfs(1);
	int ans = 0;
	for(int i = 2; i <= n; i ++)
		if(G[i].size() == 1 && g[i] <= m) ans ++;
	printf("%d\n", ans);
	return 0;
}