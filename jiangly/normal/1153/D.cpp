#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> m(n);
    for (int i = 0; i < n; ++i)
        cin >> m[i];
    vector<int> sz(n);
    vector<vector<int>> e(n);
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        e[--p].push_back(i);
    }
    function<int(int)> dfs = [&](int u) {
        if (e[u].empty()) {
            sz[u] = 1;
            return 1;
        }
        int x = 0;
        if (m[u] == 1)
            x = n;
        sz[u] = 0;
        for (int v : e[u]) {
            int y = dfs(v);
            sz[u] += sz[v];
            if (m[u] == 1)
                x = min(x, sz[v] - y);
            else
                x += y - 1;
        }
        if (m[u] == 1)
            return sz[u] - x;
        else
            return x + 1;
    };
    cout << dfs(0) << endl;
    return 0;
}