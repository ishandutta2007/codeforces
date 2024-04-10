#include<bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<vector<int>> dp(n, vector<int> (n));
    for (int i = 0; i + 1 < n; i++) {
        dp[i][i + 1] = 0;
        if (s[i] != s[i + 1]) {
            dp[i][i + 1] = 1;
        }
    }
    for (int len = 4; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            dp[l][r] = -1;
            {
                int res = 1;
                if (dp[l + 1][r - 1] == -1) {
                    res = -1;
                } else if (dp[l + 1][r - 1] == 0) {
                    if (s[l] == s[r]) {
                        res = min(res, 0);
                    } else if (s[r] < s[l]) {
                        res = -1;
                    }
                }
                if (dp[l + 2][r] == -1) {
                    res = -1;
                } else if (dp[l + 2][r] == 0) {
                    if (s[l] == s[l + 1]) {
                        res = min(res, 0);
                    } else if (s[l + 1] < s[l]) {
                        res = -1;
                    }
                }
                dp[l][r] = max(dp[l][r], res);
            }
            {
                int res = 1;
                if (dp[l + 1][r - 1] == -1) {
                    res = -1;
                } else if (dp[l + 1][r - 1] == 0) {
                    if (s[l] == s[r]) {
                        res = min(res, 0);
                    } else if (s[l] < s[r]) {
                        res = -1;
                    }
                }
                if (dp[l][r - 2] == -1) {
                    res = -1;
                } else if (dp[l][r - 2] == 0) {
                    if (s[r] == s[r - 1]) {
                        res = min(res, 0);
                    } else if (s[r - 1] < s[r]) {
                        res = -1;
                    }
                }
                dp[l][r] = max(dp[l][r], res);
            }
        }
    }
    cout << (dp[0][n - 1] == 1 ? "Alice\n" : dp[0][n - 1] == -1 ? "Bob\n" : "Draw\n");
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}