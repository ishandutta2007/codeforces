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

        vector<int> deg(n), a(n);
        vector<pair<int, int>> e(m);
        
        for (int i : ra(0, n)) {
            cin >> a[i];
        }

        for (int i : ra(0, m)) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            deg[x]++;
            deg[y]++;
            e[i] = {x, y};
        }

        if (m % 2 == 0) {
            cout << "0\n";
        } else {
            int sol = 1123123123;
            for (int i : ra(0, n)) {
                if (deg[i] % 2) {
                    sol = min(sol, a[i]);
                }
            }

            for (auto [x, y] : e) {
                if (deg[x] % 2 == 0 && deg[y] % 2 == 0) {
                    sol = min(sol, a[x] + a[y]);
                }
            }

            cout << sol << '\n';
        }
    }
}