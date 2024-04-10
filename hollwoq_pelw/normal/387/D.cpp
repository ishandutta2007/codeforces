/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
	if (fopen(filein.c_str(), "r")){
		freopen(filein.c_str(), "r", stdin);
		freopen(fileout.c_str(), "w", stdout);
#ifdef hollwo_pelw_local
		freopen(fileerr.c_str(), "w", stderr);
#endif
	}
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
#ifdef hollwo_pelw_local
	FAST_IO("input.inp", "output.out", "error.err");
	auto start = chrono::steady_clock::now();
#else
	FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
#endif
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
	return 0;
}

const int N = 1010;

struct Dinic {
	static const int64_t inf = 1e18;
	
	struct flow_edge {
		int u, v; int64_t c, f;
		flow_edge () {}
		flow_edge (int _u, int _v, int64_t _c)
			: u(_u), v(_v), c(_c) {}
	};
	vector<flow_edge> edges;

	int n, s, t, level[N], ptr[N];
	vector<int> adj[N];

	queue<int> q;

	Dinic(int _n = N - 1) : n(_n) {} // [0, n]

	inline void add_edge(int u, int v, int64_t c = inf) {
#define do_add(u, v, c) adj[u].push_back(edges.size()), edges.emplace_back(u, v, c)
		do_add(u, v, c), do_add(v, u, 0);
	}

	inline bool bfs() {
		fill(level, level + n + 1, -1);
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

	inline int64_t dfs(int u, int64_t push) {
		if (!push) return 0;
		if (u == t) return push;
		for (int &i = ptr[u]; i < adj[u].size(); i++) {
			int id = adj[u][i], v = edges[id].v;
			if (level[v] == level[u] + 1 && edges[id].c > edges[id].f) {
				int64_t nxt_push = dfs(v, min(push, edges[id].c - edges[id].f));
				if (nxt_push) {
					edges[id].f += nxt_push, edges[id ^ 1].f -= nxt_push;
					return nxt_push;
				}
			}
		}
		return 0;
	}

	inline int64_t maxflow(int _s, int _t) {
		for (auto &ed : edges) ed.f = 0;
		s = _s, t = _t;
		int64_t res = 0;
		while (bfs()) {
			fill(ptr, ptr + n + 1, 0);
			while (int64_t push = dfs(s, inf))
				res += push;
		}
		return res;
	}
};

int n, m, res = 1e9;
vector<pair<int, int>> edges;

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int u, v; m --; )
		cin >> u >> v, edges.emplace_back(u, v);

	// brute center
	for (int i = 1; i <= n; i++) {
		Dinic dinic(2 * n + 1);
		int cnt = 2 * n - 1, oth = 0;
		for (auto ed : edges) {
			if (ed.first == i || ed.second == i) {
				cnt --;
			}
			else {
				dinic.add_edge(ed.first, ed.second + n, 1);
				oth ++;
			}
		}
		for (int i = 1; i <= n; i++)
			dinic.add_edge(0, i, 1), dinic.add_edge(i + n, 2 * n + 1, 1);
		res = min(res, oth - 2 * (int) dinic.maxflow(0, 2 * n + 1) + cnt + n - 1);
	}
	cout << res;
}