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
        string s;
        cin >> s;
        int z = R::count(s, '0');
        int n = ssize(s);
        if (2*z != n) {
            cout << min(z, n-z) << '\n';
        } else {
            cout << z-1 << '\n';
        }
    }
    
}