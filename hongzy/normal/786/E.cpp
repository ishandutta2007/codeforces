#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9 + 11;
namespace net {

const int N = 2e5 + 10;
const int M = 1e7 + 10;
struct Edge { int v, c, f, nxt; } e[M];
int hd[N], ec, n, s, t; 
void clr(int n) {
	net::n = n; t = n - 1; s = n;
	fill(hd + 1, hd + n + 1, -1); ec = 0;
}
void add(int u, int v, int c) {
	e[ec] = (Edge) {v, c, 0, hd[u]}; hd[u] = ec ++;
	e[ec] = (Edge) {u, 0, 0, hd[v]}; hd[v] = ec ++;
}
int d[N], cur[N];
bool bfs() {
	fill(d + 1, d + n + 1, -1);
	queue<int> q; q.push(s); d[s] = 0;
	while(q.size()) {
		int u = q.front(); q.pop();
		for(int i = hd[u]; ~ i; i = e[i].nxt) {
			int v = e[i].v;
			if(e[i].c > e[i].f && -1 == d[v]) {
				d[v] = d[u] + 1; q.push(v);
			}
		}
	}
	return ~ d[t];
}
int dfs(int u, int s) {
	if(u == t || s == 0) return s;
	int flow = 0, f;
	for(int &i = cur[u]; ~ i; i = e[i].nxt) {
		int v = e[i].v;
		if(d[u] + 1 == d[v] && (f = dfs(v, min(s, e[i].c - e[i].f))) > 0) {
			flow += f; e[i].f += f; e[i ^ 1].f -= f;
			if((s -= f) == 0) break ;
		}
	}
	return flow;
}
int dinic() {
	int ans = 0;
	while(bfs()) {
		copy(hd + 1, hd + n + 1, cur + 1);
		ans += dfs(s, INF);
	}
	return ans;
}

}
const int N = 3e4 + 10;
int n, m, fa[N], fw[N], sz[N], son[N];
int dfn[N], pos[N], top[N], idx, d[N];
struct Edge { int v, id; };
vector<Edge> G[N];
void dfs(int u) {
	sz[u] = 1; d[u] = d[fa[u]] + 1;
	for(auto e : G[u]) if(e.v != fa[u]) {
		fa[e.v] = u; fw[e.v] = e.id; dfs(e.v); sz[u] += sz[e.v];
		if(sz[e.v] > sz[son[u]]) son[u] = e.v;
	}
}
void dfs2(int u, int t) {
	top[u] = t; dfn[u] = ++ idx; pos[idx] = u;
	if(son[u]) {
		dfs2(son[u], t);
		for(auto e : G[u]) if(!dfn[e.v]) dfs2(e.v, e.v);
	}
}
int num[N << 2], id;
void build(int u, int l, int r) {
	if(l == r) { num[u] = n + l; return ; }
	int mid = (l + r) >> 1; num[u] = ++ id;
	build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
}
void build2(int u, int l, int r) {
	if(l == r) return ;
	int mid = (l + r) >> 1;
	net::add(num[u], num[u << 1], INF);
	net::add(num[u], num[u << 1 | 1], INF);
	build2(u << 1, l, mid); build2(u << 1 | 1, mid + 1, r);
}
void solve(int u, int l, int r, int ql, int qr, int e) {
	if(l == ql && r == qr) { net::add(e, num[u], INF); return ; }
	int mid = (l + r) >> 1;
	if(qr <= mid) solve(u << 1, l, mid, ql, qr, e);
	else if(ql > mid) solve(u << 1 | 1, mid + 1, r, ql, qr, e);
	else {
		solve(u << 1, l, mid, ql, mid, e);
		solve(u << 1 | 1, mid + 1, r, mid + 1, qr, e);
	}
}
void addedge(int u, int v, int e) {
	while(top[u] ^ top[v]) {
		if(d[top[u]] < d[top[v]]) swap(u, v);
		net::add(e, dfn[u], INF); u = fa[top[u]];
	}
	if(dfn[u] > dfn[v]) swap(u, v);
	if(dfn[u] ^ dfn[v]) {
		solve(1, 2, n, dfn[u] + 1, dfn[v], e);
	}
}
int main() {
	// freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int u, v, i = 1; i < n; i ++) {
		scanf("%d%d", &u, &v);
		G[u].push_back({v, i});
		G[v].push_back({u, i});
	}
	dfs(1); dfs2(1, 1); id = n + n + m; build(1, 2, n);
	net::clr(id + 2); build2(1, 2, n);//chain_pre, node, path, seg, s & t
	for(int i = 2; i <= n; i ++) {
		if(top[i] != i && i != son[1]) net::add(dfn[i], dfn[i] - 1, INF);
		net::add(dfn[i], n + dfn[i], INF);
		net::add(n + dfn[i], net::t, 1);
	}
	for(int u, v, i = 1; i <= m; i ++) {
		net::add(net::s, n + n + i, 1);
		scanf("%d%d", &u, &v);
		addedge(u, v, n + n + i);
	}
	static bool path[N], edge[N];
	printf("%d\n", net::dinic());
	int pa = 0, ed = 0;
	for(int i = 0; i < net::ec; i += 2) {
		int u = net::e[i ^ 1].v, v = net::e[i].v;
		if(~ net::d[u] && net::d[v] == -1) {
			if(u == net::s) { path[v - n - n] = 1; pa ++; }
			else {
				u = pos[u - n];
				if(!edge[fw[u]]) { edge[fw[u]] = 1; ed ++; }
			}
		}
	}
	printf("%d", pa);
	for(int i = 1; i <= m; i ++) if(path[i]) printf(" %d", i);
	printf("\n%d", ed);
	for(int i = 1; i < n; i ++) if(edge[i]) printf(" %d", i);
	putchar('\n');
	return 0;
}