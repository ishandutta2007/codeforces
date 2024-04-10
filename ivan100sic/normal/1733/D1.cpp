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
        int n, x, y;
        string a, b;
        cin >> n >> x >> y >> a >> b;
        vector<int> c;
        for (int i : ra(0, n)) {
            if (a[i] != b[i]) {
                c.push_back(i);
            }
        }

        if (c.empty()) {
            cout << "0\n";
            continue;
        }

        if (c.size() % 2) {
            cout << "-1\n";
            continue;
        }

        ll sol = 0;
        if (c.size() > 2) {
            sol = ssize(c) / 2 * y;
        } else {
            if (c[1] - c[0] > 1) {
                sol = y;
            } else {
                if (n == 3) {
                    sol = 2*x;
                } else if (n == 4 && c[0] == 1 && c[1] == 2) {
                    sol = min(x+y, 3*y);
                } else {
                    sol = min(x, 2*y);
                }
            }
        }

        cout << sol << '\n';
    }
    
}