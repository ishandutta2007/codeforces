#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 205;
int T, n, m;

struct Edge {
	int u, v, id;
	Edge() {}
	Edge(int u, int v, int id) : u(u), v(v), id(id) {}
} edge[N * N];
int en;

int vis[N * N];
int head[N], nxt[N * N];

void addedge(int u, int v, int id) {
	edge[en] = Edge(u, v, id);
	nxt[en] = head[u];
	head[u] = en++;
}

int du[N];
vector<int> g[N];

void dfs(int u) {
	for (int i = head[u]; i + 1; i = nxt[i]) {
		int v = edge[i].v;
		int id = edge[i].id;
		if (vis[id]) continue;
		vis[id] = 1;
		du[u]--; du[v]--;
		g[u].push_back(v);
		dfs(v);
		break;
	}
}

int chu[N], ru[N];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		int u, v;
		memset(du, 0, sizeof(du));
		memset(head, -1, sizeof(head));
		memset(vis, 0, sizeof(vis));
		en = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &u, &v);
			du[u]++; du[v]++;
			addedge(u, v, i);
			addedge(v, u, i);
		}
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i <= n; i++)
			if (du[i] % 2) dfs(i);
		for (int i = 1; i <= n; i++)
			dfs(i);
		memset(chu, 0, sizeof(chu));
		memset(ru, 0, sizeof(ru));
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < g[i].size(); j++) {
				int v = g[i][j];
				ru[v]++; chu[i]++;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) if (chu[i] == ru[i]) ans++;
		printf("%d\n", ans);
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < g[i].size(); j++) {
				printf("%d %d\n", i, g[i][j]);
			}
		}
	}
	return 0;
}