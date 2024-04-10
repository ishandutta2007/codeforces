#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j + i < n; j++) {
            int from = j;
            int to = j + i;

            auto& x = dp[from][to];
            x = n;
            if (from == to) {
                x = 1;
                continue;
            }

            // case 1: letter is alone
            x = min(x, 1 + dp[from+1][to]);
            // case 2: it is clear with something in the middle
            for (int k = from + 1; k <= to; k++) {
                if (s[from] != s[k]) continue;
                x = min(x, dp[from+1][k-1] + dp[k][to]);
            }
        }
    }
    cout << dp[0][n-1] << '\n';
}