#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

typedef long long ll;

const int N = 5010;

struct Edge {
	int v, w, nxt;
} e[N << 1];
int n, p, hd[N], sz[N];
ll dis[N];
bool ban[N << 1], vis[N];

void clr() {
	fill(hd + 1, hd + n + 1, -1); p = 0;
}
void add(int u, int v, int w) {
	e[p] = (Edge) {v, w, hd[u]}; hd[u] = p ++;
}
void epp() {
	int u = e[p - 1].v, v = e[p - 2].v;
	hd[u] = e[p - 2].nxt; hd[v] = e[p - 1].nxt;
	p -= 2;
}
ll bfs(int s) {
	static ll d[N];
	ll ans = 0;
	queue<int> q; q.push(s);
	fill(d + 1, d + n + 1, -1); d[s] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int i = hd[u]; ~ i; i = e[i].nxt) if(!ban[i]) {
			if(d[e[i].v] == -1) {
				d[e[i].v] = d[u] + e[i].w;
				q.push(e[i].v);
			}
		}
	}
	for(int i = 1; i <= n; i ++) {
		if(~ d[i]) {
			ans += d[i];
		}
	}
	return ans;
}
void gsz(int u, int fa) {
	sz[u] = 1; vis[u] = 1;
	for(int i = hd[u]; ~ i; i = e[i].nxt) if(!ban[i]) {
		int v = e[i].v;
		if(v == fa) continue ;
		gsz(v, u); sz[u] += sz[v];
	}
}
void dfs(int u, int rt, int fa) {
	for(int i = hd[u]; ~ i; i = e[i].nxt) if(!ban[i]) {
		int v = e[i].v, w = e[i].w;
		if(v == fa) continue ;
		dis[v] = dis[u] + (sz[rt] - 2ll * sz[v]) * w;
		dfs(v, rt, u);
	}
}

ll dfs2(int u, int fa) {
	ll ans = 0; sz[u] = 1;
	for(int i = hd[u]; ~ i; i = e[i].nxt) if(!ban[i]) {
		int v = e[i].v, w = e[i].w;
		if(v == fa) continue ;
		ans += dfs2(v, u) + w * 1ll * sz[v] * (n - sz[v]);
		sz[u] += sz[v];
	}
	return ans;
}
int main() {
	scanf("%d", &n); clr();
	for(int i = 1; i < n; i ++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w); add(v, u, w);
	}
	ll ans = 1e18;
	for(int i = 0; i < p; i += 2) {
		int u = e[i ^ 1].v, v = e[i].v, u0 = -1, v0 = -1;
		ban[i] = ban[i ^ 1] = 1;
		
		fill(vis + 1, vis + n + 1, 0);
		gsz(u, 0); dis[u] = bfs(u); dfs(u, u, 0);
		for(int j = 1; j <= n; j ++) if(vis[j]) {
			if(u0 == -1 || dis[j] < dis[u0]) {
				u0 = j;
			}
		}
		
		fill(vis + 1, vis + n + 1, 0);
		gsz(v, 0); dis[v] = bfs(v); dfs(v, v, 0);
		for(int j = 1; j <= n; j ++) if(vis[j]) {
			if(v0 == -1 || dis[j] < dis[v0]) {
				v0 = j;
			}
		}
		add(u0, v0, e[i].w); add(v0, u0, e[i].w);
		ans = min(ans, dfs2(n, 0));
		ban[i] = ban[i ^ 1] = 0; epp();
	}
	printf("%I64d\n", ans);
	return 0;
}