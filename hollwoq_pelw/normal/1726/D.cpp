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

const int N = 2e5 + 15;

int n, m, vis[N], col[N], par[N], h[N];
pair<int, int> ed[N];
vector<pair<int, int>> adj[N];

void pre_dfs(int u, int p) {
	vis[u] = 1;
	h[u] = h[p] + 1;
	par[u] = p;
	for (auto [v, i] : adj[u]) if (v != p) {
		if (vis[v]) {
			col[i] = 1;
		} else {
			col[i] = 0;
			pre_dfs(v, u);
		}
	}
}

void Hollwo_Pelw(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		adj[i].clear();
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		ed[i] = {u, v};
		adj[u].emplace_back(v, i);
		adj[v].emplace_back(u, i);
	}
	fill(vis + 1, vis + n + 1, 0);
	pre_dfs(1, 0);

	if (m == n + 2) {
		vector<int> spe;

		for (int i = 1; i <= m; i++)
			if (col[i] == 1)
				spe.push_back(i);

		map<int, int> cnt;
		for (int i : spe)
			cnt[ed[i].first] ++, cnt[ed[i].second] ++;
		int f = 0;
		for (auto [i, j] : cnt) {
			if (h[i] > h[f]) f = i;
			if (j != 2) {
				for (int i = 1; i <= m; i++)
					cout << col[i];
				cout << '\n';
				return ;
			}
		}

		for (auto [v, i] : adj[f])
			if (v == par[f]) {
				col[i] = 1;
			}
		for (auto [v, i] : adj[f]) {
			if (col[i] == 1 && v != par[f]) {
				col[i] = 0; break;
			}
		}
	}

	for (int i = 1; i <= m; i++)
		cout << col[i];
	cout << '\n';
}