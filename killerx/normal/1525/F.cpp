#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

typedef long long i64;

struct Edge {
	int v, w, r;

	Edge(int _v, int _w, int _r): v(_v), w(_w), r(_r) { }
};

struct MF {
	static const int mxn = 105;

	int n, S, T, id[mxn], dis[mxn], que[mxn], ql, qr;
	std::vector <Edge> adj[mxn];

	inline void add_edge(int u, int v, int w) {
		adj[u].emplace_back(v, w, (int) adj[v].size());
		adj[v].emplace_back(u, 0, (int) adj[u].size() - 1);
	}

	void init(int _n, int _S, int _T) {
		n = _n, S = _S, T = _T;
		rep(i, n) adj[i].clear();
	}

	bool bfs() {
		ql = qr = 0; que[qr ++] = S;
		rep(i, n) dis[i] = -1; dis[S] = 0;
		while (ql < qr) {
			int u = que[ql ++];
			rep(i, adj[u].size()) {
				int v = adj[u][i].v, w = adj[u][i].w;
				if (w && dis[v] == -1) dis[v] = dis[u] + 1, que[qr ++] = v;
			}
		}
		return dis[T] != -1;
	}

	int dfs(int u, int f = 0x3f3f3f3f) {
		if (u == T) return f;
		int flow = 0;
		for (int &i = id[u]; i < (int) adj[u].size(); ++ i) {
			int v = adj[u][i].v, w = adj[u][i].w, d;
			if (w && dis[v] == dis[u] + 1 && (d = dfs(v, std::min(f, w)))) {
				flow += d, f -= d, adj[u][i].w -= d, adj[v][adj[u][i].r].w += d;
				if (f == 0) break;
			}
		}
		return flow;
	}

	int solve() {
		int ans = 0;
		while (bfs()) { rep(i, n) id[i] = 0; ans += dfs(S); }
		return ans;
	}
} mf;

const int mxn = 55;

int n, m, k;
bool adj[mxn][mxn];
bool ban[mxn * 2];
int f[mxn];
int f_las[mxn], f_frm[mxn];
int x[mxn], y[mxn];
i64 dp[mxn][mxn];
int pr[mxn][mxn];

int solve() {
	int S = n * 2, T = n * 2 + 1;
	mf.init(n * 2 + 2, S, T);
	rep(i, n) rep(j, n) if (adj[i][j] && !ban[i] && !ban[j + n]) mf.add_edge(i, j + n, 1);
	rep(i, n) mf.add_edge(S, i, !ban[i]);
	rep(j, n) mf.add_edge(j + n, T, !ban[j + n]);
	return n - mf.solve();
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	rep(i, m) {
		int u, v; scanf("%d %d", &u, &v); -- u, -- v;
		adj[u][v] = 1;
	}
	rep(i, k) {
		scanf("%d %d", &x[i], &y[i]);
	}
	memset(f, 0x3f, sizeof(f));
	int wav = solve();
	f[wav] = 0;
	int ini = wav;
	while (wav < n) {
		int nwav = 0, u = -1;
		rep(i, n * 2) if (!ban[i]) {
			ban[i] = 1;
			int cur = solve();
			if (cur > nwav) {
				nwav = cur;
				u = i;
			}
			ban[i] = 0;
		}
		f[nwav] = f[wav] + 1;
		f_las[nwav] = u;
		f_frm[nwav] = wav;
		ban[u] = 1;
		wav = nwav;
	}
	memset(dp, -0x3f, sizeof(dp));
	dp[0][ini] = 0;
	rep(i, k) {
		rep(j, n + 1) {
			if (dp[i][j] >= 0) {
				for (int nj = std::max(j, i + 2); nj <= n; ++ nj) if (f[nj] <= n) {
					if (dp[i + 1][nj] < dp[i][j] + std::max(0LL, x[i] - 1LL * y[i] * (f[nj] - f[j]))) {
						dp[i + 1][nj] = dp[i][j] + std::max(0LL, x[i] - 1LL * y[i] * (f[nj] - f[j]));
						pr[i + 1][nj] = j;
					}
				}
			}
		}
	}
	i64 ans = 0;
	int w = -1;
	rep(j, n + 1) if (dp[k][j] > ans) ans = dp[k][j], w = j;
	int i = k;
	std::vector <int> vec;
	while (i) {
		vec.push_back(0);
		int nw = w;
		while (nw != pr[i][w]) {
			if (f_las[nw] >= n) vec.push_back(-(f_las[nw] - n + 1));
			else vec.push_back(f_las[nw] + 1);
			nw = f_frm[nw];
		}
		w = nw;
		-- i;
	}
	// eprintf("%lld\n", ans);
	std::reverse(vec.begin(), vec.end());
	printf("%d\n", (int) vec.size());
	rep(i, vec.size()) printf("%d ", vec[i]);
	printf("\n");
	return 0;
}