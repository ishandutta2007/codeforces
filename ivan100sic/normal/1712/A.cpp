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
        int n, k, z = 0;
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (x > k && i <= k) z++;
        }
        cout << z << '\n';
    }
    
}