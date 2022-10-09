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
        vector<vector<array<int, 3>>> e(n);
        for (int i : ra(1, n)) {
            int p, a, b;
            cin >> p >> a >> b;
            e[p-1].push_back({i, b, a});
        }

        vector z = {0ll};
        ll bsum = 0;

        vector<int> sol(n);

        auto dfs = [&](int x, auto self) -> void {
            sol[x] = R::upper_bound(z, bsum) - begin(z) - 1;
            for (auto [y, a, b] : e[x]) {
                z.push_back(z.back() + a);
                bsum += b;
                self(y, self);
                bsum -= b;
                z.pop_back();
            }
        };

        dfs(0, dfs);
        for (int i : ra(1, n)) {
            cout << sol[i] << " \n"[i == n-1];
        }
    }
}