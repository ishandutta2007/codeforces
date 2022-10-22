#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 2000006, MOD = 1e9 + 7;

int t, n, dp[MN][3], cnt[MN], top[MN];

int32_t main() {
    boost();

    /*dp[1][0] = 1;
    for (int i = 2; i < MN; i++) {
        dp[i][0] = dp[i - 1][0] + 2 * dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
        dp[i][2] = dp[i - 1][1] + dp[i - 1][2];
        dp[i][0] %= MOD; dp[i][1] %= MOD; dp[i][2] %= MOD;
        //printf("%lld %lld %lld\n", dp[i][0], dp[i][1], dp[i][2]);
    }*/
    cnt[3] = cnt[4] = 1;
    top[3] = 1, top[4] = 0;
    for (int i = 5; i < MN; i++) {
        cnt[i] = cnt[i - 2] * 2 + cnt[i - 1];
        if (!top[i - 2] && !top[i - 1]) cnt[i]++, top[i] = 1;
        cnt[i] %= MOD;
    }
    cin >> t;
    while (t--) {
        cin >> n;
        printf("%lld\n", cnt[n] * 4 % MOD);
    }

    return 0;
}