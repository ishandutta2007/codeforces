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
        int a[3];
        cin >> a[0] >> a[1] >> a[2];

        bool f = 0;
        for (int i : ra(0, 3)) {
            int x = a[i], y = a[(i+1)%3], z = a[(i+2)%3];

            if (x % 2 == 0 && y == z) {
                f = 1;
            }
            
            if (x == y + z) {
                f = 1;
            }
        }

        cout << (f ? "YES\n" : "NO\n");
    }
    
}