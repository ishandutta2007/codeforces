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
        if (k > (n+1) / 2) {
            cout << "-1\n";
        } else {
            for (int i : ra(0, n)) {
                for (int j : ra(0, n)) {
                    if (i == j && i % 2 == 0 && i/2 < k) {
                        cout << 'R';
                    } else {
                        cout << '.';
                    }
                }
                cout << '\n';
            }
        }
    }
}