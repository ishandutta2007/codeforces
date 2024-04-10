// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

#ifdef LOCAL
const ll H = 10;
#else
const ll H = 500000000;
#endif

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        ll b = 1, z = 1;
        for (ll x=1; x<=H; x*=2) {
            cout << "? " << b << ' ' << b+2*x << '\n' << flush;
            ll g;
            cin >> g;
            if (g == x) {
                b += x;
                z += x;
            } else {
                b += 2*x;
            }
        }

        // final step
        {
            const ll E = 1ll << 29;
            // it's z or z+E 
            if (z == E) {
                // it's E
            } else {
                cout << "? " << E-z << ' ' << 3*E-z << '\n' << flush;
                ll g;
                cin >> g;
                if (g == 2*E) {
                    z += E;
                }
            }
        }

        cout << "! " << z << '\n' << flush;
    }
}