#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 998244353;

void sum(int &a, int b) {
	a = (a + b) % MOD;
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int dp[n][n];
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		dp[i][j] = 0;
    	}
    }
    for (int i = 0; i < n; i++) {
    	dp[i][i] = 1;
    }
    for (int len = 2; len <= n; len++) {
    	for (int l = 0; l + len - 1 < n; l++) {
    		int r = l + len - 1;
    		int m = l, tmp = a[l];
    		for (int i = l + 1; i <= r; i++) {
    			if (a[i] < tmp) {
    				m = i;
    				tmp = a[i];
    			}
    		}
    		int res1 = 0, res2 = 0;
    		for (int i = l; i <= m && m != l; i++) {
    			if (i == l) {
    				sum(res1, dp[l][m - 1]);
    			}
    			else if (i == m) {
    				sum(res1, dp[l][m - 1]);
    			}
    			else {
    				sum(res1, (dp[l][i - 1] * dp[i][m - 1]) % MOD);
    			}
    		}
    		if (m == l) res1 = 1;
    		for (int i = m; i <= r && m != r; i++) {
    			if (i == m) {
    				sum(res2, dp[m + 1][r]);
    			}
    			else if (i == r) {
    				sum(res2, dp[m + 1][r]);
    			}
    			else {
    				sum(res2, (dp[m + 1][i] * dp[i + 1][r]) % MOD);
    			}
    		}
    		if (m == r) res2 = 1;
    		sum(dp[l][r], (res1 * res2) % MOD);
    	}
    }
    cout << dp[0][n - 1];
}