#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

signed main(){
#ifndef hollwo_pelw_local
	if (fopen("hollwo_pelw.inp", "r"))
		assert(freopen("hollwo_pelw.inp", "r", stdin)), assert(freopen("hollwo_pelw.out", "w", stdout));
#else
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

struct dinic_maxflow {
	using flow_t = int64_t;
	static const flow_t inf = 1e18;
	
	struct flow_edge {
		int u, v; flow_t c, f;
		flow_edge (int _u = 0, int _v = 0, flow_t _c = 0) : u(_u), v(_v), c(_c) {}
	};
	vector<flow_edge> edges;

	int n, s, t;
	vector<int> level, ptr;
	vector<vector<int>> adj;

	queue<int> q;

	dinic_maxflow(int _n = 0) : n(_n), level(n), ptr(n), adj(n) {}

	inline void add_edge(int u, int v, flow_t c = inf) {
#define do_add(u, v, c) adj[u].push_back(edges.size()), edges.emplace_back(u, v, c)
		do_add(u, v, c), do_add(v, u, 0);
	}

	inline bool bfs() {
		fill(level.begin(), level.end(), -1);
		level[s] = 0, q.push(s);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto id : adj[u]) {
				int v = edges[id].v;
				if (edges[id].c > edges[id].f && level[v] == -1)
					level[v] = level[u] + 1, q.push(v);
			}
		}
		return level[t] != -1;
	}

	inline flow_t dfs(int u, flow_t push) {
		if (!push || u == t) return push;
		for (int &i = ptr[u]; i < (int) adj[u].size(); i++) {
			int id = adj[u][i], v = edges[id].v;
			if (level[v] == level[u] + 1 && edges[id].c > edges[id].f) {
				flow_t nxt_push = dfs(v, min(push, edges[id].c - edges[id].f));
				if (nxt_push) {
					edges[id].f += nxt_push, edges[id ^ 1].f -= nxt_push;
					return nxt_push;
				}
			}
		}
		return 0;
	}

	inline flow_t maxflow(int _s, int _t) {
		for (auto &ed : edges) ed.f = 0;
		s = _s, t = _t;
		flow_t res = 0;
		while (bfs()) {
			fill(ptr.begin(), ptr.end(), 0);
			while (flow_t push = dfs(s, inf)) res += push;
		}
		return res;
	}
} mf(2005);

const int N = 2005;

int n, m, a, b;

void Hollwo_Pelw(){
	cin >> n >> m >> a >> b;
	mf.add_edge(0, a << 1 | 0);
	mf.add_edge(a << 1 | 1, 1);

	mf.add_edge(0, b << 1 | 1);
	mf.add_edge(b << 1 | 0, 1);

	for (int u, v, w; m --; ) {
		cin >> u >> v >> w;
		mf.add_edge(u << 1, v << 1 | 1, w);
		mf.add_edge(v << 1 | 1, u << 1, w);

		mf.add_edge(v << 1, u << 1 | 1, w);
		mf.add_edge(u << 1 | 1, v << 1, w);
	}

	cout << mf.maxflow(0, 1) << '\n';
	for (int i = 1; i <= n; i++) {
		int S = (mf.level[i << 1 | 0] != -1) ^ 0;
		int T = (mf.level[i << 1 | 1] != -1) ^ 1;

		if ((S && !T) || (T && !S)) {
			cout << 'C';
		} else {
			cout << (S ? 'A' : 'B');
		}

	}
}