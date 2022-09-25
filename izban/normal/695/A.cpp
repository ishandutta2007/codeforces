#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;



int main() {
#ifndef ONLINE_JUDGE
	freopen("task.in", "r", stdin);
	freopen("task.out", "w", stdout);
#endif

	cout.precision(15);
	cout << fixed;

	int n, k;
	while (cin >> n >> k) {
		vector<double> p(n);
		for (int i = 0; i < n; i++) cin >> p[i];

		vector<double> sum(1 << n);
		for (int i = 0; i < 1 << n; i++) {
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) {
					sum[i] += p[j];
				}
			}
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += p[i] > 1e-5;
		}
		if (cnt <= k) {
			for (int i = 0; i < n; i++) {
				double pp;
				if (p[i] > 1e-5) pp = 1.0;
				else pp = 0.0;
				cout << pp << " \n"[i + 1 == n];
			}
			continue;
		}
		vector<double> dp(1 << n);
		dp[0] = 1;
		for (int mask = 0; mask < 1 << n; mask++) {
			int rmask = (~mask) & ((1 << n) - 1);
			for (int i = 0; i < n; i++) if ((rmask & (1 << i)) && p[i] > 1e-5) {
				dp[mask | (1 << i)] += dp[mask] * p[i] / sum[rmask];
			}
		}
		vector<double> ans(n);
		for (int mask = 0; mask < 1 << n; mask++) {
			int cnt = 0;
			for (int i = 0; i < n; i++) cnt += (mask & (1 << i)) != 0;
			if (cnt != k) continue;
			for (int i = 0; i < n; i++) if (mask & (1 << i)) {
				ans[i] += dp[mask];
			}
		}
		for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i + 1 == n];
	}

	return 0;
}