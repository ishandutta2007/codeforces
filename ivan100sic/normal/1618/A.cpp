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
        int a[7];
        for (int& x : a) cin >> x;

        cout << a[0] << ' ' << a[1] << ' ' << a[6] - a[0] - a[1] << '\n';
    }
    
}