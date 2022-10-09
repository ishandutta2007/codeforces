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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == c || b == d) {
            cout << abs(a-c) + abs(b-d) << '\n';
        } else {
            cout << abs(a-c) + abs(b-d) + 2 << '\n';
        }
    }
    
}