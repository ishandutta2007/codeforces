#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<vector<int>> G(n + 1);
        vector<int> ans(n + 1);
        for (int i = 1, u, v; i < n; i += 1) {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        function<void(int, int)> DFS = [&](int u, int p) {
            for (int v : G[u]) if (v != p) {
                ans[v] = -ans[u];
                DFS(v, u);
            }
        };
        ans[1] = -1;
        DFS(1, 0);
        for (int i = 1; i <= n; i += 1) cout << ans[i] * (int)G[i].size() << " ";
        cout << "\n";
    }
    return 0;
}