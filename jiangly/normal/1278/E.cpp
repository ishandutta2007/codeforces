#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> e(n);
    vector<int> l(n), r(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int dfsNow = 1;
    l[0] = 1;
    function<void(int, int)> dfs = [&](int u, int p) {
        for (int v : e[u])
            if (v != p)
                l[v] = ++dfsNow;
        r[u] = ++dfsNow;
        reverse(e[u].begin(), e[u].end());
        for (int v : e[u])
            if (v != p)
                dfs(v, u);
    };
    dfs(0, -1);
    for (int i = 0; i < n; ++i)
        cout << l[i] << " " << r[i] << "\n";
    return 0;
}