#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    set<int> g[n], g2[n];
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].insert(y);
        g2[y].insert(x);
    }
    auto F = [&] (int x) {
        for (auto y : g[x]) {
            g2[y].erase(x);
        }
        for (auto y : g2[x]) {
            g[y].erase(x);
        }
        g[x].clear();
        g2[x].clear();
    };
    auto get = [&] (int x) {
        if (g2[x].size() == 0) return 1;
        for (auto v : g2[x]) {
            if (g2[v].size() != 0) return 3;
        }
        return 2;
    };
    set<int> ans;
    for (int i = 0; i < n; i++) {
        while (g[i].size() > 0) {
            int v = *g[i].begin();
            g[i].erase(v);
            if (g[v].size() == 0) continue;
            if (get(v) == 3) {
                F(v);
                ans.insert(v);
                continue;
            }
            if (g[v].size() == 1) {
                int x = *g[v].begin();
                F(x);
                ans.insert(x);
                continue;
            }
            int x = *g[v].begin(), y = *g[v].rbegin();
            int res = g[x].size() * ((int) g2[x].size() - 1);
            int res2 = g[y].size() * ((int) g2[y].size() - 1);
            if (res + res2 <= 1 || (res + res2 == 2 && rand() % 3 == 0)) {
                F(v);
                ans.insert(v);
                continue;
            }
            F(x), F(y);
            ans.insert(x);
            ans.insert(y);
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans) cout << x + 1 << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}