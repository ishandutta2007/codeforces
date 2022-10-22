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

#define int long long

const int N = 1e5 + 5;
int n;

void Hollwo_Pelw() {
	cin >> n;
	int cl = 2e9, cr = -2e9;
	map<pair<int, int>, int> mp;
	map<int, int> mpl, mpr;

	for (int i = 1, l, r, c; i <= n; i++) {
		cin >> l >> r >> c;
		cl = min(cl, l);
		cr = max(cr, r);
		if (mp.count({l, r})) {
			mp[{l, r}] = min(mp[{l, r}], c);
		} else {
			mp[{l, r}] = c;
		}
		if (mpl.count(l)) {
			mpl[l] = min(mpl[l], c);
		} else {
			mpl[l] = c;
		}
		if (mpr.count(r)) {
			mpr[r] = min(mpr[r], c);
		} else {
			mpr[r] = c;
		}

		int res = mp.count({cl, cr}) ? mp[{cl, cr}] : 1e18;
		res = min(res, mpl[cl] + mpr[cr]);
		cout << res << '\n';
	}
}