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

const int N = 3e5 + 5;

int n, a[N], res[N], tot;
vector<int> adj[N], g[N];

void pre_dfs(int u, int p) {
	for (int v : adj[u]) if (v != p) {
		pre_dfs(v, u);
		a[u] += a[v];

		if (a[v] >= 2)
			g[v].push_back(u);
		if (tot - a[v] >= 2)
			g[u].push_back(v);
	}
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], tot += a[i];
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) if (a[i]) {
		res[i] = 1;
		for (auto v : adj[i]) res[v] = 1;
	}

	pre_dfs(1, 0);

	queue<int> q;

	for (int i = 1; i <= n; i++)
		if (res[i]) q.push(i);
	
	while (!q.empty()) {
		int u = q.front(); q.pop();

		for (auto v : g[u])
			if (!res[v]) res[v] = 1, q.push(v);
	}

	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
}