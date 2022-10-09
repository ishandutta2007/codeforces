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
        int n, k;
        cin >> n >> k;
        if (k % 2 == 1) {
            cout << "YES\n";
            for (int i : ra(0, n/2)) {
                cout << 2*i+1 << ' ' << 2*i+2 << '\n';
            }
        } else if (k % 4 == 2) {
            cout << "YES\n";
            for (int i : ra(0, n/4)) {
                cout << 4*i+2 << ' ' << 4*i+1 << '\n';
                cout << 4*i+3 << ' ' << 4*i+4 << '\n';
            }

            if (n % 4) {
                cout << n << ' ' << n-1 << '\n';
            }
        } else {
            cout << "NO\n";
        }
    }
}