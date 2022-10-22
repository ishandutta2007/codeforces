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

const int N = 1005;

int n, d, par[N], siz[N];
pair<int, int> ed[N];

inline int find(int u) {
	return par[u] == u ? u : par[u] = find(par[u]);
}

inline bool merge(int u, int v) {
	if ((u = find(u)) == (v = find(v)))
		return 0;
	par[u] = v;
	siz[v] += siz[u];
	return 1;
}

void Hollwo_Pelw() {
	cin >> n >> d;
	iota(par + 1, par + n + 1, 1);
	fill(siz + 1, siz + n + 1, 1);
	int cnt = 0;

	for (int i = 1, x, y; i <= d; i++) {
		cin >> x >> y;
		if (!merge(x, y)) ++ cnt;

		// cout << cnt << '\n';

		vector<int> v;
		for (int j = 1; j <= n; j++)
			if (par[j] == j) v.push_back(siz[j]);
		sort(v.rbegin(), v.rend());

		int res = 0;
		for (int j = 0; j < v.size() && j <= cnt; j++)
			res += v[j];

		cout << res - 1 << '\n';
	}
}