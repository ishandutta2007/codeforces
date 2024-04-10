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
        int n;
        cin >> n;
        vector<int> inv(n);
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            inv[x] = i;
        }

        int l = inv[0], r = inv[0], sol = 1, cnt = 1;
        for (int x : span(inv).subspan(1)) {
            if (x < l || x > r) {
                l = min(l, x);
                r = max(r, x);
            } else {
                sol = 1ll * sol * (r-l+1-cnt) % 1'000'000'007;
            }
            cnt++;
        }
        cout << sol << '\n';
    }
}