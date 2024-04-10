#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 1005, M = 40005;
const ll INF = 1ll<<60;
typedef ll Type;

struct Edge {
	int u, v;
	Type w;
	Edge() {}
	Edge(int u, int v, Type w) : u(u), v(v), w(w) {}
};

struct DMST {
	int n, m;
	Edge e[M];
	int vis[N], pre[N], id[N];
	Type in[N];

	void init(int _n) {
		n = _n;
		m = 0;
	}
	void add_Edge(int u, int v, Type w) {
		e[m++] = Edge(u, v, w);
	}
	Type dir_mst(int root) {
		Type ans = 0;
		while (true) {
			for (int i = 0; i < n; i++) in[i] = INF;
			for (int i = 0; i < m; i++) {
				int u = e[i].u, v = e[i].v;
				if (e[i].w < in[v] && u != v) {
					in[v] = e[i].w;
					pre[v] = u;
				}
			}
			for (int i = 0; i < n; i++) {
				if (i == root) continue;
				if (in[i] == INF) return -1;
			}
			int cnt = 0;
			memset(id, -1, sizeof(id));
			memset(vis, -1, sizeof(vis));
			in[root] = 0;
			for (int i = 0; i < n; i++) {
				ans += in[i]; int v = i;
				while (vis[v] != i && id[v] == -1 && v != root)
					vis[v] = i, v = pre[v];
				if (v != root && id[v] == -1) {
					for (int u = pre[v]; u != v; u = pre[u])
						id[u] = cnt;
					id[v] = cnt++;
				}
			}
			if (cnt == 0) break;
			for (int i = 0; i < n; i++)
				if (id[i] == -1) id[i] = cnt++;
			for (int i = 0; i < m; i++) {
				int v = e[i].v;
				e[i].u = id[e[i].u];
				e[i].v = id[e[i].v];
				if (e[i].u != e[i].v)
					e[i].w -= in[v];
			}
			n = cnt;
			root = id[root];
		}
		return ans;
	}
} gao;


int n;
int vis[N];

int fa[N];
int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%*d");
		fa[i] = i;
	}
	int m;
	scanf("%d", &m);
	int u, v, w;
	int cnt = n;
	gao.init(n);
	while (m--) {
		scanf("%d%d%d", &u, &v, &w);
		u--; v--;
		int pu = find(u), pv = find(v);
		if (pu != pv) {
			fa[pu] = pv;
			cnt--;
		}
		vis[v] = 1;
		gao.add_Edge(u, v, w);
	}
//	if (cnt != 1) {
//		printf("-1\n");
//		return 0;
//	}
	for (int i = 0; i < n; i++) if (!vis[i]) {
		printf("%lld\n", gao.dir_mst(i));
		return 0;
	}
	printf("-1\n");
	return 0;
}