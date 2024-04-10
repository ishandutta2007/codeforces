#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 1;
const int inf  = 1e9;
const int LogN = 20;


vector <int> e[N];
int dp[N], d[N], sz[N], p[N], m[LogN][N];
bool use[N];


int cnt[N];
bool flag = false;

int dfs(int u, int pr) {
    ++cnt[u];
    if (u == 37)
        flag = true;
    sz[u] = 1;
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr && !use[e[u][i]]) {
        dfs(e[u][i], u);
        sz[u] += sz[e[u][i]];
    }
}

int fn(int u, int pr, int s) {
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr && !use[e[u][i]] && 2 * sz[e[u][i]] > s)
        return fn(e[u][i], u, s);
    return u;
}

void find_centroid(int u, int pr) {
    dfs(u, 0);
    int cent = fn(u, 0, sz[u]);
    p[cent] = pr;
    use[cent] = true;
    d[cent] = inf;
    for (int i = 0; i < e[cent].size(); ++i)
    if (!use[e[cent][i]])
        find_centroid(e[cent][i], cent);
}

void dfs1(int u, int pr) {
    m[0][u] = pr;
    for (int i = 1; i < LogN; ++i)
        m[i][u] = m[i - 1][m[i - 1][u]];
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr) {
        dp[e[u][i]] = dp[u] + 1;
        dfs1(e[u][i], u);
    }
}

int lca(int a, int b) {
    if (dp[a] > dp[b])
        swap(a, b);
    for (int i = LogN - 1; i >= 0; --i)
    if (dp[a] <= dp[m[i][b]])
        b = m[i][b];
    if (a == b)
        return a;
    for (int i = LogN - 1; i >= 0; --i)
    if (m[i][a] != m[i][b]) {
        a = m[i][a];
        b = m[i][b];
    }
    return m[0][a];
}

int r(int a, int b) {
    int u = lca(a, b);
    return dp[a] + dp[b] - 2 * dp[u];
}

void kr(int u) {
    int v = u;
    int cnt = 0;
    while (u != 0) {
        ++cnt;
        d[u] = min(d[u], r(u, v));
        u = p[u];
    }
}

int mn(int u) {
    int v = u;
    int ans = inf;
    while (u != 0) {
        ans = min(ans, r(u, v) + d[u]);
        u = p[u];
    }
    return ans;
}

int main() {
    int i, j, k, n, q, a, b, t, x;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (i = 1; i < n; ++i) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    find_centroid(1, 0);
    dfs1(1, 0);
    kr(1);
    for (i = 0; i < q; ++i) {
        cin >> t >> x;
        if (t == 1)
            kr(x);
        else
            cout << mn(x) << "\n";
    }
}