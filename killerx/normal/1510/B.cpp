#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int inf = 0x3f3f3f3f;

struct Edge {
	int v, w, c, r;

	Edge(int _v, int _w, int _c, int _r): v(_v), w(_w), c(_c), r(_r) { }
};

struct MinCostFlow {
	static const int mxn = 1024 * 2 + 5;
	static const int M = 23333;

	int n, S, T;
	int tot;
	std::vector <Edge> adj[mxn];
	int dis[mxn], inque[mxn], que[mxn], ql, qr;
	int prv[mxn], pre[mxn];

	void init(int _n, int _S, int _T) {
		n = _n, S = _S, T = _T;
		tot = 0;
		rep(i, n) adj[i].clear();
	}

	void __add_edge(int u, int v, int w, int c) {
		adj[u].push_back(Edge(v, w, c, (int) adj[v].size()));
		adj[v].push_back(Edge(u, 0, -c, (int) adj[u].size() - 1));
	}

	void add_edge(int u, int v, int w0, int w1, int c) {
		// printf("%d %d [%d, %d] %d\n", u, v, w0, w1, c);
		tot += w0 * M;
		if (w0) __add_edge(u, v, w0, c - M);
		if (w1 - w0) __add_edge(u, v, w1 - w0, c);
	}

	bool spfa() {
		rep(i, n) dis[i] = inf; dis[S] = 0;
		ql = qr = 0; que[qr ++] = S;
		rep(i, n) inque[i] = 0; inque[S] = 1;
		while (ql != qr) {
			int u = que[ql ++]; inque[u] = 0;
			if (ql == mxn) ql = 0;
			rep(i, adj[u].size()) {
				int v = adj[u][i].v, w = adj[u][i].w, c = adj[u][i].c;
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
		return dis[T] < inf / 2;
	}

	std::pair <int, int> solve() {
		int flow = 0, cost = 0;
		while (spfa() && dis[T] < 0) {
			int f = inf;
			for (int u = T; u != S; u = prv[u])
				f = std::min(f, adj[prv[u]][pre[u]].w);
			flow += f;
			cost += f * dis[T];
			for (int u = T; u != S; u = prv[u]) {
				adj[prv[u]][pre[u]].w -= f;
				adj[u][adj[prv[u]][pre[u]].r].w += f;
			}
		}
		return std::make_pair(flow, cost);
	}
} mcf;

int d, n;
char s[1024][15];
int p[1024], deg[1024];

int main() {
	scanf("%d %d", &d, &n);
	rep(i, n) scanf("%s", s[i]);
	int S = n << 1, T = n << 1 | 1;
	mcf.init(n * 2 + 2, S, T);
	rep(i, n) rep(j, n) if (i != j) {
		bool ok = true;
		rep(k, d) ok &= s[i][k] <= s[j][k];
		if (ok) mcf.add_edge(i << 1 | 1, j << 1, 0, 1, 0);
	}
	rep(i, n) {
		int cnt = 0;
		rep(j, d) if (s[i][j] == '1') ++ cnt;
		mcf.add_edge(i << 1, i << 1 | 1, 1, 1, 0);
		mcf.add_edge(S, i << 1, 0, 1, 0);
		mcf.add_edge(i << 1 | 1, T, 0, 1, cnt + 1);
	}
	auto pr = mcf.solve();
	// printf("%d %d\n", pr.first, pr.second + mcf.tot);
	rep(i, n) p[i] = -1;
	rep(i, n) {
		rep(j, mcf.adj[i << 1 | 1].size()) {
			if (mcf.adj[i << 1 | 1][j].v % 2 == 0 &&
				mcf.adj[i << 1 | 1][j].v / 2 < n &&
				mcf.adj[i << 1 | 1][j].w == 0 &&
				mcf.adj[i << 1 | 1][j].c == 0) {
				p[mcf.adj[i << 1 | 1][j].v / 2] = i;
				deg[i] ++;
			}
		}
	}
	printf("%d\n", pr.second + mcf.tot - 1);
	bool is_first = true;
	rep(i, n) if (!deg[i]) {
		if (!is_first) printf("R ");
		is_first = false;
		std::vector <int> stk;
		for (int u = i; ~u; u = p[u]) {
			for (int j = d - 1; ~j; -- j) {
				char a = p[u] == -1 ? '0' : s[p[u]][j];
				char b = s[u][j];
				if (a < b) stk.push_back(j);
			}
		}
		for (int i = (int) stk.size() - 1; ~i; -- i)
			printf("%d ", stk[i]);
	}
	printf("\n");
	return 0;
}