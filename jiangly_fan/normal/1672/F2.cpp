#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        map<int, int> mp;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i += 1) {
            cin >> a[i];
            mp[a[i]] += 1;
        }
        int mx = 0;
        for (auto [x, y] : mp) mx = max(mx, y);
        int s = 0;
        for (auto [x, y] : mp) if (y == mx) s = x;
        for (int i = 0; i < n; i += 1)
            cin >> b[i];
        vector<vector<int>> G(n + 1);
        int ok = 1;
        for (int i = 0; i < n; i += 1)
            if (a[i] != s and b[i] != s)
                G[a[i]].push_back(b[i]);
        vector<int> inq(n + 1), vis(n + 1);
        function<void(int)> DFS = [&](int u) {
            inq[u] = 1;
            vis[u] = 1;
            for (int v : G[u])
                if (inq[v]) {
                    ok = 0;
                }
                else if (not vis[v]) {
                    DFS(v);
                }
            inq[u] = 0;
        };
        for (int i = 1; i <= n; i += 1)
            if (not vis[i]) DFS(i);
        cout << (ok ? "AC\n" : "WA\n");
    }
    return 0;
}