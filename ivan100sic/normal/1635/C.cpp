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

        vector<array<int, 3>> b;
        auto can = [&]() {
            if (a[n-2] > a[n-1]) return false;
            int w = a[n-2] - a[n-1], h = max(a[n-1], a[n-2]);
            int wi = n-2, wj = n-1, hi = a[n-1] > a[n-2] ? n-1 : n-2;
            for (int i=n-3; i>=0; i--) {
                if (a[i] > a[i+1]) {
                    a[i] = w;
                    b.push_back({i, wi, wj});
                }
                if (w > a[i] - h) {
                    w = a[i] - h;
                    wi = i;
                    wj = hi;
                }

                if (h < a[i]) {
                    h = a[i];
                    hi = i;
                }
            }
            return R::is_sorted(a);
        };

        if (!can()) {
            cout << "-1\n";
        } else {
            cout << size(b) << '\n';
            for (auto [x, y, z] : b) {
                cout << x+1 << ' ' << y+1 << ' ' << z+1 << '\n';
            }
        }
    }
}