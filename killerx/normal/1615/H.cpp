#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;
const i64 inf = 1LL << 60;

struct Edge {
	int v;
	i64 w;
	int r;
};

struct MaxFlow {
	static const int mxn = 2005;

	int n, S, T;
	std::vector <Edge> adj[mxn];
	int dis[mxn], que[mxn], ql, qr;
	int id[mxn];

	void init(int _n, int _S, int _T) {
		n = _n, S = _S, T = _T;
		rep(i, n) adj[i].clear();
	}

	inline void add_edge(int u, int v, i64 w) {
		adj[u].push_back({v, w, (int) adj[v].size()});
		adj[v].push_back({u, 0, (int) adj[u].size() - 1});
	}

	bool bfs() {
		ql = qr = 0; que[qr ++] = S;
		rep(i, n) dis[i] = i == S ? 0 : -1;
		while (ql < qr) {
			int u = que[ql ++];
			rep(i, adj[u].size()) {
				int v = adj[u][i].v;
				i64 w = adj[u][i].w;
				if (w && !~dis[v]) {
					dis[v] = dis[u] + 1;
					que[qr ++] = v;
				}
			}
		}
		return ~dis[T];
	}

	i64 dfs(int u, i64 f = inf) {
		if (u == T) return f;
		i64 flow = 0;
		for (int &i = id[u]; i < (int) adj[u].size(); ++ i) {
			int v = adj[u][i].v;
			i64 w = adj[u][i].w;
			if (w && dis[v] == dis[u] + 1) {
				int d = dfs(v, std::min(f, w));
				adj[u][i].w -= d, adj[v][adj[u][i].r].w += d;
				flow += d, f -= d;
				if (!f) break;
			}
		}
		return flow;
	}

	i64 solve() {
		i64 ans = 0;
		while (bfs()) {
			rep(i, n) id[i] = 0;
			ans += dfs(S);
		}
		return ans;
	}

	bool vis[mxn], col[mxn];

	void gg(int u) {
		vis[u] = true;
		col[u] = true;
		for (Edge e : adj[u]) {
			if (e.w && !vis[e.v]) {
				gg(e.v);
			}
		}
	}

	std::vector <std::pair <int, int> > find_cut() {
		rep(i, n) vis[i] = false, col[i] = false;
		gg(S);
		std::vector <std::pair <int, int> > E;
		rep(i, n) for (Edge e : adj[i]) {
			if (col[i] == true && col[e.v] == false) {
				E.push_back({i, e.v});
			}
		}
		return E;
	}
} mf;

const int mxn = 1005;

int n, m;
int va[mxn];
std::vector <int> vec;
int E[mxn][2];
int ans[mxn];

void process(int a, int b, std::vector <int> cur, std::vector <int> &vl, std::vector <int> &vr) {
	int S = cur.size() * 2, T = S + 1;
	mf.init(T + 1, S, T);
	static int ID[mxn];
	rep(i, n) ID[i] = -1;
	rep(i, cur.size()) ID[cur[i]] = i;
	rep(i, cur.size()) {
		mf.add_edge(S, i, std::abs(a - va[cur[i]]));
		mf.add_edge(i, i + cur.size(), inf);
		mf.add_edge(i + cur.size(), T, std::abs(b - va[cur[i]]));
	}
	rep(i, m) {
		if (~ID[E[i][0]] && ~ID[E[i][1]]) {
			mf.add_edge(ID[E[i][0]] + cur.size(), ID[E[i][1]], inf);
		}
	}
	mf.solve();
	auto cut = mf.find_cut();
	for (auto e : cut) {
		if (e.first == S) vl.push_back(cur[e.second]);
		else if (e.second == T) vr.push_back(cur[e.first - cur.size()]);
	}
	std::sort(vl.begin(), vl.end());
	std::sort(vr.begin(), vr.end());
	assert(vl.size() + vr.size() == cur.size());
}

void solve(int l, int r, std::vector <int> cur) {
	/*
	eprintf("[%d, %d]", l, r);
	for (int x : cur) eprintf(" %d", x + 1);
	eprintf("\n");
	*/
	if (l == r) {
		for (int x : cur) ans[x] = vec[l];
		return ;
	}
	if (cur.empty()) return ;
	int mid = (l + r) >> 1;
	std::vector <int> left, right;
	process(vec[mid], vec[mid + 1], cur, left, right);
	solve(l, mid, left);
	solve(mid + 1, r, right);
}

int main() {
	scanf("%d %d", &n, &m);
	rep(i, n) scanf("%d", &va[i]);
	rep(i, n) vec.push_back(va[i]);
	std::sort(vec.begin(), vec.end());
	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
	rep(i, m) scanf("%d %d", &E[i][0], &E[i][1]), -- E[i][0], -- E[i][1];
	std::vector <int> cur(n);
	std::iota(cur.begin(), cur.end(), 0);
	solve(0, vec.size() - 1, cur);
	rep(i, n) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}