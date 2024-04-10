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
        int n, b, x, y;
        cin >> n >> b >> x >> y;
        ll z = 0;
        int t = 0;
        for (int i : ra(0, n)) {
            if (t + x <= b) {
                t += x;
            } else {
                t -= y;
            }
            z += t;
        }
        cout << z << '\n';
    }
}