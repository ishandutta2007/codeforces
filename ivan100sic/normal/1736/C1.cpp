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
        int n;
        cin >> n;
        int f = 0;
        ll sol = n*(n+1ll)/2;
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            f = max(f, (i+1)-x);
            sol -= f;
        }

        cout << sol << '\n';
    }
    
}