#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 3030;
std::vector<int> G[maxn];
int ex[maxn], ey[maxn];
int size[maxn];
ll f[maxn][maxn];

void dp(int x, int fx, int y, int fy) {
	if(f[x][y]) return;
	for(int v : G[x])
		if(v != fx) {
			dp(v, x, y, fy);
			f[x][y] = std::max(f[x][y], f[v][y]);
		}
	for(int v : G[y])
		if(v != fy) {
			dp(x, fx, v, y);
			f[x][y] = std::max(f[x][y], f[x][v]);
		}
	f[x][y] += 1ll * size[x] * size[y];
}

void dfs(int u, int fa) {
	size[u] = 1;
	for(int v : G[u])
		if(v != fa) {
			dfs(v, u);
			size[u] += size[v];
		}
}

int main() {
	int n = read;
	for(int i = 1; i < n; i ++) {
		int u = ex[i] = read, v = ey[i] = read;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	ll ans = 0;
	for(int i = 1; i < n; i ++) {
		dfs(ex[i], ey[i]);
		dfs(ey[i], ex[i]);
		dp(ex[i], ey[i], ey[i], ex[i]);
		ans = std::max(ans, f[ex[i]][ey[i]]);
	}

	printf("%lld\n", ans);
}