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
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 1e5 + 5;
// dfs tree => back edge => depth ??
int n, m, rt, d[N], par[N], vis[N], ok[N], path[N];
vector<int> adj[N];

void dfs(int u, int p = 0) {
	d[u] = d[par[u] = p] + 1, vis[u] = 1;
	path[d[u]] = u;

	for (auto v : adj[u]) {
		if (vis[v]) {
			if (d[u] - d[v] + 1 >= rt) {
				cout << "2\n" << d[u] - d[v] + 1 << '\n';
				for (int i = d[v]; i <= d[u]; i++)
					cout << path[i] << ' ';
				exit(0);
			}
		} else {
			dfs(v, u);
		}
	}

	if (!ok[u]) {
		for (auto v : adj[u])
			ok[v] = 1;
	}
}

void Hollwo_Pelw() {
	cin >> n >> m, rt = ceil(sqrt(n));
	for (int u, v; m --; )
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	dfs(1), cout << "1\n";
	for (int i = 1; i <= n && rt; i++)
		if (!ok[i]) rt --, cout << i << ' ';
}