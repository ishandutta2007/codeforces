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
	cin >> testcases;
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

const int N = 2e5 + 5;

int n, m, vis[N], ok;
map<pair<int, int>, int> res;
vector<pair<int, int>> adj[N];

void dfs(int u, int c) {
	vis[u] = c;
	for (auto [v, w] : adj[u]) if (w != -1) {
		if (vis[v] == -1) {
			if (w != -1)
				dfs(v, c ^ w);
		} else if ((c ^ w) != vis[v]) {
			ok = 0;
		}
	}
}

void Hollwo_Pelw() {
	cin >> n >> m;
	res.clear(), ok = 1;
	for (int i = 1; i <= n; i++)
		adj[i].clear(), vis[i] = -1;

	for (int i = 1, x, y, v; i < n; i++) {
		cin >> x >> y >> v;
		res[{x, y}] = v;
		if (v != -1) {
			v = __builtin_popcount(v);
			adj[x].emplace_back(y, v & 1);
			adj[y].emplace_back(x, v & 1);
		}

	}
	for (int i = 1, x, y, v; i <= m; i++) {
		cin >> x >> y >> v;
		adj[x].emplace_back(y, v);
		adj[y].emplace_back(x, v);
	}

	for (int i = 1; i <= n; i++)
		if (vis[i] == -1) dfs(i, 0);

	if (ok) {
		cout << "YES\n";
		for (auto [v, p] : res) {
			if (p == -1)
				p = vis[v.first] ^ vis[v.second];
			cout << v.first << ' ' << v.second << ' ' << p << '\n';
		}
	} else {
		cout << "NO\n";
	}
}