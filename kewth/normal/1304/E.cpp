#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 100005, maxk = 20;
std::vector<int> G[maxn];
int fa[maxn][maxk], deep[maxn];

void dfs(int u) {
	deep[u] = deep[*fa[u]] + 1;
	for(int k = 1; k < maxk; k ++)
		fa[u][k] = fa[fa[u][k - 1]][k - 1];
	for(int v : G[u])
		if(v != *fa[u]) {
			*fa[v] = u;
			dfs(v);
		}
}

int lca(int x, int y) {
	if(deep[x] < deep[y])
		std::swap(x, y);
	for(int k = maxk - 1; k >= 0; k --)
		if(deep[fa[x][k]] >= deep[y])
			x = fa[x][k];
	for(int k = maxk - 1; k >= 0; k --)
		if(fa[x][k] != fa[y][k]) {
			x = fa[x][k];
			y = fa[y][k];
		}
	return x == y ? x : *fa[x];
}

int dis(int x, int y) {
	return deep[x] + deep[y] - deep[lca(x, y)] * 2;
}

int main() {
	int n = read;
	for(int i = 1; i < n; i ++) {
		int u = read, v = read;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	dfs(1);

	int q = read;
	while(q --) {
		int x = read, y = read, a = read, b = read, k = read;
		int d = dis(a, b);
		int d1 = dis(a, x) + 1 + dis(y, b);
		int d2 = dis(a, y) + 1 + dis(x, b);
		int dc = dis(x, y) + 1;

		// debug("%d %d %d %d\n", d, d1, d2, dc);

		if(d <= k and (d & 1) == (k & 1)) {
			puts("YES");
			continue;
		}

		if(d1 <= k and (d1 & 1) == (k & 1)) {
			puts("YES");
			continue;
		}

		if(d2 <= k and (d2 & 1) == (k & 1)) {
			puts("YES");
			continue;
		}

		d1 += dc;
		d2 += dc;

		if(d1 <= k and (d1 & 1) == (k & 1)) {
			puts("YES");
			continue;
		}

		if(d2 <= k and (d2 & 1) == (k & 1)) {
			puts("YES");
			continue;
		}

		puts("NO");
	}
}