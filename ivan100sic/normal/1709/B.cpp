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

    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n), c(n);
    for (int i : ra(0, n)) {
        cin >> a[i];
        if (i > 0) {
            b[i] = b[i-1] + max(0ll, a[i-1] - a[i]);
            c[i] = c[i-1] + max(0ll, a[i] - a[i-1]);
        }
    }

    while (m--) {
        int s, t;
        cin >> s >> t;
        if (s < t) {
            cout << b[t-1]-b[s-1] << '\n';
        } else {
            cout << c[s-1]-c[t-1] << '\n';
        }
    }
}