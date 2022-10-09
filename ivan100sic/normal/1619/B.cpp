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

    set<ll> a;
    for (ll x=1; x<=32000; x++) {
        a.insert(x*x);
        a.insert(x*x*x);
    }

    vector<ll> b(begin(a), end(a));
    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        cout << R::upper_bound(b, x) - b.begin() << '\n';
    }
}