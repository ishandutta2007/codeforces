#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 30;
int dp[MAXN];

main() {
    int t;
    cin >> t;
    while (t--) {
        int d, m;
        cin >> d >> m;
        fill(dp, dp + MAXN, 0);
        dp[0] = 1;
        int ans = 1;
        for (int i = 1; i < MAXN; ++i) {
            if ((1 << i) > d) {
                break;
            }
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j];
            }
            dp[i] += 1;
            dp[i] %= m;
            dp[i] *= min((int64_t)(1 << i), d - (1 << i) + 1);
            dp[i] %= m;
            ans += dp[i];
            ans %= m;
        }
        cout << ans % m << endl;
    }
    return 0;
}