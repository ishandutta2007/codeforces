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
        int n, z = 0, h = 0;
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            h = max(h, x);
            if (h == i) {
                z++;
            }
        }

        cout << z << '\n';
    }
    
}