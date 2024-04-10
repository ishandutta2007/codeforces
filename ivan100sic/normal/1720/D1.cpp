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
        vector<int> a(n), d(n, 1);
        for (int& x : a) cin >> x;

        for (int j : ra(1, n)) {
            for (int i : ra(max(0, j-514), j)) {
                if ((a[i] ^ j) < (a[j] ^ i)) {
                    d[j] = max(d[j], d[i] + 1);
                }
            }
        }

        cout << R::max(d) << '\n';
    }
}