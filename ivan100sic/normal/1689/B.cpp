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
        vector<int> a(n), b(n, -2);
        for (int& x : a) cin >> x, x--;

        if (n == 1) {
            cout << "-1\n";
            continue;
        }

        vector<int> used(n);
        for (int i : ra(0, n-2)) {
            for (int j : ra(0, n)) {
                if (!used[j] && j != a[i]) {
                    used[j] = 1;
                    b[i] = j;
                    break;
                }
            }
        }

        int ux = -1, uy = -1;
        for (int i : ra(0, n)) {
            if (!used[i]) {
                if (ux == -1) {
                    ux = i;
                } else {
                    uy = i;
                }
            }
        }

        b[n-2] = ux;
        b[n-1] = uy;
        if (a[n-2] == b[n-2] || a[n-1] == b[n-1]) {
            swap(b[n-2], b[n-1]);
        }

        for (int x : b) {
            cout << x+1 << ' ';
        }
        cout << '\n';
    }
    
}