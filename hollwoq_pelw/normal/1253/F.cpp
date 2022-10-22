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
	FAST_IO("1253F.inp", "1253F.out");
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

const int N = 1e5 + 5;

const int64_t inf = 1e18;

int n, m, k, q, vis[N], par[N];
vector<pair<int, int>> g[N];

struct dist_t {
	int u; int64_t d;
	dist_t (int _u = 0, int64_t _d = 0)
		: u(_u), d(_d) {}
	bool operator < (const dist_t &o) const {
		return d > o.d;
	}
};

struct edge {
	int u, v; int64_t w;
	edge (int _u = 0, int _v = 0, int64_t _w = 0)
		: u(_u), v(_v), w(_w) {}
	bool operator < (const edge &o) const {
		return w < o.w;
	}
};

vector<edge> edges;
priority_queue<dist_t> pq;

int64_t res[N * 3], dist[N];

set<int> curq[N];

inline int find(int u) {
	return par[u] = par[u] == u ? u : find(par[u]);
}

void Hollwo_Pelw() {
	cin >> n >> m >> k >> q;
	for (int i = 1, u, v, w; i <= m; i++)
		cin >> u >> v >> w, g[u].emplace_back(v, w), g[v].emplace_back(u, w);
	
	fill(dist + 1, dist + n + 1, inf);
	for (int i = 1; i <= k; i++)
		pq.emplace(i, dist[i] = 0);
	
	while (!pq.empty()) {
		int u = pq.top().u; int64_t d = pq.top().d; pq.pop();
		if (dist[u] != d) continue ;
		for (auto vw : g[u]) {
			int v = vw.first, w = vw.second;
			if (dist[v] > d + w) 
				pq.emplace(v, dist[v] = d + w);
		}
	}

	for (int i = 1; i <= n; i++)
		for (auto vw : g[i]) if (vw.first < i)
			edges.emplace_back(vw.first, i, vw.second + dist[i] + dist[vw.first]);

	sort(edges.begin(), edges.end());

	iota(par + 1, par + n + 1, 1);

	for (int i = 1, a, b; i <= q; i++) {
		cin >> a >> b;
		curq[a].insert(i);
		curq[b].insert(i);
	}

	for (auto ed : edges) {
		// cout << ed.u << ' ' << ed.v << ' ' << ed.w << '\n';
		int u = find(ed.u), v = find(ed.v);
		if (u == v) continue ;
		if (curq[u].size() < curq[v].size()) swap(u, v);
		for (auto id : curq[v]) {
			if (curq[u].count(id)) {
				curq[u].erase(id);
				res[id] = ed.w;
			} else {
				curq[u].insert(id);
			}
		}
		par[v] = u;
	}

	for (int i = 1; i <= q; i++)
		cout << res[i] << "\n";
}