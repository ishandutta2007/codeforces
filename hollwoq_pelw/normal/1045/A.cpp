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

const int N = 5e4 + 5, M = 5005;


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
} mf;

int n, m, nd[M], v[M], rev[N], nnode = M << 2;

#define tm (tl + tr >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

void build(int id = 1, int tl = 1, int tr = m) {
	if (tl == tr) {
		nd[tl] = id, rev[id] = tl;
	} else {
		build(left), build(right);
		mf.add_edge(id, id << 1);
		mf.add_edge(id, id << 1 | 1);
	}
}

void add_beam(int l, int r, int v, int id = 1, int tl = 1, int tr = m) {
	if (l > tr || tl > r) return ;
	if (l <= tl && tr <= r) 
		return mf.add_edge(v, id, 1);
	add_beam(l, r, v, left), add_beam(l, r, v, right);
}

vector<pair<int, int>> adj[N];
map<int, int> weapon;
vector<int> sp_ship;

int dfs(int u) {
	if (weapon.count(u) && weapon[u] > 0)
		return weapon[u] --, u;
	for (auto &vw : adj[u]) {
		int v = vw.first, w = vw.second;
		if (w) {
			int x = dfs(v);
			if (~x) {
				vw.second --;
				return x;
			}
		}
	}
	return -1;
}

int need[N], tobaz[N];

void Hollwo_Pelw() {
	cin >> n >> m, build();
	for (int i = 1, tp, x, y; i <= n; i++) {
		cin >> tp, v[i] = ++ nnode;
		rev[nnode] = i;
		
		if (tp == 0) {
			// add rocket
			mf.add_edge(0, v[i], 1);
			for (cin >> x; x --; )
				cin >> y, mf.add_edge(v[i], nd[y], 1);
		}
		if (tp == 1) {
			// add beam
			mf.add_edge(0, v[i], 1);
			cin >> x >> y, add_beam(x, y, v[i]);
		}
		if (tp == 2) {
			// add bazooka
			mf.add_edge(0, v[i], 2);
			for (x = 3; x --; ) {
				cin >> y, tobaz[y] = i;
				mf.add_edge(v[i], nd[y], 1);
			}
		}
	}
	++ nnode;
	for (int i = 1; i <= m; i++)
		mf.add_edge(nd[i], nnode, 1);
	cout << mf.maxflow(0, nnode) << '\n';


	for (auto ed : mf.edges) if (ed.f > 0) {
		if (ed.v == nnode) {
			sp_ship.push_back(ed.u);
		}
		else if (ed.u == 0) {
			weapon[ed.v] = ed.f;
			int id = rev[ed.v];
			if (ed.f == 1 && ed.c == 2)
				need[id] = 1;
		}
		else {
			adj[ed.v].emplace_back(ed.u, ed.f);
		}
	}

	for (auto v : sp_ship) {
		int wp = rev[dfs(v)], sp = rev[v];
		if (tobaz[sp] && need[tobaz[sp]] && wp != tobaz[sp]) {
			wp = tobaz[sp], need[wp] = 0;
		}
		cout << wp << ' ' << sp << '\n';
	}
}