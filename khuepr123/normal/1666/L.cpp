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
	if (fopen("L.inp", "r"))
		assert(freopen("L.inp", "r", stdin)), assert(freopen("L.out", "w", stdout));
#else
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
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
}

const int N = 2e5 + 5;

int n, m, s, par[N], vis[N], c;
vector<int> adj[N], path;

void dfs(int u) {
	par[u] = path.back();
	vis[u] = c;
	path.push_back(u);

	for (int v : adj[u]) {
		if (vis[v] && vis[v] != c) {
			cout << "Possible\n";
			cout << path.size() + 1 << '\n';
			for (int x : path)
				cout << x << ' ';
			cout << v << '\n';

			vector<int> p1;
			while (v > 0)
				p1.push_back(v), v = par[v];
			reverse(p1.begin(), p1.end());

			cout << p1.size() << '\n';
			for (int x : p1)
				cout << x << ' ';
			cout << '\n';
			exit(0);

		} else if (vis[v] == 0) {
			dfs(v);
		}
	}

	path.pop_back();
}

void Hollwo_Pelw(){
	cin >> n >> m >> s;
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		if (v != s) adj[u].push_back(v);
	}

	path.push_back(s);
	for (int v : adj[s]) {
		++ c;
		if (vis[v] && vis[v] != c) {

			cout << "Possible\n";
			cout << path.size() + 1 << '\n';
			for (int x : path)
				cout << x << ' ';
			cout << v << '\n';

			vector<int> p1;
			while (v > 0)
				p1.push_back(v), v = par[v];
			reverse(p1.begin(), p1.end());

			cout << p1.size() << '\n';
			for (int x : p1)
				cout << x << ' ';
			cout << '\n';
			exit(0);

		}

		dfs(v);
	}

	cout << "Impossible";
}