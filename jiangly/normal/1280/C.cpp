#include <bits/stdc++.h>
using namespace std;
constexpr int N = 100'000;
vector<pair<int, int>> e[2 * N];
int n;
int sz[2 * N];
long long ans1, ans2;
void dfs(int u, int p) {
    sz[u] = 1;
    for (auto ed : e[u]) {
        int v, l;
        tie(v, l) = ed;
        if (v == p)
            continue;
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] % 2 == 1)
            ans1 += l;
        ans2 += 1LL * l * min(sz[v], 2 * n - sz[v]);
    }
}
void solve() {
    cin >> n;
    for (int i = 0; i < 2 * n - 1; ++i) {
        int u, v, l;
        cin >> u >> v >> l;
        --u;
        --v;
        e[u].emplace_back(v, l);
        e[v].emplace_back(u, l);
    }
    dfs(0, -1);
    cout << ans1 << " " << ans2 << "\n";
    ans1 = ans2 = 0;
    for (int i = 0; i < 2 * n; ++i)
        e[i].clear();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}