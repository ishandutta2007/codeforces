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

int t, a, b;

int main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        int ans = 0;
        int diff = b - a;
        if (diff >= a) {
            printf("%d\n", a);
            continue;
        }
        a -= diff;
        b -= 2 * diff;
        ans += diff;
        ans += a / 3 * 2;
        a %= 3;
        if (a == 2) ans++;
        printf("%d\n", ans);
    }

    return 0;
}