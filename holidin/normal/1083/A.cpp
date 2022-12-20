#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 1;

long long dpv[N], w[N], ans = 0;
vector <pair<int, int> > e[N];

void dfs1(int u, int pr) {
    dpv[u] = 0;
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i].fi != pr) {
        dfs1(e[u][i].fi, u);
        dpv[u] = max(dpv[u], dpv[e[u][i].fi] - e[u][i].se);
    }
    dpv[u] += w[u];
}

void dfs2(int u, int pr, long long x) {
    vector <long long> v;
    x = max(x, (long long)0);
    ans = max(ans, x + w[u]);
    v.push_back(x);
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i].fi != pr)
        v.push_back(dpv[e[u][i].fi] - e[u][i].se);
    sort(v.begin(), v.end());
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i].fi != pr)
        if (dpv[e[u][i].fi] - e[u][i].se == v[v.size() - 1])
            dfs2(e[u][i].fi, u, v[v.size() - 2] - e[u][i].se + w[u]);
        else
            dfs2(e[u][i].fi, u, v[v.size() - 1] - e[u][i].se + w[u]);
}

int main() {
    int i, j, k, n, a, b, c;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> w[i];
    for (i = 1; i < n; ++i) {
        cin >> a >> b >> c;
        e[a].push_back({b, c});
        e[b].push_back({a, c});
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    cout << ans;
}