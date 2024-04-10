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

const int N = 2e5 + 5;

int n, h[N];
vector<int> adj[N];
long long res;

void dfs(int u, int p) {
	int f1 = 0, f2 = 0;
	
	for (int v : adj[u]) if (v != p) {
		dfs(v, u);	int cr = h[v];

		res += cr;

		if (f1 < cr) swap(f1, cr);
		if (f2 < cr) swap(f2, cr);
	}

	h[u] = max(h[u], f1);
	res -= p ? f1 : f1 + f2;
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	
	int r = max_element(h + 1, h + n + 1) - h;
	dfs(r, 0);

	cout << res + h[r] * 2;
}