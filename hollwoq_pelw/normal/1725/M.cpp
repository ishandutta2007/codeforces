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

#define int long long

const int N = 1e5 + 5, inf = 1e18;

int n, m, d[N];
vector<pair<int, int>> adj1[N], adj2[N];
priority_queue<pair<int, int>> pq;

void Hollwo_Pelw(){
	cin >> n >> m;
	for (int u, v, w; m --; ) {
		cin >> u >> v >> w;
		adj1[u].emplace_back(v, w);
		adj2[v].emplace_back(u, w);
	}
	fill(d + 1, d + n + 1, inf);
	pq.emplace(d[1] = 0, 1);

	while (!pq.empty()) {
		int D = -pq.top().first, u = pq.top().second; pq.pop();

		if (D != d[u]) continue;
		for (auto [v, w] : adj1[u])
			if (D + w < d[v])
				pq.emplace(- (d[v] = D + w), v);
	}

	for (int i = 1; i <= n; i++)
		if (d[i] != inf) pq.emplace(- d[i], i);

	while (!pq.empty()) {
		int D = -pq.top().first, u = pq.top().second; pq.pop();

		if (D != d[u]) continue;
		for (auto [v, w] : adj2[u])
			if (D + w < d[v])
				pq.emplace(- (d[v] = D + w), v);
	}

	for (int i = 2; i <= n; i++)
		cout << (d[i] == inf ? -1 : d[i]) << ' ';
}