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
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> sol(n);
        bool ok = 1;
        for (int i=1; i<=n; i++) {
            int x = (l+i-1)/i*i;
            if (x > r) {
                ok = 0;
            }
            sol[i-1] = x;
        }

        if (!ok) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int x : sol) cout << x << ' ';
            cout << '\n';
        }
    }
}