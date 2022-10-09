// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct entry {
    ll sum = 0, low = 0;
};

auto proc(auto b) {
    entry e = {};
    vector<entry> v;
    
    for (ll x : b) {
        e.sum += x;
        e.low = min(e.low, e.sum);
        if (e.sum > 0) {
            v.push_back(e);
            e = {};
        }
    }

    v.push_back(e);
    return v;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        k--;

        vector<ll> a(n);

        for (ll& x : a) cin >> x;

        auto lv = proc(R::reverse_view{span(a).subspan(0, k)});
        auto rv = proc(span(a).subspan(k+1));

        auto ls = span(lv);
        auto rs = span(rv);

        ll w = a[k];
        bool ok = 1;
        while (ls.size() && rs.size()) {
            entry e;
            if (ls[0].low > rs[0].low) {
                e = ls[0];
                ls = ls.subspan(1);
            } else {
                e = rs[0];
                rs = rs.subspan(1);
            }
            
            if (w + e.low < 0) {
                ok = 0;
                break;
            }

            w += e.sum;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}