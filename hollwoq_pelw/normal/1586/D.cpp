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

const int N = 105;

int n, st, res[N], timer;
vector<int> adj[N];

inline void query_dw(int p) {
	cout << "? ";
	for (int i = 1; i <= n; i++)
		cout << (i == p ? 1 : 2) << " ";
	cout << endl;
	int k; cin >> k;
	if (k == 0) {
		st = p;
	} else if (k != p) {
		adj[k].push_back(p);
		adj[p].push_back(k);
	}
}

inline void query_up(int p) {
	cout << "? ";
	for (int i = 1; i <= n; i++)
		cout << (i != p ? 1 : 2) << " ";
	cout << endl;
	int k; cin >> k;
	if (k != 0 && k != p) {
		adj[k].push_back(p);
		adj[p].push_back(k);
	}
}

void dfs(int u) {
	res[u] = ++ timer;
	for (auto v : adj[u])
		if (!res[v]) dfs(v);
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		query_dw(i);
		query_up(i);
	}
	dfs(st);
	cout << "! ";
	for (int i = 1; i <= n; i++)
		cout << res[i] << ' ';
	cout << endl;
}