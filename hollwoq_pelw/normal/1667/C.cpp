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

void Hollwo_Pelw(){
	int n; cin >> n;
	cout << n / 3 + (n + 2) / 3 << '\n';

	if (n == 1)
		return cout << "1 1\n", (void) 0;

	for (; n % 3 != 2; n --)
		cout << n << ' ' << n << '\n';

	int f = (n + 1) / 3;
	for (int i = f, x =         1, y = f; i --; x++, y--)
		cout << x << ' ' << y << '\n';
	for (int i = f, x = n - f + 2, y = n; -- i; x++, y--)
		cout << x << ' ' << y << '\n';
}