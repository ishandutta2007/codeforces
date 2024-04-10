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

vector<int> adj[N], c[2];
int n, res[N];

void pre_dfs(int u, int p, int d = 0) {
	c[d].push_back(u);
	for (int v : adj[u]) if (v ^ p) {
		pre_dfs(v, u, d ^ 1);
	}
}

void Hollwo_Pelw() {
	cin >> n, c[0].clear(), c[1].clear();
	for (int i = 1; i <= n; i++) adj[i].clear();
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	pre_dfs(1, 0);

	for (int i = n, j = 17; ~j; j --) {
		int t = c[1].size() > c[0].size();
		vector<int> &v = c[t];
		for (; i >= 1 << j; i--)
			res[v.back()] = i, v.pop_back();
	}

	for (int i = 1; i <= n; i++)
		cout << res[i] << " \n"[i == n];
}