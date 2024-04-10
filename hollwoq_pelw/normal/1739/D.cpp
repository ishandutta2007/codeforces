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

const int N = 2e5 + 5;

int n, k, p[N], d[N];

bool check(int h) {
	fill(d + 1, d + n + 1, 0);
	int f = 0;
	for (int i = n; i >= 2; i--) {
		d[i] ++;
		if (d[i] == h && p[i] != 1)
			f ++;
		else
			d[p[i]] = max(d[p[i]], d[i]);
	}
	// cout << h << " -> " << f << endl;
	return f <= k;
}

void Hollwo_Pelw(){
	cin >> n >> k;
	for (int i = 2; i <= n; i++)
		cin >> p[i];

	int tl = 1, tr = n - 1;
	while (tl < tr) {
		int tm = (tl + tr) >> 1;
		if (check(tm))
			tr = tm;
		else
			tl = tm + 1;
	}
	cout << tl << '\n';
}