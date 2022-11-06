#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long ll;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<lf, lf> pff;

int n;
vector<int> edge[100005];
int dp[100005][2];
vector<int> con[100005][2];
void dfs1(int x, int p) {
    vector<pii> c;
    int sum = 0;
    for (int i : edge[x]) {
        if (i == p) continue;
        dfs1(i, x);
        sum += dp[i][0] + 1;
        c.emplace_back(dp[i][1] - dp[i][0], i);
    }
    sort(c.begin(), c.end());
    dp[x][0] = dp[x][1] = sum;
    if (int(c.size()) > 0) {
        dp[x][0] += c[0].first - 1;
        con[x][0].push_back(c[0].second);
        dp[x][1] += c[0].first - 1;
        con[x][1].push_back(c[0].second);
    }
    if (int(c.size()) > 1) {
        dp[x][0] += c[1].first - 1;
        con[x][0].push_back(c[1].second);
    }
}

int ord;
vector<int> G[100005];
vector<pair<pii, pii>> E;
int dfs2(int x, int p, int c = 0, int o = 0) {
    if (!o) o = ++ord;
    int deg = c;
    for (int i : edge[x]) {
        if (i == p) continue;
        bool in = 0;
        for (int j : con[x][c]) if (i == j) in = 1;
        deg += in;
        int r = dfs2(i, x, in, in ? o : 0);
        if (!in) E.emplace_back(pii(i, x), pii(r, o));
    }
    while (deg++ < 2) G[o].push_back(x);
    return o;
}

int par[100005];
int find(int x) {
    if (par[x]) return par[x] = find(par[x]);
    return x;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        edge[i].clear(), G[i].clear(), par[i] = 0;
        con[i][0].clear();
        con[i][1].clear();
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs1(1, 0);
    printf("%d\n", dp[1][0]);
    ord = 0;
    E.clear();
    dfs2(1, 0);
    for (auto [e1, e2] : E) {
        e2.first = find(e2.first);
        e2.second = find(e2.second);
        printf("%d %d %d %d\n", e1.first, e1.second, G[e2.first][0], G[e2.second][1]);
        G[e2.first][0] = G[e2.second][0];
        par[e2.second] = e2.first;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}