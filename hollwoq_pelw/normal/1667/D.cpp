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
	if (fopen("hollwo_pelw.inp", "r"))
		assert(freopen("hollwo_pelw.inp", "r", stdin)), assert(freopen("hollwo_pelw.out", "w", stdout));
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
	cout << "\nExcution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 2e5 + 5;

int n, fail, col[N];
vector<int> adj[N];

void pre_dfs(int u, int p) {
	vector<int> cnt(2, 0);
	for (int v : adj[u]) if (v != p) {
		pre_dfs(v, u);
		cnt[col[v]] ++;
	}
	if (p) cnt[col[u] = cnt[0] >= cnt[1]] ++;
	fail |= (cnt[0] > cnt[1] || cnt[0] + 1 < cnt[1]);
}

void solve(int u, int p) {
	vector<int> f[2];
	for (int v : adj[u]) {
		int x = v == p ? u : v;
		f[col[x]].push_back(x);
	}
	for (int i = adj[u].size(); i; i --) {
		int x = f[i & 1].back(); f[i & 1].pop_back();
		if (x == u)
			cout << u << ' ' << p << '\n';
		else
			solve(x, u);
	}
}

void Hollwo_Pelw(){
	cin >> n, fail = 0;
	for (int i = 1; i <= n; i++) adj[i].clear();
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);

	pre_dfs(1, 0);

	if (fail) return cout << "NO\n", (void) 0;
	cout << "YES\n";
	solve(1, 0);
}