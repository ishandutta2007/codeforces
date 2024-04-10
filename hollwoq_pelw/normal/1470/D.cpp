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

const int N = 3e5 + 5;

int n, m, vis[N], choose[N];
vector<int> adj[N];

void pre_dfs(int u) {
	int c = 0;
	for (int v : adj[u])
		c |= choose[v];
	choose[u] = !c;

	vis[u] = 1;
	for (int v : adj[u])
		if (!vis[v]) pre_dfs(v);
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		adj[i].clear(), vis[i] = choose[i] = 0;
	for (int u, v; m --; )
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	pre_dfs(1);
	if (count(vis + 1, vis + n + 1, 1) != n)
		return cout << "NO\n", (void) 0;
	cout << "YES\n" << count(choose + 1, choose + n + 1, 1) << '\n';
	for (int i = 1; i <= n; i++) if (choose[i]) cout << i << ' '; cout << '\n';
}