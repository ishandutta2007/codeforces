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

const int N = 35e3 + 5, inf = 2e9;

int n, k, a[N], b[N], pre[N], nxt[N], dp[N], ndp[N];

struct range_calc {
	int v = 0, l = 1, r = 0;
	range_calc() {}

	inline int getr() { return pre[r] >= l ? r - pre[r] : 0; }
	inline int getl() { return nxt[l] <= r ? nxt[l] - l : 0; }

	inline int get(int tl, int tr) {
		while (r < tr) ++ r, v += getr();
		while (r > tr) v -= getr(), -- r;
		while (l > tl) -- l, v += getl();
		while (l < tl) v -= getl(), ++ l;
		return v;
	}
} res;

inline bool chkmin(int &a, int b) {
	return a > b ? a = b, 1 : 0;
}

void solve(int l, int r, int opl, int opr) {
	if (l > r) return ;
	int m = l + r >> 1, opm = opl;
	ndp[m] = inf;
	for (int i = opl; i <= opr && i + 1 <= m; i++)
		if (chkmin(ndp[m], dp[i] + res.get(i + 1, m))) opm = i;
	solve(l, m - 1, opl, opm);
	solve(m + 1, r, opm, opr);
}

void Hollwo_Pelw() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	fill(b + 1, b + n + 1, 0);
	for (int i = 1; i <= n; i++)
		pre[i] = b[a[i]], b[a[i]] = i;
	fill(b + 1, b + n + 1, N);
	for (int i = n; i >= 1; i--)
		nxt[i] = b[a[i]], b[a[i]] = i;
	fill(dp + 1, dp + n + 1, inf);
	for (int t = 1; t <= k; t++) {
		solve(0, n, 0, n);
		memcpy(dp, ndp, sizeof dp);
	}
	cout << dp[n] << '\n';
}