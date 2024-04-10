/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include <bits/stdc++.h>
// #include <ext/push_back_ds/assoc_container.hpp>
// #include <ext/push_back_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_push_backds;
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

const int N = 5e4 + 5;

int n, k, sz[N];
vector<int> adj[N];

bool mark[N];

int dfs_sz(int u, int p){
	sz[u] = 1;
	for (int v : adj[u]) if (v != p && !mark[v])
		sz[u] += dfs_sz(v, u);
	return sz[u];
}

int find_cen(int u, int p, int tot){
	for (int v : adj[u]) if (v != p && !mark[v])
		if (sz[v] > tot / 2) return find_cen(v, u, tot);
	return u;
}

int dep[N], cnt[505];
long long res;

void dfs(int u, int p, int h = 0){
	dep[u] = h;
	if (dep[u] <= k) cnt[dep[u]] ++;
	for (int v : adj[u]) if (v != p && !mark[v])
		dfs(v, u, h + 1);
}

void dfs_sub(int u, int p) {
	if (dep[u] <= k) cnt[dep[u]] --;
	for (int v : adj[u]) if (v != p && !mark[v])
		dfs_sub(v, u);
}

void calc_sub(int u, int p){
	if (dep[u] <= k) res += cnt[k - dep[u]];
	for (int v : adj[u]) if (v != p && !mark[v])
		calc_sub(v, u);
}

void centroid_decomp(int r) {
	int tot = dfs_sz(r, r);
	r = find_cen(r, r, tot);

	dfs(r, r);
	for (int v : adj[r]) if (!mark[v])
		dfs_sub(v, r), calc_sub(v, r);

	cnt[0] = 0;
	mark[r] = 1;
	for (int v : adj[r])
		if (!mark[v]) centroid_decomp(v);
}

void Hollwo_Pelw() {
	cin >> n >> k;
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	centroid_decomp(1);
	cout << res;
}