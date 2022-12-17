#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 1;
vector <pair<int, pair<int, int> > > e[N];
vector <int> ans;
int d[N], tout[N], top = 0;
bool flag = false;

void dfs(int u, int x) {
    d[u] = 1;
    for (int i = 0; i < e[u].size(); ++i)
    if (d[e[u][i].fi] == 0 && e[u][i].se.fi > x) {
        dfs(e[u][i].fi, x);
    }
    ++top;
    tout[u] = top;
}

int main() {
    int i, j, n, k, a, b, c;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 1; i <= k; ++i) {
        cin >> a >> b >> c;
        e[a].push_back({b, {c, i}});
    }
    int l = 0, r = 1e9 + 1;
    while (r - l > 1) {
        int x = (l + r) / 2 - 1;
        for (i = 1; i <= n; ++i)
            d[i] = 0;
        bool can = true;
        for (i = 1; i <= n; ++i)
        if (d[i] == 0)
            dfs(i, x);
        for (i = 1; i <= n; ++i)
        for (j = 0; j < e[i].size(); ++j)
        if (tout[e[i][j].fi] > tout[i] && e[i][j].se.fi > x)
            can = false;
        if (can)
            r = x + 1;
        else
            l = x + 1;
        top = 0;
    }
    for (i = 1; i <= n; ++i)
        d[i] = 0;
    flag = true;
    for (i = 1; i <= n; ++i)
    if (d[i] == 0)
        dfs(i, l);
    for (i = 1; i <= n; ++i)
    for (j = 0; j < e[i].size(); ++j)
    if (tout[e[i][j].fi] > tout[i])
        ans.push_back(e[i][j].se.se);
    cout << l << ' ' << ans.size() << "\n";
    for (i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
}