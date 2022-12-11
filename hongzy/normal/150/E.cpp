#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e7 + 10;
struct Edge { int v, w; };
int n, m, ans, ansu, ansv, L, R;
int size, rt, nowu, nowv, w[N], sz[N], tw[N];
vector<Edge> G[N];
bool vis[N];
void findrt(int u, int fa = 0) {
	sz[u] = 1; w[u] = 0;
	for(const Edge &e : G[u]) {
		if(e.v != fa && !vis[e.v]) {
			findrt(e.v, u);
			sz[u] += sz[e.v];
			w[u] = max(w[u], sz[e.v]);
		}
	}
	w[u] = max(w[u], size - sz[u]);
	if(!rt || w[u] < w[rt]) rt = u;
}
int d[N], cur_max, curd[N], fw[N];
void dfs0(int u, int fa = 0) {
	cur_max = max(cur_max, d[u] = d[fa] + 1);
	for(const Edge &e : G[u]) {
		if(e.v != fa && !vis[e.v]) {
			dfs0(e.v, u);
		}
	}
}
int st[N], top, low, f[N], g[N], fu[N], gu[N];
bool cmp(int x, int y) {
	return curd[x] < curd[y];
}
void dfs(int u, int we, int fa = 0) {
	if(g[d[u]] < we) {
		g[d[u]] = we; gu[d[u]] = u;
	}
	for(const Edge &e : G[u]) if(e.v != fa && !vis[e.v]) {
		dfs(e.v, we + (e.w >= low ? 1 : -1), u);
	}
}
bool calc(int u, int mid) {
	top = d[u] = 0;
	for(const Edge &e : G[u]) if(!vis[e.v]) {
		cur_max = 0; dfs0(e.v, u);
		curd[e.v] = cur_max;
		st[++ top] = e.v; fw[e.v] = e.w;
	}
	sort(st + 1, st + top + 1, cmp);
	int ld = -1; low = mid;
	for(int i = 1; i <= top; i ++) {
		int v = st[i], nd = curd[v];
		fill(g + 1, g + nd + 1, - INF);
		dfs(v, fw[v] >= low ? 1 : -1);
		for(int j = L; j <= nd && j <= R; j ++)
			if(g[j] >= 0) return nowu = u, nowv = gu[j], 1;
		if(i == 1) {
			copy(g + 1, g + nd + 1, f + 1);
			copy(gu + 1, gu + nd + 1, fu + 1);
		} else {
			static int q[N];
			int ql = 0, qr = 0, pos = min(R - 1, ld); //!
			for(int j = 1; j <= nd; j ++) {
				for(; pos >= L - j && pos >= 1; pos --) {
					for(; ql < qr && f[q[qr - 1]] <= f[pos]; qr --) ;
					q[qr ++] = pos;
				}
				for(; ql < qr && q[ql] > R - j; ql ++) ; 
				if(ql < qr && f[q[ql]] + g[j] >= 0)
					return nowu = fu[q[ql]], nowv = gu[j], 1;
			}
			for(int j = 1; j <= ld; j ++) if(f[j] < g[j]) f[j] = g[j], fu[j] = gu[j];
			for(int j = ld + 1; j <= nd; j ++) f[j] = g[j], fu[j] = gu[j];
		}
		ld = nd;
	}
	return 0;
}
void solve(int u) {
	int tsz = size; vis[u] = 1;
	int l = 1, r = m, uu = -1, vv = -1, res = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(calc(u, tw[mid])) {
			l = (res = mid) + 1;
			uu = nowu; vv = nowv;
		} else r = mid - 1;
	}
	if(res > ans) {
		ans = res; ansu = uu; ansv = vv;
	}
	for(const Edge &e : G[u]) {
		if(!vis[e.v]) {
			rt = 0; size = sz[e.v] > sz[u] ? tsz - sz[u] : sz[e.v];
			findrt(e.v); solve(rt);
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &L, &R);
	for(int u, v, w, i = 1; i < n; i ++) {
		scanf("%d%d%d", &u, &v, &w);
		G[u].push_back({v, w});
		G[v].push_back({u, w});
		tw[i] = w;
	}
	sort(tw + 1, tw + n);
	m = unique(tw + 1, tw + n) - tw - 1;
	rt = 0; size = n; findrt(1); solve(rt);
	printf("%d %d\n", ansu, ansv);
	return 0;
}