// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const int inf = 1020304050;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int w = -1, wc = inf, l = inf, lc = inf, r = -inf, rc = inf;
        for (int i : ra(0, n)) {
            int al, ar, ac;
            cin >> al >> ar >> ac;
            if (al < l || (al == l && ac < lc)) {
                l = al;
                lc = ac;
            }

            if (ar > r || (ar == r && ac < rc)) {
                r = ar;
                rc = ac;
            }

            int aw = ar-al+1;
            if (aw > w || (aw == w && ac < wc)) {
                w = aw;
                wc = ac;
            }

            int ans = lc + rc;
            if (w == r-l+1) ans = min(ans, wc);
            cout << ans << '\n';
        }
    }
}