#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using Uint = uint32_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
int n, m, ans;
bool g[7][7], a[7][7];
int v[7];
void dfs(int x) {
    if (x == n) {
        memset(a, 0, sizeof(a));
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (g[i][j]) {
                    int x = v[i], y = v[j];
                    if (x > y)
                        swap(x, y);
                    a[x][y] = true;
                }
        ans = max(ans, accumulate(&a[0][0], &a[0][0] + 49, 0));
        return;
    }
    for (int i = 0; i < 6; ++i) {
        v[x] = i;
        dfs(x + 1);
    }
}
void solve(int case_id) {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u][v] = true;
    }
    dfs(0);
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; ++i)
        solve(i);
    return 0;
}