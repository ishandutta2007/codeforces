#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 600;
int d[MAXN][MAXN];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = MAXN;
            }
        }
        vector<array<int, 3>> ed;
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            d[u][v] = d[v][u] = 1;
            ed.push_back({u, v, w});
            ed.push_back({v, u, w});
        }
        for (int i = 0; i < n; ++i) {
            d[i][i] = 0;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        int ans = 1e18;
        for (auto e : ed) {
            ans = min(ans, e[2] * (d[0][e[0]] + d[n - 1][e[1]] + 1));
        }
        for (auto e : ed) {
            int u = e[0], v = e[1], w = e[2];
            for (int i = 0; i < n; ++i) {
                int dst = d[u][i] + d[i][0] + d[i][n - 1] + 2;
                ans = min(ans, w * dst);
            }
        }
        cout << ans << endl;
    }
    return 0;
}