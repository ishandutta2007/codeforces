#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

signed main(){
#ifndef hollwo_pelw_local
	if (fopen(".inp", "r"))
		assert(freopen(".inp", "r", stdin)), assert(freopen(".out", "w", stdout));
#else
	using namespace chrono;
	auto start = steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExecution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 2e5 + 5;

int n, m, dp[N], deg[N];
vector<int> adj[N], rev[N];

void Hollwo_Pelw(){
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		deg[u] ++;
		adj[u].push_back(v);
		rev[v].push_back(u);
	}

	memset(dp, 0x3f, sizeof dp);

	priority_queue<pair<int, int>> pq;
	pq.emplace(- (dp[n] = 0), n);

	while (!pq.empty()) {
		auto [f, u] = pq.top(); pq.pop();

		if (-f != dp[u]) continue;

		for (int v : rev[u]) {
			if (dp[v] > dp[u] + deg[v])
				pq.emplace(- (dp[v] = dp[u] + deg[v]), v);
			deg[v] --;
		}

	}

	cout << dp[1] << '\n';
}