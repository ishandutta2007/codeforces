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
        vector<int> x(n), y(n);
        for (int i : ra(0, n)) {
            cin >> x[i] >> y[i];
        }

        int sol = -1;
        for (int i : ra(0, n)) {
            bool ok = true;
            for (int j : ra(0, n)) {
                if (abs(x[i] - x[j]) + abs(y[i] - y[j]) > k) {
                    ok = false;
                    break;
                }
            }
            if (ok) sol = 1;
        }

        cout << sol << '\n';
    }
    
}