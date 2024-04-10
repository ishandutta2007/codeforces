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

#define int long long

const int N = 2e5 + 5;

int n, k, p[N], s[N], f[N];
vector<int> adj[N];

void pre_dfs(int u) {
	for (int v : adj[u])
		s[v] += s[u], pre_dfs(v);
}

map<int, int> dp[N];

int solve(int u, int k) {
	if (dp[u].count(k))
		return dp[u][k];
	if (adj[u].empty())
		return dp[u][k] = k * s[u];

	int res = 0, f = k % adj[u].size(), g = k / adj[u].size();
	vector<int> vv;

	for (int v : adj[u]) {
		res += solve(v, g);
		if (f) vv.push_back(solve(v, g + 1) - solve(v, g));
	}

	sort(vv.rbegin(), vv.rend());

	for (int i = 0; i < f; i++)
		res += vv[i];

	return dp[u][k] = res;
}

void Hollwo_Pelw(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		adj[i].clear(), dp[i].clear();
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		adj[p[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	pre_dfs(1);
	cout << solve(1, k) << '\n';
}