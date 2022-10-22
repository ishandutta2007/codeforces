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

int n, q, root;
int64_t dist[N], h1[N], h2[N], lim;
vector<pair<int, int>> adj[N];

void pre_dfs(int u, int p, int64_t * h) {
	for (auto [v, w] : adj[u])
		if (v != p) {
			h[v] = h[u] + w;
			pre_dfs(v, u, h);
		}
}

inline void calc_dist() {
	pre_dfs(1, 0, h1);
	int r1 = max_element(h1 + 1, h1 + n + 1) - h1;
	h1[r1] = 0, pre_dfs(r1, 0, h1);
	int r2 = max_element(h1 + 1, h1 + n + 1) - h1;
	h2[r2] = 0, pre_dfs(r2, 0, h2);

	for (int i = 1; i <= n; i++)
		dist[i] = max(h1[i], h2[i]);
	root = min_element(dist + 1, dist + n + 1) - dist;
}

pair<int64_t, int> path[N];
int top, dp[N];

void solve(int u, int p) {
	path[++ top] = {dist[u], u};

	dp[prev(lower_bound(path, path + top + 1, make_pair(dist[u] - lim, 0))) -> second] --;
	dp[u] ++;

	for (auto [v, w] : adj[u]) if (v != p) {
		solve(v, u);
		dp[u] += dp[v];
	}

	top --;
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, u, v, w; i < n; i++) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	calc_dist();

	path[0] = {- 1e18, 0};

	for (cin >> q; q --; ) {
		memset(dp, 0, sizeof dp);
		
		cin >> lim;
		solve(root, 0);

		cout << *max_element(dp + 1, dp + n + 1) << '\n';
	}

}