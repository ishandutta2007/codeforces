#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct MF {
	static const int mxn = 4005;
	struct E {
		int v, w, i, r;
		E(int v, int w, int i, int r): v(v), w(w), i(i), r(r) {}
	};
	vector <E> g[mxn];
	inline void add_edge(int u, int v, int w, int i) {
		g[u].pb(E(v, w, i, (int)(g[v].size())));
		g[v].pb(E(u, 0, i, (int)(g[u].size()) - 1));
	}
	int dis[mxn], que[mxn], ql, qr;
	bool bfs(int S, int T) {
		memset(dis, -1, sizeof(dis));
		ql = qr = 0;
		dis[S] = 0; que[qr ++] = S;
		while (ql < qr) {
			int u = que[ql ++];
			if (u == T) break;
			rep(i, g[u].size()) {
				int v = g[u][i].v, w = g[u][i].w;
				if (w && dis[v] == -1) {
					dis[v] = dis[u] + 1;
					que[qr ++] = v;
				}
			}
		}
		return dis[T] != -1;
	}
	int id[mxn];
	int dfs(int u, int T, int f) {
		if (u == T) return f;
		int flow = 0;
		for (int& i = id[u]; i < (int)(g[u].size()); ++ i) {
			int v = g[u][i].v, w = g[u][i].w;
			if (w && dis[v] == dis[u] + 1) {
				int d = dfs(v, T, min(f, w));
				if (d > 0) {
					f -= d; flow += d;
					g[u][i].w -= d;
					g[v][g[u][i].r].w += d;
					if (f == 0) break;
				}
			}
		}
		return flow;
	}
	int solve(int S, int T) {
		int ans = 0;
		while (bfs(S, T)) {
			memset(id, 0, sizeof(id));
			ans += dfs(S, T, 0x3f3f3f3f);
		}
		return ans;
	}
} mf;

int n1, n2, m;
int deg[4005];
vector <int> Ans[2005];

int main() {
	scanf("%d %d %d", &n1, &n2, &m);
	int S = n1 + n2, T = S + 1;
	rep(i, m) {
		int u, v;
		scanf("%d %d", &u, &v);
		-- u; -- v;
		++ deg[u]; ++ deg[v + n1];
		mf.add_edge(u, v + n1, 1, i);
	}
	int mn = 0x3f3f3f3f;
	rep(i, n1 + n2) mn = min(mn, deg[i]);
	rep(i, n1) mf.add_edge(S, i, deg[i] - mn, -1);
	rep(i, n2) mf.add_edge(i + n1, T, deg[i + n1] - mn, -1);
	for (int k = mn; k >= 0; -- k) {
		mf.solve(S, T);
		vector <int> ans;
		rep(i, n1) rep(j, mf.g[i].size())
			if (mf.g[i][j].v >= n1 && mf.g[i][j].v < n1 + n2)
				if (mf.g[i][j].w) ans.pb(mf.g[i][j].i);
		Ans[k] = ans;
		rep(i, n1) mf.add_edge(S, i, 1, -1);
		rep(i, n2) mf.add_edge(i + n1, T, 1, -1);
	}
	rep(k, mn + 1) {
		printf("%d", (int)(Ans[k].size()));
		rep(i, Ans[k].size()) printf(" %d", Ans[k][i] + 1);
		printf("\n");
	}
	return 0;
}