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
        ll h = *R::max_element(a);
        if (h == 0) {
            cout << "0\n";
            continue;
        }

        ll s = accumulate(begin(a), end(a), 0ll);
        s -= h;
        cout << max(1ll, h-s) << '\n';
    }
    
}