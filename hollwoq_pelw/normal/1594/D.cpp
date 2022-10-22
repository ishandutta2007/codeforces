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

const int N = 4e5 + 5;

int n, m, par[N], ipo[N], vis[N];

struct dsu {
	dsu () {}
	dsu (int n) {
		for (int i = 0; i < 2 * n; i++)
			par[i] = i, ipo[i] = i & 1, vis[i] = 0;
	}
	inline int find(int u) {
		return par[u] = (par[u] == u ? u : find(par[u]));
	}
	inline void merge(int u, int v) {
		if ((u = find(u)) != (v = find(v)))
			par[u] = v, ipo[v] += ipo[u];
	}
};

void Hollwo_Pelw() {
	cin >> n >> m;
	dsu dsu(n);
	for (int u, v; m --; ) {
		string s;
		cin >> u >> v >> s;
		-- u, -- v;
		if (s[0] == 'i') {
			dsu.merge(u << 1, v << 1 | 1);
			dsu.merge(v << 1, u << 1 | 1);
		} else {
			dsu.merge(u << 1, v << 1);
			dsu.merge(u << 1 | 1, v << 1 | 1);
		}
	}
	for (int i = 0; i < n; i++) {
		if (dsu.find(i << 1) == dsu.find(i << 1 | 1))
			return cout << "-1\n", (void) 0;
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		int x = dsu.find(i << 1), y = dsu.find(i << 1 | 1);
		if (!vis[x]) {
			res += max(ipo[x], ipo[y]);
			vis[x] = vis[y] = 1;
		}
	}
	cout << res << '\n';
}