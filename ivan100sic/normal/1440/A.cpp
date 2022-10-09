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
        int n, c0, c1, h;
        cin >> n >> c0 >> c1 >> h;
        
        string s;
        cin >> s;

        int k0 = R::count(s, '0');
        int k1 = R::count(s, '1');

        cout << k0 * min(c0, c1 + h) + k1 * min(c1, c0 + h) << '\n';
    }
    
}