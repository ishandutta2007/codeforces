// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

ll rev(ll x) {
    ll z = 0;
    while (x) {
        z = 2*z + (x&1);
        x >>= 1;
    }
    return z;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    ll x, y;
    cin >> x >> y;

    set<ll> s = {x};
    queue<ll> q;
    q.push(x);
    
    while (q.size()) {
        ll t = q.front(); q.pop();
        for (ll z : {rev(t), rev(2*t+1)}) {
            if (z < 4e18 && !s.count(z)) {
                s.insert(z);
                q.push(z);
            }
        }
    }

    cout << (s.count(y) ? "YES\n" : "NO\n");
}