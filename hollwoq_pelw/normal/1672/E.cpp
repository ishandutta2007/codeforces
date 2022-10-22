#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

signed main(){
#ifndef hollwo_pelw_local
	if (fopen("hollwo_pelw.inp", "r"))
		assert(freopen("hollwo_pelw.inp", "r", stdin)), assert(freopen("hollwo_pelw.out", "w", stdout));
#else
	using namespace chrono;
	auto start = steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExcution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

#define int long long

const int N = 2e5 + 5;

inline int ask(int w) {
	cout << "? " << w << endl;
	int res; return cin >> res, res;
}

void Hollwo_Pelw(){
	int n, l = 1, r = 4.1e6;
	
	cin >> n;
	while (l < r) {
		int m = (l + r) >> 1;
		if (ask(m) == 1)
			r = m;
		else
			l = m + 1;
	}

	int len = l - (n - 1), res = l;

	for (int i = 2; i <= n; i++) {
		int f = len + (n - i), s = (res - 1) / i;
		f = f / i + (f % i > 0);
		if (s < f) continue ;

		while (f <= s) {
			int m = (f + s) >> 1;
			int x = ask(m);
			if (x && x <= i) {
				res = min(res, x * m);
				s = m - 1;
			} else {
				f = m + 1;
			}
		}
	}

	cout << "! " << res << endl;
}