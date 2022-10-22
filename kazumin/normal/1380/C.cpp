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

int n, x, a[MN];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        int cnt = 0, len = 0;
        for (int i = n; i > 0; i--) {
            len++;
            if (a[i] * len >= x) cnt++, len = 0;
        }
        printf("%lld\n", cnt);
    }

    return 0;
}