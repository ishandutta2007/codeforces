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

const int N = 105;

bool f[N][N][N], vis[N];
int n, d[N][N];
vector<pair<int, int>> res;
vector<int> adj[N];

void build(int u, int p) {
	vis[u] = 1;
	for (int v = 0; v < n; v++)
		if (!vis[v] && f[u][v][p]) {
			adj[u].push_back(v);
			adj[v].push_back(u);
			res.emplace_back(u, v);

			build(v, u);
		}
}

void dfs(int u, int p, int h, int *d) {
	d[u] = h;
	for (int v : adj[u])
		if (v != p) dfs(v, u, h + 1, d);
}

bool check(int u, int v) {
	for (int i = 0; i < n; i++)
		adj[i].clear();
	res.clear();

	fill(vis, vis + n, 0);
	build(u, v);

	for (int i = 0; i < n; i++)
		if (!vis[i]) return 0;

	for (int i = 0; i < n; i++)
		dfs(i, -1, 0, d[i]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < j; k++)
				if ((d[i][j] == d[i][k]) != f[i][j][k])
					return 0;
	return 1;
}

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			string s; cin >> s;
			for (int k = 0; k < n; k++)
				f[k][i][j] = f[k][j][i] = s[k] & 1;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			f[i][j][j] = 1;

	for (int x = 1; x < n; x++)
		if (check(0, x)) {
			cout << "Yes\n";
			assert((int) res.size() == n - 1);
			for (auto [u, v] : res)
				cout << u + 1 << ' ' << v + 1 << '\n';
			return ;
		}
	cout << "No\n";
}