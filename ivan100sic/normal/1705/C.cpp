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
        int n, c, q;
        string s;
        
        cin >> n >> c >> q >> s;
        ll len = n;
        vector<array<ll, 4>> a(c);
        for (int i : ra(0, c)) {
            ll l, r;
            cin >> l >> r;
            l--;
            a[i] = {len, len + r - l, l, r};
            len += r - l;
        }

        while (q--) {
            ll k;
            cin >> k;
            k--;
            while (k >= n) {
                auto [al, ar, bl, br] = *R::find_if(a, [&](auto& w) {
                    return w[0] <= k && k < w[1];
                });

                k -= al - bl;
            }

            cout << s[k] << '\n';
        }
    }    
}