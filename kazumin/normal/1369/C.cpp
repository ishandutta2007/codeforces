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

const int MN = 200005;

int n, k, a[MN], w[MN];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int ones = 0;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= k; i++) {
            cin >> w[i], w[i]--;
            if (w[i] == 0) ones++;
        }
        sort(w + 1, w + k + 1, greater<>());
        sort(a + 1, a + n + 1);
        int lft = 1, rit = n, ans = 0;
        for (int i = 1; i <= ones; i++) ans += 2 * a[rit--];
        for (int i = 1; i <= k; i++) {
            if (w[i] == 0) continue;
            ans += a[rit--];
            ans += a[lft], lft += w[i];
        }
        assert(lft == rit + 1);
        printf("%lld\n", ans);
    }

    return 0;
}