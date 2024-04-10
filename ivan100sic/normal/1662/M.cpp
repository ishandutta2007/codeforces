// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int hr = 0, hw = 0;
        for (int i : ra(0, m)) {
            int r, w;
            cin >> r >> w;
            hr = max(hr, r);
            hw = max(hw, w);
        }

        if (hr + hw > n) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << string(hr, 'R') << string(n-hr, 'W') << '\n';
        }
    }
}