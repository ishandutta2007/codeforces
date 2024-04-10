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
	cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExecution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

int n, adj[20], par[20];
bool dp[1 << 20];
string a, b;

inline int find(int u) { return par[u] == -1 ? u : par[u] = find(par[u]); }
inline bool merge(int u, int v) {
	if ((u = find(u)) == (v = find(v)))
		return 0;
	return par[v] = u, 1;
}

void Hollwo_Pelw(){
	memset(adj, 0, sizeof adj);
	memset(dp, 0, sizeof dp);
	memset(par, -1, sizeof par);
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++)
		if (a[i] != b[i])
			adj[a[i] - 'a'] |= 1 << (b[i] - 'a');

	int res = 0, comp = 20;

	for (int i = 0; i < n; i++)
		comp -= merge(a[i] - 'a', b[i] - 'a');

	dp[0] = 1;

	for (int mask = 0; mask < 1 << 20; mask++) if (dp[mask]) {
		res = max(res, __builtin_popcount(mask));
		for (int u = 0; u < 20; u++)
			if ((~mask >> u & 1) && (adj[u] & mask) == 0)
				dp[mask | 1 << u] = 1;
	}

	cout << 2 * 20 - comp - res << '\n';
}