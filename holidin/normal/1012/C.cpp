#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int N = 5000;
int dp[N][N][3], a[N];

int main() {
    int i, j, n;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; ++i)
        cin >> a[i];
    for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j) {
        dp[i][j][0] = inf;
        dp[i][j][1] = inf;
        dp[i][j][2] = inf;
    }
    dp[0][0][0] = 0;
    dp[0][1][1] = 0;
    for (i = 1; i < n; ++i)
    for (j = 0; j < n; ++j) {
        dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][2]);
        if (j > 0) {
            dp[i][j][2] = dp[i - 1][j][1] + max(a[i] - a[i - 1] + 1, 0);
            dp[i][j][1] = dp[i - 1][j - 1][0] + max(a[i - 1] - a[i] + 1, 0);
            if (i > 1)
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - 1][2] + max(min(a[i - 1], a[i - 2] - 1) - a[i] + 1, 0));
        }
    }
    for (i = 1; i <= (n + 1) / 2; ++i) {
        long long ans = inf;
        cout << min(min(dp[n - 1][i][2], dp[n - 1][i][0]), dp[n - 1][i][1]) << ' ';
    }
}