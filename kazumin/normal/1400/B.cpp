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

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int p, f, cnts, cntw, s, w, CS, CW;
        cin >> p >> f >> cnts >> cntw >> s >> w;
        if (s > w) swap(s, w), swap(cnts, cntw);
        CS = cnts, CW = cntw;
        int ans = 0;
        for (int s1 = 0; s1 <= cnts; s1++) {
            int ret = s1;
            int rem = p - s1 * s;
            cnts -= s1;
            if (rem < 0) break;
            ret += min(cntw, rem / w);
            //printf("%d %d ", s1, rem / w);
            cntw -= min(cntw, rem / w);
            int p2 = f;
            ret += min(cnts, p2 / s);
            //printf("%d ", min(cnts, p2 / s));
            p2 -= min(cnts, p2 / s) * s;
            cnts -= min(cnts, p2 / s);
            ret += min(cntw, p2 / w);
            //printf("%d\n", min(cntw, p2 / w));
            ans = max(ans, ret);
            cnts = CS, cntw = CW;
        }
        printf("%lld\n", ans);
    }

    return 0;
}