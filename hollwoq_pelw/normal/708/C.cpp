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

const int N = 4e5 + 5;

int sz[N], n, ans[N];
vector<int> adj[N];

int dfs_sz(int u, int p) {
	sz[u] = 1;
	for (auto v : adj[u])
		if (v != p) sz[u] += dfs_sz(v, u);
	return sz[u];
}

int find_cen(int u, int p) {
	for (auto v : adj[u]) if (v != p) {
		if (sz[v] > n / 2) return find_cen(v, u);
	}
	return u;
}

vector<pair<int, int>> sub;

void dfs(int u, int p, int tot, int prv) {
	if (tot <= n / 2)
		ans[u] = 1; 
	for (int i = 0; i < sub.size(); i++) {
		if (sub[i].second == prv) continue ;
		if (n - sz[u] - sub[i].first <= n / 2) 
			ans[u] = 1;
	}
	for (auto v : adj[u])
		if (v != p) dfs(v, u, tot, prv);
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	if (n == 2)
		return cout << "1 1", (void) 0;
	dfs_sz(1, 1);
	int r = find_cen(1, 1);
	ans[r] = 1;
	dfs_sz(r, r);
	for (auto v : adj[r])
		sub.emplace_back(sz[v], v);
	sort(sub.rbegin(), sub.rend());
	sub.resize(2);
	for (auto v : adj[r])
		dfs(v, r, n - sz[v], v);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
}