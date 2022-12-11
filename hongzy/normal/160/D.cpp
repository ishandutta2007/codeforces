#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 2e5 + 10;

struct Edge {
	int u, v, w, id;
	bool operator < (const Edge &b) const {
		return w < b.w;
	}
} e[N];
int n, m, f[N];
bool all[N], some[N], vis[N];

struct Edge2 {
	int v, w, nxt, id;
} e2[N];
int hd[N], p;

void clr() {
	fill(hd + 1, hd + n + 1, -1);
}
void add(int u, int v, int w, int id) {
	e2[p] = (Edge2) {v, w, hd[u], id}; hd[u] = p ++;
}
int get(int u) {
	return f[u] == u ? u : f[u] = get(f[u]);
}

bool unite(int u, int v) {
	u = get(u); v = get(v);
	if(u == v) return 0;
	return f[u] = v, 1;
}

int faw[N], faid[N], dep[N], g[N][20];
void dfs(int u, int fa = 0) {
	dep[u] = dep[fa] + 1;
	g[u][0] = fa;
	for(int i = 1; i < 20; i ++) {
		g[u][i] = g[g[u][i - 1]][i - 1];
	}
	for(int i = hd[u]; ~ i; i = e2[i].nxt) {
		if(e2[i].v == fa) continue ;
		faw[e2[i].v] = e2[i].w;
		faid[e2[i].v] = e2[i].id;
		dfs(e2[i].v, u);	
	}
}
int lca(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	int dc = dep[u] - dep[v];
	for(int i = 0; i < 20; i ++)
		if(dc >> i & 1) {
			u = g[u][i];
		}
	if(u == v) return u;
	for(int i = 19; i >= 0; i --) {
		if(g[u][i] != g[v][i]) {
			u = g[u][i]; v = g[v][i];
		}
	}
	return g[u][0];
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i ++) {
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
		e[i].id = i;
	}
	sort(e + 1, e + m + 1); clr();
	for(int i = 1; i <= n; i ++) f[i] = i;
	for(int i = 1; i <= m; i ++) {
		if(unite(e[i].u, e[i].v)) {
			add(e[i].u, e[i].v, e[i].w, e[i].id);
			add(e[i].v, e[i].u, e[i].w, e[i].id);
			vis[i] = 1; all[e[i].id] = some[e[i].id] = 1;
		}
	}
	dfs(1);
	for(int i = 1; i <= m; i ++) if(!vis[i]) {
		int x = lca(e[i].u, e[i].v), wei = e[i].w, mn = 1e9;
//		printf("x = %d, u = %d, v = %d\n", x, e[i].u, e[i].v);
//		for(int u = e[i].u; u != x; u = g[u][0]) mn = min(mn, faw[u]);
//		for(int u = e[i].v; u != x; u = g[u][0]) mn = min(mn, faw[u]);
//		printf("mn = %d, wei = %d\n", mn, wei);
//		if(mn != wei) continue ;
		for(int u = e[i].u; u != x; u = g[u][0]) {
			if(wei == faw[u]) {
//				printf("pity!");
				int j = faid[u];
				some[e[i].id] = 1;
				all[j] = 0;
			}
		}
		for(int u = e[i].v; u != x; u = g[u][0]) {
			if(wei == faw[u]) {
//				printf("pity!");
				int j = faid[u];
				some[e[i].id] = 1;
				all[j] = 0;
			}
		}
	}
	for(int i = 1; i <= m; i ++) {
		if(all[i]) puts("any");
		else if(some[i]) puts("at least one");
		else puts("none");
	}
	return 0;
}