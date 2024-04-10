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

int n, a[N], b[N], res;
set<int> st[N];
vector<int> adj[N];

void pre_dfs(int u, int p) {
	b[u] ^= a[u];
	for (int v : adj[u]) if (v != p) {
		b[v] = b[u], pre_dfs(v, u);
	}
}

void solve(int u, int p) {
	st[u].insert(b[u]);
	for (int v : adj[u]) if (v != p) {
		solve(v, u);
	}
	for (int v : adj[u]) if (v != p) {
		if (st[v].size() > st[u].size())
			swap(st[u], st[v]);
		for (int x : st[v])
			if (st[u].count(x ^ a[u]))
				return ++ res, st[u].clear();
		for (int x : st[v])
			st[u].insert(x);
	}
}

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	pre_dfs(1, 0), solve(1, 0);
	cout << res << '\n';
}