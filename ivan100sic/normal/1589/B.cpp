// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

ll sol(ll x, ll y) {
    ll z = 0;
    z += (x/3) * y;
    z += (x%3) * (y / 3 + !!(y % 3));
    return z;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        cout << min(sol(n, m), sol(m, n)) << '\n';
    }
    
}