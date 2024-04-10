// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

void cmp(ll x, ll y) {
    if (x > y) {
        cout << ">";
    } else if (x < y) {
        cout << "<";
    } else {
        cout << "=";
    }
    cout << '\n';
}

ll pw(ll x) {
    ll z = 1;
    while (x--) z *= 10;
    return z;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        ll x1, p1, x2, p2;
        cin >> x1 >> p1 >> x2 >> p2;

        if (p1 - p2 > 7) {
            cout << ">\n";
        } else if (p2 - p1 > 7) {
            cout << "<\n";
        } else if (p1 > p2) {
            x1 *= pw(p1 - p2);
            cmp(x1, x2);
        } else {
            x2 *= pw(p2 - p1);
            cmp(x1, x2);
        }
    }
    
}