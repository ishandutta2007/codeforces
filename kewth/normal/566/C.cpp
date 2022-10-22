#if 0
2020.01.29


 u  g(x) = dis(u, x)^1.5 g 
 f(x)  g(x)  f 
 f(x) 

 u  g(x) = dis(u, x)^1.5  x 
 x  u  g(x) g 
 f(x)  f 
 x  f(x)  x  f 






 u  v  dis(u, v) = w 
 u - v  f(x)  x  u 
 u  v  f 
 f  x = 0  0 
 u  dfs 

 0  v  u 
 u - v 
#endif
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
} read;

const int maxn = 200005;
// int head[maxn], nxt[maxn << 1], to[maxn << 1], len[maxn << 1], hp = 1;
struct Edge {
	int to, w;
};
std::vector<Edge> G[maxn];
int val[maxn];

bool vis[maxn];
int size[maxn];
int cen, csize;
void get(int u, int n) {
	size[u] = 1;
	int now = 0;
	vis[u] = 1;
	for(Edge e : G[u])
		if(!vis[e.to]) {
			get(e.to, n);
			size[u] += size[e.to];
			now = std::max(now, size[e.to]);
		}
	vis[u] = 0;
	now = std::max(now, n - size[u]);
	if(now < csize) {
		cen = u;
		csize = now;
	}
}

int dis[maxn];
double sq[maxn], sum;
void dfs(int u, int fa) {
	sq[u] = sqrt(dis[u]) * val[u];
	sum += sq[u] * dis[u];
	for(Edge e : G[u])
		if(e.to != fa) {
			dis[e.to] = dis[u] + e.w;
			dfs(e.to, u);
			sq[u] += sq[e.to];
		}
}

double ans = 1e100;
int anspos;
void divi(int s, int n) {
	csize = 1000000000;
	get(s, n);
	int u = cen;
	// debug("divi %d get %d\n", s, u);

	dis[u] = 0;
	sum = 0;
	dfs(u, 0);
	if(sum < ans) {
		ans = sum;
		anspos = u;
	}

	// debug("%d : %.5lf\n", u, sq[u]);
	// for(Edge e : G[u])
		// if(!vis[e.to])
			// debug("%d : %.5lf\n", e.to, sq[e.to]);

	int to = 0;
	for(Edge e : G[u])
		if(!vis[e.to] and sq[u] - sq[e.to] * 2 < 0)
			to = e.to;
	if(!to) return;

	vis[u] = 1;
	if(size[to] < size[u])
		divi(to, size[to]);
	else
		divi(to, n - size[u]);
}

int main() {
	int n = read;
	for(int i = 1; i <= n; i ++)
		val[i] = read;

	for(int i = 1; i < n; i ++) {
		int u = read, v = read, w = read;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}

	divi(1, n);
	printf("%d %.7lf\n", anspos, ans);
}