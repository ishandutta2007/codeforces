#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int M = 2e5 + 10, MOD = 998244353;

int n, X[M], Y[M], A[M], Dp[M];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> X[i] >> Y[i] >> A[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int idx = lower_bound(X, X + i, Y[i]) - X;
        Dp[i] = (Dp[i - 1] + X[i] - X[i - 1]) % MOD * 2 % MOD;
        Dp[i] = (Dp[i] + MOD - Dp[idx - 1]) % MOD;
        Dp[i] = (Dp[i] + MOD - Y[i]) % MOD;
        Dp[i] = (Dp[i] + X[idx - 1]) % MOD;

        ans = (ans + X[i] - X[i - 1]) % MOD;
        if (A[i]) {
            ans = (ans + Dp[i - 1]) % MOD;
            ans = (ans + X[i] - X[i - 1]) % MOD;
            ans = (ans + MOD - Dp[idx - 1]) % MOD;
            ans = (ans + MOD - Y[i]) % MOD;
            ans = (ans + X[idx - 1]) % MOD;
        }
    }
    cout << (ans + 1) % MOD;
}