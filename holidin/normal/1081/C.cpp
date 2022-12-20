#include <bits/stdc++.h>
using namespace std;
const int N = 2003;
const int mod = 998244353;
long long dp[N][N];

int main() {
    int i, j, n, m, k;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    k = n - k - 1;
    dp[1][0] = m;
    for (i = 1; i < n; ++i)
    for (j = 0; j < n; ++j) {
        dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod;
        dp[i + 1][j] = (dp[i + 1][j] + ((long long)m - 1) * dp[i][j]) % mod;
    }
    cout << dp[n][k];
}