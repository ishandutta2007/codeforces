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

int tmp[10];

int join(int *res, int *a, int n, int* b, int m, int lim = 10){
	int i = 0, j = 0, k = 0;
	while (i < n && j < m) {
		tmp[k ++] = a[i] < b[j] ? a[i ++] : b[j ++];
		if (k == lim) break ;
	}
	while (i < n && k < lim) tmp[k ++] = a[i ++];
	while (j < m && k < lim) tmp[k ++] = b[j ++];

	for (int i = 0; i < k; i++)
		res[i] = tmp[i];

	return k;
}

int n, m, q, par[N][17], d[N];
vector<int> adj[N];

int city[N][17][10], csz[N][17], res[10];

void build_lca(int u, int p = 0){
	for (int i = 1; i < 17; i++){
		int v = par[u][i - 1]; par[u][i] = par[v][i - 1];
		csz[u][i] = join(city[u][i], city[u][i - 1], csz[u][i - 1], city[v][i - 1], csz[v][i - 1]);
	}
	for (auto v : adj[u]) if (v != p)
		par[v][0] = u, d[v] = d[u] + 1, build_lca(v, u);
}

int query(int u, int v, int a){
	if (d[u] > d[v]) swap(u, v);
	int sz = 0;
	for (int i = 16; i >= 0; i--) {
		if (d[v] - d[u] >> i & 1) {
			sz = join(res, res, sz, city[v][i], csz[v][i], a);
			v = par[v][i];
		}
	}
	if (u == v) 
		return sz = join(res, res, sz, city[u][0], csz[u][0], a);
	
	for (int i = 16; i >= 0; i--){
		if (par[u][i] != par[v][i]){
			sz = join(res, res, sz, city[u][i], csz[u][i], a);
			sz = join(res, res, sz, city[v][i], csz[v][i], a);
			u = par[u][i], v = par[v][i];
		}
	}
	if (par[u][0] == par[v][0]) {
		sz = join(res, res, sz, city[u][0], csz[u][0], a); 
		sz = join(res, res, sz, city[v][0], csz[v][0], a);
		u = par[u][0], v = par[v][0];
	}
	return sz = join(res, res, sz, city[u][0], csz[u][0], a);
}

void Hollwo_Pelw() {
	cin >> n >> m >> q;
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	for (int i = 1, c; i <= m; i++){
		cin >> c;
		if (csz[c][0] < 10)
			city[c][0][csz[c][0] ++] = i;
	}
	build_lca(1);
	for(int u, v, a; q--; ) {
		cin >> u >> v >> a;
		int sz = query(u, v, a);
		if (sz > a) sz = a;
		cout << sz << ' ';
		for (int i = 0; i < sz; i++) 
			cout << res[i] << ' ';
		cout << "\n";
	}
}