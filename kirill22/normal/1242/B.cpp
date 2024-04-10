#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> g(n);
    vector<set<int>> g2(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].insert(y);
        g[y].insert(x);
    }
    set<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        a.insert({0, i});
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto x = *a.begin();
        a.erase(a.begin());
        if (i == 0) {
            for (auto c : g[x.second]) {
                g[c].erase(x.second);
                a.erase({g2[c].size(), c});
                g2[c].insert(x.second);
                a.insert({g2[c].size(), c});
            }
        }
        else {
            int y = x.second;
            if (g2[y].size() < i) {
                for (auto c : g[y]) {g[c].erase(x.second);
                    a.erase({g2[c].size(), c});
                    g2[c].insert(x.second);
                    a.insert({g2[c].size(), c});
                }
            }
            else {
                ans++;
                for (auto c : g[y]) {g[c].erase(x.second);
                    a.erase({g2[c].size(), c});
                    g2[c].insert(x.second);
                    a.insert({g2[c].size(), c});
                }
            }
        }
    }
    cout << ans;
}