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

int c1[3], c2[3];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> c1[0] >> c1[1] >> c1[2] >> c2[0] >> c2[1] >> c2[2];
        int ans = min(c1[2], c2[1]);
        //printf("%d\n", ans);
        c1[2] -= ans, c2[1] -= ans;
        for (int i = 2; i >= 0; i--) {
            for (int j = 2; j >= 0; j--) {
                if (i == 1 && j == 2) continue;
                int tmp = min(c1[i], c2[j]);
                //printf("%d %d %d\n", i, j, tmp);
                c1[i] -= tmp, c2[j] -= tmp;
            }
        }
        //printf("%d %d\n", c1[1], c2[2]);
        ans -= min(c1[1], c2[2]);
        printf("%lld\n", ans * 2);
    }

    return 0;
}