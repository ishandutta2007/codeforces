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
        int n, m;
        cin >> n >> m;
        vector<array<int, 3>> a(m);
        for (int i : ra(0, m)) {
            cin >> a[i][1] >> a[i][0];
            a[i][2] = i+1;
        }

        R::sort(a);
        auto b = span(a).subspan(0, 2*n);
        R::sort(b, [](auto& x, auto & y) { return x[1] < y[1]; });
        ll z = 0;
        for (auto& x : b) z += x[0];
        cout << z << '\n';

        for (int i : ra(0, n)) {
            cout << b[i][2] << ' ' << b[2*n-1-i][2] << '\n';
        }
    }
}