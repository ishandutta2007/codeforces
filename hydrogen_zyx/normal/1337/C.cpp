#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int> g[300000];
int sub[300000], deep[300000], deg[300000], fa[300000];
priority_queue<pair<int, int> > que;

void dfs(int u, int f, int d) {
    fa[u] = f;
    deep[u] = d;
    for (auto v : g[u]) {
        if (v == f) continue;
        deg[u]++;
        dfs(v, u, d + 1);
    }
    if (deg[u] == 0) {
        que.push(pair<int, int>(d, u));
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1, 0);
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        pair<int, int> p = que.top();
        que.pop();
        ans += p.first;
        if (fa[p.second] == -1) continue;
        deg[fa[p.second]]--;
        sub[fa[p.second]] += sub[p.second] + 1;
        if (deg[fa[p.second]] == 0) {
            que.push(pair<int, int>(deep[fa[p.second]] - sub[fa[p.second]],
                                    fa[p.second]));
        }
    }
    cout << ans;
}