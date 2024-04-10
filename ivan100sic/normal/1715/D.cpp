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

    int n, q;
    cin >> n >> q;

    vector<vector<pair<int, int>>> e(n);

    const int ALL = (1 << 30) - 1;

    for (int i : ra(0, q)) {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        e[y].emplace_back(x, w);
        e[x].emplace_back(y, w);
    }

    vector<int> a(n), v(n);

    // set zeros on zero links and ones on self links
    for (int i : ra(0, n)) {
        for (auto [j, w] : e[i]) {
            if (j == i) {
                // self link
                a[i] = w;
                v[i] = ALL;
            } else {
                v[i] |= ALL ^ w;
            }
        }
    }

    for (int i : ra(0, n)) {
        // process one links
        int z = 0, p = 0;

        for (auto [j, w] : e[i]) {
            if (j == i) {
                continue;
            }

            // known zero in neighbors?
            int kz = v[j] & (ALL ^ a[j]) & w;

            // set that to one
            v[i] |= kz;
            a[i] |= kz;
        }

        // set rest to zero
        v[i] = ALL;
    }

    for (int x : a) cout << x << ' ';
    cout << '\n';
}