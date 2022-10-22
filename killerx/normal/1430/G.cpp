#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct MinCostFlow {
	static const int mxn = 105;
	
	struct Edge {
		int v, w, c, r;
	};

	int n, S, T;
	int que[mxn], ql, qr;
	int dis[mxn], pre[mxn], prv[mxn];
	std::vector <Edge> adj[mxn];
	bool inque[mxn];

	void add_edge(int u, int v, int w, int c) {
		adj[u].push_back({v, w, c, (int) adj[v].size()});
		adj[v].push_back({u, 0, -c, (int) adj[u].size() - 1});
	}

	void init(int _n, int _S, int _T) {
		n = _n; S = _S; T = _T;
		rep(i, n) adj[i].clear();
	}

	bool spfa() {
		rep(i, n) dis[i] = 0x3f3f3f3f;
		dis[S] = 0;
		ql = qr = 0;
		que[qr ++] = S;
		inque[S] = 1;
		while (ql != qr) {
			int u = que[ql ++];
			if (ql == mxn) ql = 0;
			inque[u] = 0;
			rep(i, adj[u].size()) {
				int v = adj[u][i].v;
				int w = adj[u][i].w;
				int c = adj[u][i].c;
				if (w && dis[v] > dis[u] + c) {
					dis[v] = dis[u] + c;
					prv[v] = u;
					pre[v] = i;
					if (!inque[v]) {
						inque[v] = 1;
						que[qr ++] = v;
						if (qr == mxn) qr = 0;
					}
				}
			}
		}
		return dis[T] < 1e9;
	}

	std::pair <int, int> solve() {
		int flow = 0, cost = 0;
		while (spfa()) {
			int f = 0x3f3f3f3f;
			for (int u = T; u != S; u = prv[u])
				f = std::min(f, adj[prv[u]][pre[u]].w);
			flow += f;
			cost += f * dis[T];
			for (int u = T; u != S; u = prv[u]) {
				adj[prv[u]][pre[u]].w -= f;
				adj[u][adj[prv[u]][pre[u]].r].w += f;
			}
		}
		return {flow, cost};
	}
} mcf;

const int mxn = 105;

int n, m;
int W[mxn];
std::vector <std::pair <std::pair <int, int>, int> > edges;
std::vector <std::pair <int, int> > adj[mxn];
int que[mxn], ql, qr;
bool inque[mxn];
int dis[mxn];
int indeg[mxn];

void add_edge(int u, int v, int w) {
	adj[u].push_back({v, w});
}

void spfa() {
	rep(i, n + 1) dis[i] = 0x3f3f3f3f;
	dis[n] = 0;
	ql = qr = 0;
	que[qr ++] = n;
	inque[n] = 1;
	while (ql != qr) {
		int u = que[ql ++];
		if (ql == mxn) ql = 0;
		inque[u] = 0;
		rep(i, adj[u].size()) {
			int v = adj[u][i].first;
			int w = adj[u][i].second;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if (!inque[v]) {
					inque[v] = 1;
					que[qr ++] = v;
					if (qr == mxn) qr = 0;
				}
			}
		}
	}
}

int main() {
	// freopen("dag.in", "r", stdin);
	// freopen("dag.out", "w", stdout);
	scanf("%d %d", &n, &m);
	int S = n;
	int T = n + 1;
	mcf.init(n + 2, S, T);
	rep(i, m) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		-- u, -- v;
		std::swap(u, v);
		mcf.add_edge(u, v, 1e9, -1);
		W[u] -= w;
		W[v] += w;
		edges.push_back({{u, v}, w});
		++ indeg[v];
	}
	rep(u, n) {
		if (W[u] > 0) {
			mcf.add_edge(u, T, W[u], 0);
		} else if (W[u] < 0) {
			mcf.add_edge(S, u, -W[u], 0);
		}
	}
	auto ans = mcf.solve();
	// eprintf("%d %d\n", ans.first, ans.second);
	rep(i, m) {
		int u = edges[i].first.first;
		int v = edges[i].first.second;
		int w = edges[i].second;
		add_edge(v, u, -1);
		rep(j, mcf.adj[u].size()) {
			if (mcf.adj[u][j].v == v) {
				if (mcf.adj[u][j].w < 1e9) {
					add_edge(u, v, 1);
				}
				break;
			}
		}
	}
	rep(u, n) if (indeg[u] == 0) {
		add_edge(n, u, 0);
	}
	spfa();
	int mn = 0x3f3f3f3f;
	rep(i, n) mn = std::min(mn, dis[i]);
	rep(i, n) printf("%d ", dis[i] - mn);
	printf("\n");
	return 0;
}