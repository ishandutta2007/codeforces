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

const int N = 1e5 + 5;

int n, q, sz[N], d[N], par[18][N];
vector<int> adj[N];

void pre_dfs(int u, int p) {
	d[u] = 1 + d[par[0][u] = p];
	for (int i = 1; i < 18; i++)
		par[i][u] = par[i - 1][par[i - 1][u]];

	sz[u] = 1;
	for (int v : adj[u]) if (v != p)
		pre_dfs(v, u), sz[u] += sz[v];
}

inline int lift(int u, int h) {
	for (int i = 17; ~i; i--)
		if (h >> i & 1)
			u = par[i][u];
	return u;
}

inline int lca(int u, int v) {
	if (d[u] > d[v]) swap(u, v);
	v = lift(v, d[v] - d[u]);
	if (u == v) return u;
	for (int i = 17; ~i; i--)
		if (par[i][u] ^ par[i][v])
			u = par[i][u], v = par[i][v];
	return par[0][u];
}

inline int dist(int u, int v) {
	return d[u] + d[v] - 2 * d[lca(u, v)];
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	pre_dfs(1, 0);
	cin >> q;
	for (int u, v; q --; ) {
		cin >> u >> v;
		if (u == v) {
			cout << n << '\n';
		} else {
			int cd = dist(u, v);
			if (cd & 1) {
				cout << 0 << '\n';
			} else {
				cd >>= 1;
				if (d[u] == d[v]) {
					cout << n - sz[lift(u, cd - 1)] - sz[lift(v, cd - 1)] << '\n';
				} else {
					if (d[u] < d[v]) swap(u, v);
					cout << sz[lift(u, cd)] - sz[lift(u, cd - 1)] << '\n';
				}
			}
		}
	}
}