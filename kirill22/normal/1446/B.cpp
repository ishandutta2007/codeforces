#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;
    vector<vector<int>> dp(n + 1, vector<int> (m + 1));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            dp[i][j] = max(dp[i][j], max(dp[i + 1][j], dp[i][j + 1]) - 1);
            if (a[i] == b[j]) {
                dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + 2);
            }
        }
    }
    int ans = 0;
    for (auto x : dp) {
        for (auto y : x) {
            ans = max(ans, y);
        }
    }
    cout << ans;
}