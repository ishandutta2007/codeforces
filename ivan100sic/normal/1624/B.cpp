// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

bool divz(ll x, ll y) {
    return x % y == 0 && x / y >= 1;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        ll a, b, c;
        cin >> a >> b >> c;

        bool ok = false;
        ok |= divz(2*b-c, a);
        ok |= divz(2*b-a, c);
        ok |= divz(a+c, 2) && divz((a+c)/2, b);
        
        cout << (ok ? "YES\n" : "NO\n");
    }
    
}