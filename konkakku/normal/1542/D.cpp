#include <bits/stdc++.h>
using namespace std;

const int N = 505, MOD = 998244353;

int n, a[N];
char t;
long long ans = 0;

long long solve(int u) {
    int thr = a[u];
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i < u; i++) {
        if (a[i] == 0) {
            (dp[0] += dp[0]) %= MOD;
            for (int j = 0; j < n; j++) {
                (dp[j] += dp[j + 1]) %= MOD;
            }
        } else if (a[i] < thr) {
            for (int j = n; j > 0; j--) {
                (dp[j] += dp[j - 1]) %= MOD;
            }
        } else {
            for (int j = n; j >= 0; j--) {
                (dp[j] *= 2) %= MOD;
            }
        }
    }
    for (int j = n; j > 0; j--) {
        dp[j] = dp[j - 1];
    }
    dp[0] = 0;
    for (int i = u + 1; i <= n; i++) {
        if (a[i] == 0) {
            (dp[0] += dp[0]) %= MOD;
            for (int j = 0; j < n; j++) {
                (dp[j] += dp[j + 1]) %= MOD;
            }
        } else if (a[i] <= thr) {
            for (int j = n; j > 0; j--) {
                (dp[j] += dp[j - 1]) %= MOD;
            }
        } else {
            for (int j = n; j >= 0; j--) {
                (dp[j] *= 2) %= MOD;
            }
        }
        dp[0] = 0;
    }
    return accumulate(dp.begin() + 1, dp.end(), 0LL) % MOD;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        if (t == '+') {
            cin >> a[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) {
            (ans += a[i] * solve(i)) %= MOD;
        }
    }
    cout << ans;
}