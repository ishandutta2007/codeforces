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
        if (k == 1 || n % 2 == 0) {
            cout << "YES\n";
            for (int i : ra(0, n)) {
                for (int j : ra(0, k)) {
                    cout << 1+i+n*j << ' ';
                }
                cout << '\n';
            }
        } else {
            cout << "NO\n";
        }
    }
}