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
        vector<vector<pair<int, int>>> e(n);
        for (int i : ra(0, n-1)) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            e[x].emplace_back(y, i);
            e[y].emplace_back(x, i);
        }

        int ok = 1;
        for (int i : ra(0, n)) {
            if (e[i].size() > 2) {
                ok = 0;
            }
        }
        
        if (!ok) {
            cout << "-1\n";
            continue;
        }

        vector<int> sol(n-1);
        
        auto dfs = [&](auto self, int x, int p, int c) -> void {
            for (auto [y, id] : e[x]) {
                if (y == p) continue;
                sol[id] = c;
                self(self, y, x, 5-c);
            }
        };

        int root = *R::find_if(ra(0, n), [&](int x) { return e[x].size() == 1; });
        dfs(dfs, root, root, 3);

        for (int x : sol) cout << x << ' ';
        cout << '\n';
    }
}