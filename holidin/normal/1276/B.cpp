#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 3e5 + 1;
const int inf = 1e9;
vector <int> e[N];
int h[N], deep[N], sz[N];

int rss = 0;
int where_b;
int a, b;

void dfs(int u, int pr) {
    h[u] = deep[u];
    sz[u] = 1;
    if (u == b)
        rss = 1;
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr && deep[e[u][i]] == 0) {
        deep[e[u][i]] = deep[u] + 1;
        dfs(e[u][i], u);
        if (a == u)
            if (rss == 1) {
                where_b = e[u][i];
                rss = 2;
            }
        sz[u] += sz[e[u][i]];
        h[u] = min(h[u], h[e[u][i]]);
    } else if (deep[e[u][i]] < deep[u])
            h[u] = min(h[u], deep[e[u][i]]);
}

void solve() {
    int i, j, k, n, l, a1, b1;
    cin >> n >> k;
    cin >> a >> b;
    for (i = 1; i <= n; ++i) {
        e[i].clear();
        deep[i] = 0;
    }
    set <pair<int, int> > s;
    for (i = 0; i < k; ++i) {
        cin >> a1 >> b1;
        if (a1 > b1)
            swap(a1, b1);
        if (s.find({a1, b1}) != s.end())
            continue;
        s.insert({a1, b1});
        e[a1].push_back(b1);
        e[b1].push_back(a1);
    }
    deep[a] = 1;
    rss =0;
    dfs(a, 0);
    int xl = 0, xr = 0;
    for (int i = 0; i < e[a].size(); ++i)
    if (deep[e[a][i]] == deep[a] + 1 && h[e[a][i]] >= deep[a] && e[a][i] != where_b)
        xl += sz[e[a][i]];
    for (int i = 0; i < e[b].size(); ++i)
    if (deep[e[b][i]] == deep[b] +1  && h[e[b][i]] >= deep[b])
        xr += sz[e[b][i]];
    cout << xl * xr << "\n";
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test;
    cin >> test;
    for (int i = 0; i < test; ++i)
    solve();
}