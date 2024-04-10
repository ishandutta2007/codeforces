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

const int N = 1e5 + 5;

#define int long long

int n, q, a[N], tin[N], tout[N], timer, bit[N], par[18][N];
vector<int> adj[N];

inline void add(int p, int x) {
	for (; p < N; p += p & -p)
		bit[p] += x;
}

inline void add(int l, int r, int x) {
	add(l, x), add(r + 1, -x);
}

inline int query(int p) {
	int r = 0;
	for (p = tin[p]; p; p -= p & -p)
		r += bit[p];
	return r;
}

void dfs(int u, int p) {
	par[0][u] = p;
	for (int i = 1; i < 18; i++)
		par[i][u] = par[i - 1][par[i - 1][u]];

	tin[u] = ++ timer;
	for (auto v : adj[u]) 
		if (v != p) dfs(v, u);
	tout[u] = timer;

	add(tin[u], tout[u], a[u]);
}

inline bool is_ancestor(int u, int v) {
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

inline int lca(int u, int v) {
	if (is_ancestor(u, v)) return u;
	if (is_ancestor(v, u)) return v;
	for (int i = 17; ~i; i--)
		if (!is_ancestor(par[i][u], v))
			u = par[i][u];
	return par[0][u];
}

void Hollwo_Pelw() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i], a[i] = abs(a[i]);
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	tin[0] = timer, dfs(1, 0), tout[0] = timer;

	for (int t, u, v; q --; ) {
		cin >> t >> u >> v;
		if (t == 1) {
			add(tin[u], tout[u], - a[u]);
			add(tin[u], tout[u], a[u] = abs(v));
		} else {
			int w = lca(u, v);
			cout << ((query(u) + query(v) - query(w) - query(par[0][w])) * 2 - a[u] - a[v]) << '\n';
		}
	}
}