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
	cout << "\nExecution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 2005;

int n, pa, pb;
double a[N], b[N];

pair<double, int> dp[N][N];

inline void solve(double cost) {
	auto upd = [&](pair<double, int> &a, const pair<double, int> &b) { a = max(a, b); };

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= pa; j++)
		dp[0][i] = {-2e9, -2e9};
	dp[0][0] = {0, 0};

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= pa; j++)
			dp[i][j] = dp[i - 1][j];
		for (int j = 0; j <= pa; j++) {
			upd(dp[i][j], pair<double, int>(dp[i - 1][j].first + b[i] + cost, dp[i - 1][j].second + 1));
		}
		for (int j = 1; j <= pa; j++) {
			upd(dp[i][j], pair<double, int>(dp[i - 1][j - 1].first + a[i], dp[i - 1][j - 1].second));
			upd(dp[i][j], pair<double, int>(dp[i - 1][j - 1].first + 1 - (1 - a[i]) * (1 - b[i]) + cost, dp[i - 1][j - 1].second + 1));
		}
	}
}

void Hollwo_Pelw(){
	cin >> n >> pa >> pb;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];

	double l = -1, r = 0;
	for (int iter = 30; iter --; ) {
		double m = (l + r) / 2;
		solve(m);
		if (dp[n][pa].second >= pb) {
			r = m;
		} else {
			l = m;
		}
	}

	solve(l);
	cout << fixed << setprecision(6) << dp[n][pa].first - pb * l;
}