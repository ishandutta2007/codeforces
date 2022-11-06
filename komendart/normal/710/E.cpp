#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e7 + 5;

int n, x, y;
int dp[maxn];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + x;
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + y);
        else dp[i] = min(dp[i], dp[i / 2 + 1] + x + y);
    }
    cout << dp[n] << endl;
}