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
        int n, h, m;
        cin >> n >> h >> m;
        int t = h * 60 + m, sol = 1440;
        for (int i : ra(0, n)) {
            int h, m;
            cin >> h >> m;
            int t2 = h * 60 + m;
            sol = min(sol, (t2 + 1440 - t) % 1440);
        }

        cout << sol / 60 << ' ' << sol % 60 << '\n';
    }
}