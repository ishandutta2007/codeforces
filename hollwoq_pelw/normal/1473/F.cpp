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

const int N = 3005;

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

int n, a[N], b[N], res;

void Hollwo_Pelw() {
	cin >> n;
	Dinic dinic(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) res += max(0, b[i]);
	for (int i = 1; i <= n; i++) {
		set<int> chk;
		for (int j = i - 1; j; j--) {
			if (!chk.count(a[j]) && a[i] % a[j] == 0)
				dinic.add_edge(i, j), chk.insert(a[j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (b[i] > 0)
			dinic.add_edge(0, i, b[i]);
		if (b[i] < 0)
			dinic.add_edge(i, n + 1, -b[i]);
	}
	cout << res - dinic.maxflow(0, n + 1);
}