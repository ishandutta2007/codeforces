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
        ll n, x, y;
        cin >> n >> x >> y;
        for (int i : ra(0, n)) {
            ll t;
            cin >> t;
            x ^= t;
        }        

        x ^= y;
        if (x & 1) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }
}