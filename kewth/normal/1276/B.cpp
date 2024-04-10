#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 200005;
std::vector<int> G[maxn];
int fa[maxn], deep[maxn], size[maxn], f[maxn];

int a, b, tot;
void dfs(int u, int shit) {
	deep[u] = deep[fa[u]] + 1;
	size[u] = 1;
	if(shit == 1) {
		for(int v : G[u])
			if(v != fa[u] and deep[v] and deep[v] < deep[b])
				shit = 3;
	}
	f[u] = shit == 3;
	for(int v : G[u])
		if(!deep[v]) {
			fa[v] = u;
			dfs(v, shit | (u == b));
			size[u] += size[v];
		}
	for(int v : G[u])
		if(deep[v] == deep[u] + 1)
			f[u] |= f[v];
	if(fa[u] == b and f[u])
		tot -= size[u];
}

int main () {
	int T = read;
	while(T --) {
		int n = read, m = read;
		a = read;
		b = read;
		tot = 0;
		for(int i = 1; i <= n; i ++) {
			G[i].clear();
			deep[i] = fa[i] = f[i] = size[i] = 0;
		}
		for(int i = 1; i <= m; i ++) {
			int u = read, v = read;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(a, 0);
		tot += size[b] - 1;
		int x = b;
		while(fa[x] != a)
			x = fa[x];
		printf("%lld\n", 1ll * tot * (n - size[x] - 1));
	}
}