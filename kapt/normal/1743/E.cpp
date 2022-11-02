#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18;

main() {
    array<int, 2> p, t;
    cin >> p[0] >> t[0] >> p[1] >> t[1];
    int h, s;
    cin >> h >> s;
    vector<int> dp(h + 1, INF);
    dp[0] = 0;
    int ans = INF;
    for (int i = 0; i <= h; ++i) {
        array<int, 2> tm = {dp[i], dp[i]};
        int cur = i;
        while (cur < h) {
            dp[min(h, cur + p[0] + p[1] - s)] = min(dp[min(h, cur + p[0] + p[1] - s)], max(tm[0] + t[0], tm[1] + t[1]));
            if (tm[0] + t[0] < tm[1] + t[1]) {
                cur += p[0] - s;
                tm[0] += t[0];
            } else {
                cur += p[1] - s;
                tm[1] += t[1];
            }
        }
        ans = min(ans, max(tm[0], tm[1]));
    }
    cout << ans;
    return 0;
}