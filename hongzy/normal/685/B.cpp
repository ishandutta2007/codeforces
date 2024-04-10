#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

const int N = 3e5 + 10; 

int n, q, ans[N], p[N], f[N], sz[N];
vector<int> G[N];

void dfs(int u) {
	sz[u] = 1;
	for(int v : G[u]) {
		dfs(v); sz[u] += sz[v];
		f[u] = max(f[u], sz[v]);
	}
	int g = f[u]; ans[u] = u;
	for(int v : G[u]) {
		int o = ans[v], la = max(sz[u] - sz[o], f[o]), res = o;
		while(o != u) {
			o = p[o];
			int nw = max(sz[u] - sz[o], f[o]);
			if(nw >= la) break ;
			res = o; la = nw;
		}
		if(la < g) { g = la; ans[u] = res; }
	}
}

int main() {
	scanf("%d%d", &n, &q);
	for(int i = 2; i <= n; i ++) {
		scanf("%d", p + i);
		G[p[i]].push_back(i);
	}
	dfs(1);
	while(q --) {
		int u; scanf("%d", &u);
		printf("%d\n", ans[u]);
	}
	return 0;
}