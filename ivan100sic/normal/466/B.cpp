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

    ll n, a, b;
    cin >> n >> a >> b;

    ll ao = 1e9, bo = 1e9;

    for (ll x : ra(0, 1000000)) {
        ll a2 = a + x;
        // a2 * b2 >= 6 * n
        ll b2 = max(b, (6 * n + a2 - 1) / a2);
        
        if (a2 * b2 < ao * bo) {
            ao = a2;
            bo = b2;
        }
    }

    for (ll x : ra(0, 1000000)) {
        ll b2 = b + x;
        // a2 * b2 >= 6 * n
        ll a2 = max(a, (6 * n + b2 - 1) / b2);
        
        if (a2 * b2 < ao * bo) {
            ao = a2;
            bo = b2;
        }
    }

    cout << ao * bo << '\n' << ao << ' ' << bo << '\n';
}