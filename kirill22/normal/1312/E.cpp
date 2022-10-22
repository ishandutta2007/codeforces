#include<bits/stdc++.h>

using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> dp(n, vector<int> (n, -1));
    for (int i = 0; i < n; i++) {
        dp[i][i] = a[i];
    }
    for (int len = 2; len <= n; len++) {
        for (int j = 0; j < n; j++) {
            if (j + len - 1 >= n) break;
            int r = j + len - 1, l = j;
            for (int i = l + 1; i <= r; i++) {
                if (dp[l][i - 1] != -1 && dp[l][i - 1] == dp[i][r]) dp[l][r] = dp[i][r] + 1;
            }
        }
    }
    vector<int> dp2(n, 1);
    for (int i = 1; i < n; i++) {
        dp2[i] = dp2[i - 1] + 1;
        for (int j = i; j > 0; j--) {
            if (dp[j][i] != -1) {
                dp2[i] = min(dp2[i], dp2[j - 1] + 1);
            }
        }
        if (dp[0][i] != -1) dp2[i] = 1;
        //cout << dp2[i] << " ";
    }
    cout << dp2[n - 1];
 }