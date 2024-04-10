#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    const int MOD = 1'000'000'007;
    
    vector<vector<long long>> dp(n+1, vector<long long>(n+1, 0));
    dp[0][0] = 1;
    char last = '.';
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if (last == 'f') {
            for (int depth = n; depth > 0; depth--) {
                dp[i][depth] = dp[i-1][depth-1];
            }
        } else {
            long long total = 0;
            for (int depth = n; depth >= 0; depth--) {
                total = (total + dp[i-1][depth]) % MOD;
                dp[i][depth] = total;
            }
        }
        last = c;
    }

    cout << accumulate(dp[n].begin(), dp[n].end(), 0LL) % MOD << '\n';
}