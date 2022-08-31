#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL INFLL = 1E18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> c(3);
    for (int i = 0; i < 3; ++i) {
        c[i].resize(n);
        for (int j = 0; j < n; ++j) cin >> c[i][j];
    }
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i)
        if (g[i].size() >= 3) {
            cout << "-1\n";
            return 0;
        }
    int s = 0, t = 0;
    while (g[s].size() == 2) ++s;
    t = g[s][0];
    vector<int> p {s, t};
    while (g[t].size() == 2) {
        s = g[t][0] == s ? g[t][1] : g[t][0];
        swap(s, t);
        p.push_back(t);
    }
    LL ans = INFLL;
    vector<int> color(n), _co(n);
    for (int x = 0; x < 3; ++x)
        for (int y = 0; y < 3; ++y) {
            if (x == y) continue;
            LL sum = 0;
            int co[3] = {x, y, 3 ^ x ^ y};
            for (int i = 0; i < n; ++i) {
                _co[p[i]] = co[i % 3];
                sum += c[_co[p[i]]][p[i]];
            }
            if (sum < ans) {
                ans = sum;
                color = _co;
            }
        }
    cout << ans << "\n";
    for (int i = 0; i < n; ++i) cout << color[i] + 1 << " \n"[i == n - 1];
    return 0;
}