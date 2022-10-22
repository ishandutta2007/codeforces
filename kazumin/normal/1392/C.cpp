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

int n, a[MN], del[MN];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int mx = 0, pre = 0, ans = 0, mn = a[1];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            /*if (a[i] >= a[i - 1]) {
                mx = a[i];
            } else {
                ans += max(0ll, pre - mn);
                pre = mx;
                mx = a[i];
                mn = a[i];
            }*/
        }
        for (int i = 2; i <= n; i++) {
            ans += max(0ll, a[i - 1] - a[i]);
        }
        //ans += max(0ll, pre - mn);
        printf("%lld\n", ans);
    }

    return 0;
}