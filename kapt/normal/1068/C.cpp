#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int maxn = 101;
vector<int> g[maxn];
vector<pair<int, int>> ans[maxn];
int now[maxn], deg[maxn];

main() {
    int n, m;
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        deg[i] = g[i].size();
    }
    int up = 1;
    int inf = 1e7;
    // cout << "start" << endl;
    for (int i = 0; i < n; ++i) {
        // cout << i << endl;
        if (deg[i] == 0) {
            ans[i].push_back({i + 1, inf});
            inf++;
            continue;
        }
        now[i] = up;
        int k;
        for (k = up; k < up + deg[i]; ++k) {
            ans[i].push_back({i + 1, k});
        }
        up = k;
        for (int j = 0; j < g[i].size(); ++j) {
            if (g[i][j] <= i) {
                continue;
            }
            ans[g[i][j]].push_back({g[i][j] + 1, now[i]});
            now[i]++;
            deg[g[i][j]]--;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i].size() << "\n";
        for (auto p : ans[i]) {
            cout << p.first << " " << p.second << "\n";
        }
    }
    return 0;
}