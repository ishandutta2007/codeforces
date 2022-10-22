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

const int MN = 100005;

int n, k, z, a[MN], dp[MN][10];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k >> z;
        k++;
        for (int i = 0; i <= n; i++) for (int j = 0; j <= z; j++) dp[i][j] = -0x3f3f3f3f;
        for (int i = 1; i <= n; i++) cin >> a[i];
        dp[1][0] = a[1];
        for (int i = 2; i <= n; i++) {
            dp[i][0] = a[i] + dp[i - 1][0];
            for (int c = 0; c < 10; c++) {
                for (int j = 1; j <= z; j++) {
                    dp[i - 1][j] = max(dp[i - 1][j], dp[i][j - 1] + a[i - 1]);
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i]);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= z; j++) {
                if (i + 2 * j == k) ans = max(ans, dp[i][j]);
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}