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
 
struct dsu {
	int par[N];
	dsu () {
		for (int i = 0; i < N; i++) par[i] = i;
	}
	int find(int u) {
		return par[u] = (par[u] == u ? u : find(par[u]));
	}
	bool check(int u, int v) {
		return find(u) != find(v);
	}
	void merge(int u, int v) {
		par[find(u)] = find(v);
	}
} da, db;
 
int n, m1, m2;

void Hollwo_Pelw() {
	cin >> n >> m1 >> m2;
	for (int i = 1, u, v; i <= m1; i++)
		cin >> u >> v, da.merge(u, v);
	for (int i = 1, u, v; i <= m2; i++)
		cin >> u >> v, db.merge(u, v);
	vector<pair<int, int>> res;
	for (int i = 1; i <= n; i++) {
		if (da.check(1, i) && db.check(1, i))
			da.merge(1, i), db.merge(1, i), res.emplace_back(1, i);
	}
	vector<int> va, vb;
	for (int i = 1; i <= n; i++) {
		if (da.check(1, i)) va.push_back(i), da.merge(1, i);
		if (db.check(1, i)) vb.push_back(i), db.merge(1, i); 
	}
	for (int i = 0; i < min(va.size(), vb.size()); i++)
		res.emplace_back(va[i], vb[i]);
	cout << res.size() << '\n';
	for (auto uv : res)
		cout << uv.first << ' ' << uv.second << '\n';
}