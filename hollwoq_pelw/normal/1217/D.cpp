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

const int N = 5005;

struct Edge {
	int u, v;
} ed[N];

int n, m, deg[N], cnt;
vector<int> adj[N];

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v, adj[u].push_back(v);
		ed[i] = {u, v}, ++ deg[v];
	}
	bool ok = 0;
	for (int i = 1; i <= n && !ok; i++) {
		for (int j = 1; j <= n; j++) if (deg[j] == 0) {
			for (int k : adj[j]) deg[k] --; deg[j] --, cnt ++;
		}
		if (cnt == n) ok = 1;
	}
	if (ok) {
		cout << 1 << '\n';
		for (int i = 1; i <= m; i++)
			cout << 1 << ' ';
	} else {
		cout << 2 << '\n';
		for (int i = 1; i <= m; i++)
			cout << (ed[i].u > ed[i].v ? 1 : 2) << ' ';
	}
}