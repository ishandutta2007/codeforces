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
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 2e5 + 5;

int n, a[N];
long long m;

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = n; i; i--)
		a[i] -= a[i - 1];
	cin >> m;

	auto f = [&](int x, int y) -> long long {
		int q = x / (y + 1), r = x % (y + 1);
		return 1ll * (y + 1 - r) * q * q + 1ll * r * (q + 1) * (q + 1);
	};

	auto solve = [&](long long x) -> pair<long long, long long> {
		long long cnt = 0, val = 0;

		// cout << "Solve " << x << '\n';

		for (int i = 1; i <= n; i++) {
			int l = 0, r = a[i] - 1;
			while (l < r) {
				int m = (l + r + 1) >> 1;
				if (f(a[i], m - 1) - f(a[i], m) >= x)
					l = m;
				else
					r = m - 1;
			}
			cnt += l;
			val += f(a[i], l);
		}

		return pair(cnt, val);
	};

	long long l = 0, r = 1e18;
	while (l + 1 < r) {
		long long md = (l + r) >> 1;
		if (solve(md).second > m)
			r = md;
		else
			l = md;
	}

	auto [cnt, val] = solve(r);

	cout << cnt + (val - m + l - 1) / l << '\n';
}