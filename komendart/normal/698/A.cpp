#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

int dp[maxn][3];
int a[maxn];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] == 2 || a[i] == 3) dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]);
        else dp[i][0] = 100500;
        if (a[i] == 1 || a[i] == 3) dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        else dp[i][1] = 100500;
        dp[i][2] = 1 + min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}