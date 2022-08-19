#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> deg(n);
    vector<vector<int>> up(n);
    LL ans = 0;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if (a > b)
            swap(a, b);
        ++deg[a];
        ++deg[b];
        up[a].push_back(b);
    }
    for (int i = 0; i < n; ++i)
        ans += 1ll * up[i].size() * (deg[i] - up[i].size());
    printf("%lld\n", ans);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int u;
        cin >> u;
        --u;
        ans -= 1ll * up[u].size() * (deg[u] - up[u].size());
        for (int v : up[u]) {
            ans += deg[v] - 2 * (int)up[v].size() - 1;
            up[v].push_back(u);
        }
        up[u].clear();
        printf("%lld\n", ans);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}