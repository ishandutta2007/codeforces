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

int n, a[MN], k;

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int lim = 1;
        if (k % 2 == 0) lim = 2;
        for (int tim = 0; tim < lim; tim++) {
            int mx = -(1LL << 60);
            for (int i = 1; i <= n; i++) mx = max(mx, a[i]);
            for (int i = 1; i <= n; i++) a[i] = mx - a[i];
        }
        for (int i = 1; i <= n; i++) printf("%lld ", a[i]);
        printf("\n");
    }

    return 0;
}