#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	long long dp[n][n];
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dp[i][j];
        }
	}
	vector<long long> a(n), ans(n, 0);
	for (int i = 0; i < n; i++) {
        cin >> a[i];
	}
	vector<bool> used(n, false);
	for (int i = n - 1; i >= 0; i--) {
        long long k = a[i] - 1, s = 0;
        used[k] = true;
        for (int j = 0; j < n; j++) {
            for (int v = 0; v < n; v++) {
                dp[j][v] = min(dp[j][v], dp[j][k] + dp[k][v]);
                if (used[j] && used[v]) s += dp[j][v];
            }
        }
        ans[i] = s;
	}
	for (auto x : ans) cout << x << " ";
}