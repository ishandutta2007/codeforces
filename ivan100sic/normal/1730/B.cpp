// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const int inf = 1123123123;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> a(n);
        for (auto& x : a) cin >> x.first, x.first *= 2;
        for (auto& x : a) cin >> x.second, x.second *= 2;

        int gl = -1;

        auto can = [&] (int m) {
            int l = -inf;
            int r = inf;

            for (auto [x, t] : a) {
                l = max(l, x-(m-t));
                r = min(r, x+(m-t));
            }

            gl = l;
            return l <= r;
        };

        int tm = *R::lower_bound(ra(0, int(1e9)), true, {}, can);
        can(tm);

        cout << gl/2 << "." << gl%2*5 << '\n';
    }
}