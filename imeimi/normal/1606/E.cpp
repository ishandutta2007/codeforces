#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 998244353;
int nCr[505][505], pw[505][505];
int dp[505][505];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i <= n; ++i) {
        nCr[i][0] = nCr[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % mod;
        }
    }
    for (int i = 1; i <= x; ++i) {
        pw[i][0] = 1;
        for (int j = 1; j <= n; ++j) {
            pw[i][j] = 1ll * pw[i][j - 1] * i % mod;
        }
    }
    for (int i = 0; i <= x; ++i) dp[0][i] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= x; ++j) {
            if (j <= i - 1) {
                dp[i][j] = pw[j][i];
            }
            else for (int k = 0; k <= i; ++k) {
                dp[i][j] = (dp[i][j] + 1ll * nCr[i][k] * pw[i - 1][k] % mod * dp[i - k][j - (i - 1)]) % mod;
            }
        }
    }
    printf("%d\n", dp[n][x]);
    return 0;
}