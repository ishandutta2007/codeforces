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
        vector<int> a(n), b(n);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;

        ll sol = 0;
        for (int i : ra(0, n-1)) {
            sol += min(
                abs(a[i] - a[i+1]) + abs(b[i] - b[i+1]),
                abs(a[i] - b[i+1]) + abs(b[i] - a[i+1])
            );
        }

        cout << sol << '\n';
    }
}