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

int m, d, w, maxday;

int32_t main() {
    boost();

    int t;
    cin >> t;
    outer:
    while (t--) {
        cin >> m >> d >> w;
        m = min(m, d);
        w /= __gcd(w, d - 1);
        int k = m / w;
        printf("%lld\n", m * k - w * (k * (k + 1) / 2));
    }

    return 0;
}