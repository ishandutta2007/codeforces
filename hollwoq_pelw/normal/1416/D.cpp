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
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 2e5 + 5, M = 3e5 + 5, Q = 5e5 + 5;

int par[N + M], deg[N + M], root;
vector<int> adj[N + M];

struct disjoint_set {
	disjoint_set() {
		iota(par, par + N + M, 0);
	}
	inline int find(int u) {
		return par[u] = par[u] == u ? u : find(par[u]);
	}

	inline void merge(int u, int v) {
		if ((u = find(u)) == (v = find(v)))
			return ;
		deg[u] ++, deg[v] ++;
		int p = ++ root; par[u] = par[v] = p;
		adj[p].push_back(u), adj[p].push_back(v);
	}
} dsu;

#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

pair<int, int> ed[M], qry[Q], st[N + M << 2];

void update(int p, int u, int val, int id = 1, int tl = 1, int tr = root) {
	if (tl == tr) {
		st[id] = {val, u};
	} else {
		int tm = tl + tr >> 1;
		(p > tm ? update(p, u, val, right)
				: update(p, u, val, left));
		st[id] = max(st[id << 1], st[id << 1 | 1]);
	}
}

pair<int, int> query(int l, int r, int id = 1, int tl = 1, int tr = root) {
	if (l > tr || tl > r) return {-1e9, -1e9};
	if (l <= tl && tr <= r) return st[id];
	int tm = tl + tr >> 1;
	return max(query(l, r, left), query(l, r, right));
}

int n, m, q, p[N], rt[Q];
int timer, tin[N + M], tout[N + M];

inline void do_update(int u, int val) {
	update(tin[u], u, val);
}

void dfs(int u) {
	tin[u] = ++ timer;
	for (auto v : adj[u])
		dfs(v);
	tout[u] = timer;
}

void Hollwo_Pelw() {
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) cin >> p[i];

	set<int> edges;
	for (int i = 1, u, v; i <= m; i++)
		cin >> u >> v, ed[i] = {u, v}, edges.insert(i);

	for (int i = 1, t, v; i <= q; i++) {
		cin >> t >> v, qry[i] = {t, v};
		if (t == 2) edges.erase(v);
	}

	root = n;
	for (auto v : edges)
		dsu.merge(ed[v].first, ed[v].second);

	for (int _ = q; _; _--) {
		int t = qry[_].first, v = qry[_].second;
		if (t == 2)
			dsu.merge(ed[v].first, ed[v].second);
		else
			rt[_] = dsu.find(v);
	}

	for (int i = 1; i <= root; i++) if (!deg[i]) dfs(i);

	for (int i = 1; i <= n; i++) do_update(i, p[i]);

	for (int i = 1; i <= q; i++) if (rt[i]) {
		pair<int, int> res = query(tin[rt[i]], tout[rt[i]]);
		cout << res.first << '\n', do_update(res.second, 0);
	}
}