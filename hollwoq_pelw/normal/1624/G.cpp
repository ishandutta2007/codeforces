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

vector<tuple<int, int, int>> edges;
int n, m, par[N];

inline int find(int u) {
	return u == par[u] ? u : par[u] = find(par[u]);
}

inline bool merge(int u, int v) {
	if ((u = find(u)) == (v = find(v)))
		return 0;
	return par[u] = v, 1;
}

inline bool check(int val) {
	iota(par + 1, par + n + 1, 1);
	int cnt = n;
	for (auto [u, v, w] : edges)
		if ((w | val) == val)
			cnt -= merge(u, v);
	return cnt == 1;
}

void Hollwo_Pelw() {
	cin >> n >> m;
	edges.resize(m);
	for (auto &[u, v, w] : edges)
		cin >> u >> v >> w;
	int res = (1 << 30) - 1;
	for (int i = 29; ~i; i--) {
		if (check(res ^ 1 << i))
			res ^= 1 << i;
	}
	cout << res << '\n';
}