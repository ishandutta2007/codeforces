#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= (int) k; i ++)
using namespace std;
typedef long long ll;
const int N = 1e5 + 11;
const ll INF = 1e16 + 51;
struct Edge { int v, w; };
vector<Edge> G[N], T[N];
int n, lgn, m, q, f[N], sp, d[N], g[N][20];
bool spe[N];
ll de[N];
int find(int u) { return u == f[u] ? u : f[u] = find(f[u]); }
bool unite(int u, int v) {
	u = find(u); v = find(v); f[u] = v;
	return u != v;
}
void dfs(int u, int fa = 0) {
	d[u] = d[fa] + 1; g[u][0] = fa;
	rep(i, 1, lgn - 1) g[u][i] = g[g[u][i - 1]][i - 1];
	for(auto e : T[u]) if(e.v != fa) {
		de[e.v] = de[u] + e.w; dfs(e.v, u);
	}
}
int lca(int u, int v) {
	if(d[u] < d[v]) swap(u, v);
	int c = d[u] - d[v];
	for(int i = lgn - 1; ~ i; i --)
		if(c >> i & 1) u = g[u][i];
	if(u == v) return u;
	for(int i = lgn - 1; ~ i; i --)
		if(g[u][i] ^ g[v][i]) {
			u = g[u][i]; v = g[v][i];
		}
	return g[u][0];
}
ll dis[45][N];
struct Node {
	int u; ll d;
	bool operator < (const Node &b) const { return d > b.d; }
};
void Dijkstra(int s, ll *d) {
	fill(d + 1, d + n + 1, INF);
	priority_queue<Node> pq; pq.push((Node) {s, d[s] = 0});
	while(pq.size()) {
		int u = pq.top().u; ll du = pq.top().d; pq.pop();
		if(d[u] < du) continue ;
		rep(i, 0, G[u].size() - 1) {
			Edge &e = G[u][i];
			if(d[e.v] > d[u] + e.w) {
				pq.push((Node) {e.v, d[e.v] = d[u] + e.w});
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(lgn = 1; (1 << lgn) <= n; lgn ++) ;
	rep(i, 1, n) f[i] = i;
	rep(i, 1, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[u].pb({v, w}); G[v].pb({u, w});
		if(unite(u, v)) {
			T[u].pb({v, w}); T[v].pb({u, w});
		} else {
			spe[u] = spe[v] = 1;
		}
	}
	dfs(1);
	rep(i, 1, n) if(spe[i]) {
		Dijkstra(i, dis[++ sp]);
	}
	scanf("%d", &q);
	rep(i, 1, q) {
		int u, v;
		scanf("%d%d", &u, &v);
		ll ans = de[u] + de[v] - 2 * de[lca(u, v)];
		rep(j, 1, sp) ans = min(ans, dis[j][u] + dis[j][v]);
		printf("%lld\n", ans);
	}
	return 0;
}