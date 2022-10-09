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
        vector<vector<int>> e(n);
        for (int i : ra(1, n)) {
            int p;
            cin >> p;
            p--;
            e[p].push_back(i);
        }

        vector<pair<ll, ll>> a(n);
        for (auto& [l, r] : a) {
            cin >> l >> r;
        }

        int sol = 0;
        auto dfs = [&](int x, auto self) -> ll {
            ll sum = 0;
            for (int y : e[x]) {
                sum += self(y, self);
            }

            if (sum < a[x].first) {
                sol++;
                return a[x].second;
            } else {
                return min(sum, a[x].second);
            }
        };

        dfs(0, dfs);
        cout << sol << '\n';
    }
}