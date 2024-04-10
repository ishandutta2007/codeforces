#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[2000000][2];
ll a[2000000];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = a[1] * r1 + r3;
    dp[1][1] = min((a[1] + 1) * r1, r2);
    for (int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][0] + d + a[i] * r1 + r3,
                       dp[i - 1][1] + 3 * d + r1 + a[i] * r1 + r3);
        dp[i][0] = min(dp[i][0], dp[i - 1][1] + 3 * d + r1 +
                                     min((a[i] + 1) * r1, r2) + r1);
        dp[i][1] = min(dp[i - 1][0] + min((a[i] + 1) * r1, r2) + d,
                       dp[i - 1][1] + 3 * d + min((a[i] + 1) * r1, r2) + r1);
    }
    ll ans = dp[n][0];
    if (n != 1) {
        ans = min(ans, dp[n - 1][1] + r1 + 2 * d + a[n] * r1 + r3);
    }
    cout << ans;
}