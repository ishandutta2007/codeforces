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

const int N = 3e5 + 5;

#define int long long

inline int query(int l, int r) {
	if (l > r) return 0; 
	cout << "? " << l << ' ' << r << endl;
	int res; cin >> res; return res;
}

void Hollwo_Pelw() {
	int n; cin >> n;

	int l = 1, r = n;

	int tot = query(1, n), i = -1, j = -1, k = -1;

	while (l <= r) {
		int m = l + r >> 1;
		if (query(1, m) == tot) {
			k = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}

	{
		int diff = query(1, k) - query(1, k - 1);
		j = k - diff;
	}
	{
		int diff = query(1, j - 1) - query(1, j - 2);
		i = j - 1 - diff;
	}

	cout << "! " << i << ' ' << j << ' ' << k << endl;
}