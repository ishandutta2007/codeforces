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
	if (fopen(".inp", "r"))
		assert(freopen(".inp", "r", stdin)), assert(freopen(".out", "w", stdout));
#else
	using namespace chrono;
	auto start = steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExecution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

#define int long long

void Hollwo_Pelw(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(k);
	for (int &x : a)
		cin >> x;

	for (int i = 0; i < 2; i++) {
		vector<int> b = a;
		swap(n, m);
		int cnt = 0, c3 = 0;
		for (int &x : b) {
			x /= m;
			if (x > 1)
				cnt += x;
			if (x > 2) c3 = 1;
		}
		if (cnt < n)
			continue;
		if ((n & 1) && !c3)
			continue;
		return cout << "Yes\n", (void) 0;
	}
	cout << "No\n";
}