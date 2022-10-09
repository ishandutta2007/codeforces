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
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        R::sort(a, greater<int>{});
        vector<int> z(n+1);
        for (int i : ra(0, n)) z[i+1] = z[i] + a[i];

        while (q--) {
            int x;
            cin >> x;
            auto it = R::lower_bound(z, x) - begin(z);
            if (it == n+1) {
                it = -1;
            }
            cout << it << '\n';
        }
    }
}