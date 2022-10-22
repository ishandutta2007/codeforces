#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 105;

int t, n, x, m, l, r;

int main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n >> x >> m;
        int al = x, ar = x;
        for (int i = 1; i <= m; i++) {
            cin >> l >> r;
            if (r >= al) al = min(al, l);
            if (l <= ar) ar = max(ar, r);
        }
        printf("%d\n", ar - al + 1);
    }

    return 0;
}