#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, d;
    cin >> n >> k >> d;

    vector<vector<long long int> > dp(n+1, vector<long long int>(n+1, 0));
    vector<vector<long long int> > dp2(n+1, vector<long long int>(n+1, 0));

    long long int MOD = 1e9 + 7;
    
    for (int t = 1; t <= min(n, k); t++) {
        if (t < d) {
            dp[1][t] = 1;
        } else {
            dp2[1][t] = 1;
        }
    }

    for (int step = 2; step <= n; step++) {
        for (int sum = 1; sum <= n; sum++) {
            for (int t = 1; t < d; t++) {
                if (sum - t >= 0)
                {
                    dp[step][sum] += dp[step-1][sum - t]; 
                    dp2[step][sum] += dp2[step-1][sum - t];
                }
            }

            for (int t = d; t <= k; t++) {
                if (sum - t >= 0)
                {
                    dp2[step][sum] += dp[step-1][sum - t]; 
                    dp2[step][sum] += dp2[step-1][sum - t];
                }
            }

            dp[step][sum] %= MOD;
            dp2[step][sum] %= MOD;
        }
    }

    long long int s = 0;
    for (int i = 0; i <= n; i++) {
        s += dp2[i][n];
    }

    cout << s % MOD << endl;
    return 0;
}