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

const int N = 5e6 + 5;

int n, m, dp[N], a[N], f[N];

void Hollwo_Pelw(){
	cin >> n >> m;
	fill(a + 1, a + m + 1, 0);
	fill(f + 1, f + m + 1, 0);
	iota(dp + 1, dp + m + 1, 1);
	
	int mx = 0, mn = m;
	
	for (int i = 1, x; i <= n; i++) {
		cin >> x, a[x] = f[x] = 1;
		mx = max(mx, x), mn = min(mn, x);
	}

	int res = mx - mn;

	for (int i = mx, j = mx; i >= 1; i--) {
		for (int j = i; 1ll * j * i <= mx; j++) {
			if (a[j * i]) f[dp[j * i]] --;
			dp[j * i] = min(dp[j * i], dp[j]);
			if (a[j * i]) f[dp[j * i]] ++;
		}

		// for (int j = 1; j <= m; j++)
		// 	cout << f[j] << " \n"[j == m];

		while (!f[j]) j --;
		if (i <= mn) res = min(res, j - i);
	}

	cout << res << '\n';
}