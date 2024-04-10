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

const int N = 1e3 + 5;

int n, cnt;
vector<int> adj[N];
pair<int, int> ed[N];

void pre_dfs(int u, int p) {
	for (auto v : adj[u]) if (v != p) {
		ed[++ cnt] = {u, v}, pre_dfs(v, u);
	}
}

inline int query(int l, int r) {
	set<int> s;
	for (int i = l; i <= r; i++)
		s.insert(ed[i].first), s.insert(ed[i].second);
	cout << "? " << s.size() << ' ';
	for (auto v : s) cout << v << ' ';
	cout << endl; return cin >> r, r;
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	pre_dfs(1, -1);
	int v = query(1, cnt), l = 1, r = cnt;
	while (l < r) {
		int m = l + r >> 1;
		if (query(l, m) == v)
			r = m;
		else
			l = m + 1;
	}
	cout << "! " << ed[l].first << ' ' << ed[l].second << endl;
}