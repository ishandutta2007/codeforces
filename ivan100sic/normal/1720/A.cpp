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
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        // a/b / c/d

        ll p = a*d;
        ll q = b*c;

        int z = 2;
        if (p == q) {
            z = 0;
        } else if ((q && p % q == 0) || (p && q % p == 0) || !p || !q) {
            z = 1;
        }
        cout << z << '\n';
    }    
}