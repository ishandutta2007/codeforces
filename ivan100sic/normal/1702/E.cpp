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
        vector<int> a(n), e(n);
        vector<vector<int>> g(n);
        for (int i : ra(0, n)) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            e[x]++;
            e[y]++;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        bool ok = 1;

        vector<int> col(n, -1);

        auto dfs = [&](int x, int c, auto self) -> void {
            if (col[x] != -1 && col[x] != c) {
                ok = false;
            }

            if (col[x] != -1) return;

            col[x] = c;
            for (int y : g[x]) {
                self(y, 1-c, self);
            }
        };

        for (int i : ra(0, n)) {
            if (col[i] == -1) {
                dfs(i, 0, dfs);
            }
        }

        if (R::count(e, 2) == n && ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}