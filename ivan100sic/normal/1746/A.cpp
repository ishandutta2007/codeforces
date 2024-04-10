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
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            z |= x;
        }

        cout << (z ? "YES\n" : "NO\n");
    }
    
}