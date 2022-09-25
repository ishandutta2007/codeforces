#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    for (cin >> T; T; T -= 1) {
        int n;
        cin >> n;
        vector<vector<int>> G(n + 1);
        for (int i = 1, u, v; i < n; i += 1) {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int ans = 1;
        function<int(int, int)> dfs = [&](int u, int par) {
            int c = 0;
            for (int v : G[u]) if (v != par) {
                c += dfs(v, u);
            }
            if (c) ans += c - 1;
            return not c;
        };
        dfs(1, 0);
        cout << ans << "\n";
    }
    return 0;
}