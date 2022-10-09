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
        ll n, z=0, o=0;
        cin >> n;
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            if (x == 0) z++;
            else if (x == 1) o++;
        }

        cout << (o << z) << '\n';
    }
}