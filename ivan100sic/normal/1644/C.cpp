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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int& x : a) {
            cin >> x;
        }

        vector<int> d(n+1, -2e9);
        for (int i : ra(0, n)) {
            int z = 0;
            for (int j : ra(i+1, n+1)) {
                z += a[j-1];
                d[j-i] = max(d[j-i], z);
            }
        }

        for (int i : ra(0, n+1)) {
            int h = 0;
            for (int j : ra(0, n+1)) {
                h = max(h, d[j] + x*min(i, j));
            }
            cout << h << ' ';
        }
        cout << '\n';
    }
}