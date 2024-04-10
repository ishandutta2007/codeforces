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
        vector<array<int, 2>> a(n);
        for (auto& [x, f] : a) cin >> x, f = 1;

        for (int i : ra(0, n-1)) {
            vector<array<int, 2>> b, s;

            auto add = [&](int x, int y) {
                if (b.size() && b.back()[0] == x) {
                    b.back()[1] += y;
                } else {
                    b.push_back({x, y});
                }
            };

            for (int j : ra(0, ssize(a))) {
                // self
                if (a[j][1] > 1) {
                    add(0, a[j][1] - 1);
                }
                // neighbors
                if (j + 1 < ssize(a)) {
                    add(a[j+1][0] - a[j][0], 1);
                }
            }

            R::sort(b);
            swap(b, s);
            for (auto [x, y] : s) {
                add(x, y);
            }

            swap(a, b);
        }

        cout << a[0][0] << '\n';
    }
}