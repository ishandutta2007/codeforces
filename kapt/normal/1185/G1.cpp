#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 15, MOD = 1e9 + 7;
pair<int, int> arr[MAXN];
int dp[(1 << MAXN)][3];

main() {
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
        arr[i].second--;
    }
    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    int ans = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                // cout << i << endl;
                // cout << (mask ^ (1 << i)) << endl;
                int g = arr[i].second;
                sum += arr[i].first;
                // cout << dp[0][(g + 1) % 3] << " ";
                // cout << dp[0][(g + 2) % 3] << endl;
                dp[mask][g] += dp[mask ^ (1 << i)][(g + 1) % 3];
                dp[mask][g] %= MOD;
                dp[mask][g] += dp[mask ^ (1 << i)][(g + 2) % 3];
                dp[mask][g] %= MOD;
                // cout << g << " " << dp[mask][g] << endl;
            }
        }
        if (sum == t) {
            ans += dp[mask][0];
            ans += dp[mask][1];
            ans += dp[mask][2];
            ans %= MOD;
        }
        // cout << mask << " " << dp[mask][0] << " ";
        // cout << dp[mask][1] << " " << dp[mask][2] << endl;
    }
    if (ans % 2 == 1) {
        ans += MOD;
    }
    cout << ans / 2;
    return 0;
}