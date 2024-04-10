/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include<bits/stdc++.h>
using namespace std;

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

int n, sz[N], res[N];
long long ans;
vector<int> adj[N], ord;

void dfs_sz(int u, int p) {
	sz[u] = 1;
	for (auto v : adj[u]) if (v != p)
		dfs_sz(v, u), sz[u] += sz[v];
	ans += min(sz[u], n - sz[u]) << 1;
}

int find_cen(int u, int p) {
	for (auto v : adj[u]) if (v != p && sz[v] > n / 2)
		return find_cen(v, u);
	return u;
}

void dfs_ord(int u, int p) {
	ord.push_back(u);
	for (auto v : adj[u]) if (v != p)
		dfs_ord(v, u);
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	
	dfs_sz(1, -1), dfs_ord(find_cen(1, 1), -1);

	for (int i = 0; i < n; i++)
		res[ord[i]] = ord[(i + n / 2) % n];

	cout << ans << '\n';
	for (int i = 1; i <= n; i++)
		cout << res[i] << ' ';
}