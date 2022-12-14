#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
int dp[2005][2005];
int main() {
    dp[0][0] = 1;
    for (int i = 1; i <= 2000; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
            if (j < i) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
        }
    }
    int n, m;
    cin >> n >> m;
    //(n)H(2m)
    cout << dp[n + 2 * m - 1][2 * m];
}