#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 51;

int dp[N][N][N];

int main() {
    int  i, j, n, k, q, l, r, a, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (i = 1; i < 31; ++i)
    for (j = 1; j < 31; ++j) {
        for (int i1 = 1; i1 < N; ++i1)
            dp[i][j][i1] = 1e9;
        if (i * j <= 50)
            dp[i][j][i * j] = 0;
        dp[i][j][0] = 0;
    }
    for (i = 1; i < 31; ++i)
    for (j = 1; j < 31; ++j) {
        for (int i1 = 1; i1 < i; ++i1)
        for (int p = 0; p < N; ++p)
        for (int f = 0; f + p < N; ++f)
            dp[i][j][f + p] = min(dp[i][j][f + p], dp[i1][j][p] + dp[i - i1][j][f] + j * j);
        for (int j1 = 1; j1 < j; ++j1)
        for (int p = 0; p < N; ++p)
        for (int f = 0; f + p < N; ++f)
            dp[i][j][f + p] = min(dp[i][j][f + p], dp[i][j1][p] + dp[i][j - j1][f] + i * i);
    }
    cin >> q;
    for (i = 0; i < q; ++i) {
        cin >> n >> k >> j;
        cout << dp[n][k][j] << "\n";
    }
}