#if 0
2020.03.19

 m 

DP  f[u][i], g[u][i]  u  i 
 u  u 

#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 3030;
const ll inf = 1000000000000000000;
std::vector<int> G[maxn];
int a[maxn];
struct DP {
	ll x, y;
} f[maxn][maxn], g[maxn];
int size[maxn];

inline void chkmax (DP &f1, DP f2) {
	if(f2.x > f1.x or (f2.x == f1.x and f2.y > f1.y))
		f1 = f2;
}

DP merge (DP f1, DP f2) {
	return {f1.x + f2.x, f1.y + f2.y};
}

DP add (DP f1, DP f2) {
	return {f1.x + f2.x + (f2.y > 0), f1.y};
}

void dp (int u, int fa) {
	int &n = size[u] = 1;
	f[u][1] = {0, a[u]};

	for(int v : G[u])
		if(v != fa)
			dp(v, u);

	for(int v : G[u])
		if(v != fa) {
			int m = size[v];
			for(int i = 1; i <= n + m; i ++)
				g[i] = {0, -inf};
			for(int i = 1; i <= n; i ++)
				for(int j = 1; j <= m; j ++) {
					chkmax(g[i + j - 1], merge(f[u][i], f[v][j]));
					chkmax(g[i + j], add(f[u][i], f[v][j]));
				}
			n += m;
			for(int i = 1; i <= n; i ++)
				f[u][i] = g[i];
		}
}

int main () {
	int T = read;
	while(T --) {
		int n = read, m = read;
		for(int i = 1; i <= n; i ++)
			a[i] = -read;
		for(int i = 1; i <= n; i ++)
			a[i] += read;
		for(int i = 1; i <= n; i ++)
			G[i].clear();
		for(int i = 1; i < n; i ++) {
			int u = read, v = read;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dp(1, 0);
		printf("%lld\n", f[1][m].x + (f[1][m].y > 0));
	}
}