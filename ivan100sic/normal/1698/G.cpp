// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

// pair<ull, ull> poly_quot_rem(ull p, ull q) {
//     ull quot = 0;
//     while (p > 0) {
//         int diff = (int)bit_width(p) - (int)bit_width(q);
//         if (diff >= 0) {
//             p ^= q << diff;
//             quot ^= 1ull << diff;
//         }
//     }
//     return {quot, p};
// }

// ull poly_eea(ull a, ull b, ull& x, ull& y) {
//     if (!b) {
//         x = 1;
//         y = 0;
//         return a;
//     }

//     ull x1, y1;

//     auto [quot, rem] = poly_quot_rem(a, b);

//     ull g = poly_eea(b, rem, x1, y1);
//     x = y1;
//     y = x1 - (quot) * y1;
//     return g;
// }

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    string s;
    cin >> s;

    int leading = 1;
    while (s.size() && s[0] == '0') {
        s.erase(0, 1);
        leading++;
    }

    if (s.empty()) {
        cout << "-1\n";
        return 0;
    }
    
    while (s.size() && s.back() == '0') {
        s.pop_back();
    }

    ull p = 0;
    for (int i : ra(0, ssize(s))) {
        if (s[i] == '1') {
            p |= 1ull << i;
        }
    }
    ull phi = 1ull << (bit_width(p) - 1);

    if (p == 1 || p == 3) {
        cout << leading << ' ' << leading + 1 << '\n';
        return 0;
    }

    ull smallpows[80];
    smallpows[0] = 1;
    for (int i : ra(1, 80)) {
        smallpows[i] = smallpows[i-1] << 1;
        if (smallpows[i] & phi) {
            smallpows[i] ^= p;
        }
    }

    auto mul = [&](ull x, ull y) {
        ull z = 0;
        for (int i : ra(0, 35)) {
            if (x & (1ull << i)) {
                for (int j : ra(0, 35)) {
                    if (y & (1ull << j)) {
                        z ^= smallpows[i + j];
                    }
                }
            }
        }
        return z;
    };

    auto cyc = [&] {
        vector<pair<ull, int>> pws_inv_x(262145);
        pws_inv_x[0].first = 1;
        pws_inv_x[1].first = ((p << 1) ^ p ^ 1) >> 1;

        for (int i : ra(2, ssize(pws_inv_x))) {
            pws_inv_x[i].first = mul(pws_inv_x[i-1].first, pws_inv_x[1].first);
        }

        for (ll i : ra(1, ssize(pws_inv_x))) {
            pws_inv_x[i].second = i;
            if (pws_inv_x[i].first == 1) {
                return i;
            }
        }

        R::sort(pws_inv_x);

        ull bigpw = 2;
        for (int i = 0; i < 18; i++) {
            bigpw = mul(bigpw, bigpw);
        }

        ull tpw = 1;
        for (ll i : ra(1, -1)) {
            tpw = mul(tpw, bigpw);
            auto it = R::lower_bound(pws_inv_x, pair{tpw, -1});
            if (it != pws_inv_x.end() && it->first == tpw) {
                return (i << 18) + it->second;
            }
        }
        
        return -1ll;
    };

    cout << leading << ' ' << leading + cyc() << '\n';
}