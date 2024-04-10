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
	FAST_IO("474E.inp", "474E.out");
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

const int N = 1e5 + 5;

int n, m, d;
int64_t h[N], allp[N];

pair<int, int> bit1[N], bit2[N], dp[N];

inline void add1(int64_t hh, const pair<int, int> &x) {
	int p = upper_bound(allp, allp + m, hh) - allp;
	for (; p <= m; p += p & -p)
		bit1[p] = max(bit1[p], x);
}

inline pair<int, int> get1(int64_t hh) {
	int p = upper_bound(allp, allp + m, hh) - allp;
	pair<int, int> r = {0, -1};
	for (; p; p -= p & -p)
		r = max(r, bit1[p]);
	return r;
}

inline void add2(int64_t hh, const pair<int, int> &x) {
	int p = lower_bound(allp, allp + m, hh) + 1 - allp;
	for (; p; p -= p & -p)
		bit2[p] = max(bit2[p], x);
}

inline pair<int, int> get2(int64_t hh) {
	int p = lower_bound(allp, allp + m, hh) + 1 - allp;
	pair<int, int> r = {0, -1};
	for (; p <= m; p += p & -p)
		r = max(r, bit2[p]);
	return r;
}

void Hollwo_Pelw() {
	cin >> n >> d;
	for (int i = 0; i < n; i++)
		cin >> h[i], allp[i] = h[i];

	sort(allp, allp + n);
	m = unique(allp, allp + n) - allp;
	for (int i = 1; i <= m; i++)
		bit1[i] = bit2[i] = {0, -1};

	for (int i = n - 1; ~i; i--) {
		dp[i] = max(get1(h[i] - d), get2(h[i] + d));
		++ dp[i].first;
		pair<int, int> upd = {dp[i].first, i};
		add1(h[i], upd), add2(h[i], upd);
	}

	int p = max_element(dp, dp + n) - dp, r = 0;
	cout << (r = dp[p].first) << '\n';

	for (int i = 0; i < r; i++, p = dp[p].second) {
		cout << p + 1 << ' ';
	}
}