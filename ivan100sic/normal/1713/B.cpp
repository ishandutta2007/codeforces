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
        vector<int> a(n);
        for (int& x : a) cin >> x;

        ll z = 0;
        for (int i : ra(0, n-1)) {
            z += abs(a[i] - a[i+1]);
        }

        z += a[0] + a[n-1];

        if (z == 2 * *R::max_element(a)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}