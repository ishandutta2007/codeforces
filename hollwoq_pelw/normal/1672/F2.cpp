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

int n, a[N], b[N], deg[N], vis[N], cyc;
vector<int> adj[N];

void dfs(int u) {
	vis[u] = 1;
	for (int v : adj[u]) {
		if (vis[v]) {
			cyc |= vis[v] == 1;
		} else {
			dfs(v);
		}

	}
	vis[u] = 2;
}

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		adj[i].clear();
	fill(vis + 1, vis + n + 1, 0);
	fill(deg + 1, deg + n + 1, 0);
	
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	for (int i = 1; i <= n; i++)
		adj[a[i]].push_back(b[i]), deg[a[i]] ++;

	int rt = max_element(deg + 1, deg + n + 1) - deg;

	vis[rt] = 2, cyc = 0;
	for (int i = 1; i <= n; i++)
		if (!vis[i]) dfs(i);

	cout << (cyc ? "WA\n" : "AC\n");
}