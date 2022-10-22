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

int n, m, k, a[N], b[N];

int dp[N], cnt[N], sz[N], tot, mx, mid;
vector<int> adj[N];

void pre_dfs(int u, int p) {
	sz[u] = 1;
	for (auto v : adj[u]) if (v != p)
		pre_dfs(v, u), sz[u] += sz[v];
}

void dfs_cnt(int u, int p) {
	cnt[u] = a[u] >= b[mid];
	for (auto v : adj[u]) if (v != p) 
		dfs_cnt(v, u), cnt[u] += cnt[v];
}

void dfs(int u, int p) {
	dp[u] = a[u] >= b[mid];

	int mx1 = 0, mx2 = 0;
	for (auto v : adj[u]) if (v != p) {
		dfs(v, u);
		// if full (can go back)
		if (sz[v] == dp[v]) {
			dp[u] += dp[v];
		}
		else if (dp[v]) {
			if (mx2 < dp[v]) swap(mx2, dp[v]);
			if (mx1 < mx2) swap(mx1, mx2);
		}
	}
	if (a[u] < b[mid]) return dp[u] = 0, (void) 0;
	mx = max(mx, dp[u] += mx1);
	{
		int cur = dp[u] + mx2;
		if (tot - cnt[u] == n - sz[u]) // parent full
			cur += n - sz[u];
		mx = max(mx, cur);
	}
}

bool check() {
	tot = mx = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = cnt[i] = 0;
		tot += a[i] >= b[mid];
	}
	if (tot < k) return 0;
	dfs_cnt(1, -1), dfs(1, -1);
	return mx >= k;
}

void Hollwo_Pelw() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i], b[i] = a[i];
	
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	pre_dfs(1, -1);
	
	sort(b + 1, b + n + 1);
	m = unique(b + 1, b + n + 1) - b - 1;
	
	int l = 1, r = m, res = 0;
	while (l <= r) {
		mid = l + r >> 1;
		if (check())
			res = b[mid], l = mid + 1;
		else
			r = mid - 1; 
	}
	cout << res;
}