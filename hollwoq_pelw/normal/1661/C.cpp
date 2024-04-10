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
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
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
}

#define int long long

void Hollwo_Pelw(){
	int n; cin >> n;
	vector<int> h(n);
 
	for (int &x : h)
		cin >> x;
	sort(h.begin(), h.end());
 
	int l = 0, r = 1e18;
 
	auto check = [&](int m, int lim) -> bool {
		int c2 = m / 2, c1 = m - c2;
 
		for (int &x : h) {
			int y = lim - x;
			c1 -= y & 1;
			c2 -= y >> 1;
		}
 
		if (c1 < 0) return 0;
		return c2 >= 0 || c1 >= - c2 * 2;
	};
 
	while (l < r) {
		int m = (l + r) >> 1;
		if (check(m, h.back()) || check(m, h.back() + 1))
			r = m;
		else
			l = m + 1;
	}
 
	cout << l << '\n';
}