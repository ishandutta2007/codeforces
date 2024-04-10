// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        set<int> a, b;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            a.insert(x);
        }

        for (int i=0; i<m; i++) {
            int x;
            cin >> x;
            b.insert(x);
        }

        map<int, int> vo, ho;
        map<int, map<int, int>> vg, hg;
        for (int i=0; i<k; i++) {
            int x, y;
            cin >> x >> y;
            bool ac = a.count(x);
            bool bc = b.count(y);

            if (ac && !bc) {
                int z = *b.lower_bound(y);
                vo[z]++;
                vg[z][x]++;
            } else if (!ac && bc) {
                int z = *a.lower_bound(x);
                ho[z]++;
                hg[z][y]++;
            }
        }

        ll sol = 0;
        for (auto& [x, y] : vo) {
            sol += y * (y - 1ll) / 2;
        }

        for (auto& [x, y] : ho) {
            sol += y * (y - 1ll) / 2;
        }

        for (auto& [k, v] : vg) {
            for (auto& [x, y] : v) {
                sol -= y * (y - 1ll) / 2;
            }
        }

        for (auto& [k, v] : hg) {
            for (auto& [x, y] : v) {
                sol -= y * (y - 1ll) / 2;
            }
        }

        cout << sol << '\n';
    }
}