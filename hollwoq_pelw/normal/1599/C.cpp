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

#define int long long

int n;
long double p;

inline int C(int n, int k) {
	if (n < k || k < 0) return 0;
	int r = 1;
	for (int i = n, j = 1; j <= k; i--, j++)
		r = r * i / j;
	return r;
}

void Hollwo_Pelw() {
	cin >> n >> p;

	int need = C(n, 3) * 2;

	// cout << C(n, 3) * 3 * p << '\n';

	for (int r = 0; r < n; r++) {
		int c3 = C(r, 3) * C(n - r, 0) * 2;
		int c2 = C(r, 2) * C(n - r, 1) * 2;
		int c1 = C(r, 1) * C(n - r, 2) * 1;
		int c0 = C(r, 0) * C(n - r, 3) * 0;

		// cout << c0 + c1 + c2 + c3 << '\n';

		if ((long double) need * p <= (long double) (c0 + c1 + c2 + c3) + 1e-6)
			return cout << r, (void) 0;
	}
	cout << n;
}