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

const int N = 3.5e4 + 5;

int n, k, a[N], dp[N], ldp[N];

struct get_cost {
	int cnt[N], res = 0, tl = 1, tr = 0;
	get_cost () {
		memset(cnt, 0, sizeof cnt);
	}

	inline void add(int v) { if ((cnt[v] ++) == 0) res ++; }
	inline void del(int v) { if ((-- cnt[v]) == 0) res --; }

	inline int operator () (int l, int r) {
		while (tl > l) add(a[-- tl]);
		while (tr < r) add(a[++ tr]);
		while (tl < l) del(a[tl ++]);
		while (tr > r) del(a[tr --]);

		return res;
	}
} cost;

bool chkmax(int &a, int b) {
	return a < b ? a = b, 1 : 0;
}

void solve(int l, int r, int opl, int opr) {
	if (l > r) return ;
	int m = l + r >> 1, opm = opl;
	for (int i = opl; i <= m && i <= opr; i++)
		if (chkmax(dp[m], ldp[i - 1] + cost(i, m))) opm = i;
	solve(l, m - 1, opl, opm), solve(m + 1, r, opm, opr);
}

void Hollwo_Pelw() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	while (k --) swap(dp, ldp), memset(dp, 0, sizeof dp), solve(1, n, 1, n);
	cout << dp[n];
}