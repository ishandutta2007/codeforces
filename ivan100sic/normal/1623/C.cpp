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
        vector<ll> a(n);
        for (ll& x : a) cin >> x;

        auto can = [&](ll m) {
            auto b = a;
            for (int i=n-1; i>=2; i--) {
                // the meaning of life... is not to take as much as you need
                // but to give as much as you can
                // we will solve this problem with this strategy
                ll d = min(a[i] / 3, max(0ll, (b[i] - m) / 3));
                b[i-2] += 2*d;
                b[i-1] += d;
                b[i] -= 3*d;
            }

            return *R::min_element(b) >= m;
        };

        cout << -1 + *R::partition_point(ra(0ll, 1123123123ll), can) << '\n';
    }
}