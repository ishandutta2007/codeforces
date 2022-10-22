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

const int N = 2e5 + 5;

vector<int> adj[N], stop[N];

int n, m, q;
int tin[N], tout[N], h[N], timer;

int par[19][N];
int low[19][N];

void __predfs_lca__(int u) {
	for (int i = 1; i <= 18; i++)
		par[i][u] = par[i - 1][par[i - 1][u]];

	tin[u] = ++ timer;
	for (int v : adj[u]) {
		h[v] = h[u] + 1;
		par[0][v] = u;
		__predfs_lca__(v);
	}
	tout[u] = timer;
}

inline int lca(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	for (int i = 18; ~i; i--)
		if (h[v] - h[u] >> i & 1)
			v = par[i][v];
	if (u == v) return u;
	for (int i = 18; ~i; i--)
		if (par[i][u] ^ par[i][v]) {
			u = par[i][u];
			v = par[i][v];
		}
	return par[0][u];
}

inline void chklow(int &u, int v) { u = h[u] < h[v] ? u : v; }

void __calc_low__(int u) {
	for (int v : adj[u]) {
		__calc_low__(v);
		chklow(low[0][u], low[0][v]);
	}
}

void __predfs_low__(int u) {
	for (int i = 1; i <= 18; i++)
		low[i][u] = low[i - 1][low[i - 1][u]];

	for (int v : adj[u])
		__predfs_low__(v);
}

pair<int, int> lift(int u, int w) {
	int cnt = 0;
	for (int i = 18; ~i; i--)
		if (h[low[i][u]] > h[w]) {
			cnt |= 1 << i;
			u = low[i][u];
		}
	return {u, cnt};
}

struct query_t {
	int v, id;
	query_t (int _v = 0, int _id = 0)
		: v(_v), id(_id) {}
};
vector<query_t> query[N];

struct fenwick_tree {
	int bit[N];
	inline void add(int p, int v) {
		for (; p < N; p += p & -p)
			bit[p] += v;
	}
	inline int query(int p) {
		int r = 0;
		for (; p > 0; p -= p & -p)
			r += bit[p];
		return r;
	}
	inline int query(int l, int r) {
		return query(r) - query(l - 1);
	}
} bit;

int res[N], cnt_ways[N];

void __solve__(int u) {
	for (auto [v, id] : query[u])
		cnt_ways[id] -= bit.query(tin[v], tout[v]);

	for (int v : stop[u]) bit.add(tin[v], 1);

	for (int v : adj[u])
		__solve__(v);

	for (auto [v, id] : query[u]) {
		cnt_ways[id] += bit.query(tin[v], tout[v]);

		if (cnt_ways[id] > 0) res[id] --; // have route between (u, v)
	}
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 2, p; i <= n; i++)
		cin >> p, adj[p].push_back(i);

	__predfs_lca__(1);

	iota(low[0] + 1, low[0] + n + 1, 1);

	cin >> m;
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		stop[u].push_back(v);
		stop[v].push_back(u);

		int w = lca(u, v);
		chklow(low[0][u], w);
		chklow(low[0][v], w);
	}

	__calc_low__(1);
	__predfs_low__(1);

	cin >> q;
	for (int i = 1, u, v; i <= q; i++) {
		cin >> u >> v;
		int w = lca(u, v);
		if (h[low[18][u]] > h[w] || h[low[18][v]] > h[w]) {
			res[i] = -1; continue ;
		}

		auto [nu, len_u] = lift(u, w);
		auto [nv, len_v] = lift(v, w);

		res[i] = len_u + len_v;
		if (nu != w) res[i] ++;
		if (nv != w) res[i] ++;

		if (nu != w && nv != w) {
			// if have route(nu, nv) res[i] --;
			query[nu].emplace_back(nv, i);
		}
	}

	__solve__(1);

	for (int i = 1; i <= q; i++) {
		cout << res[i] << '\n';
	}
}