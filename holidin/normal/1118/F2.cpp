#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int LogN = 20;
const long long mod = 998244353;

int m[LogN][N], a[N], t[N], dp[N];
long long d[N][2];
vector <int> v[N], e[N], e1[N];

void dfs(int u, int pr) {
    m[0][u] = pr;
    for (int i = 1; i < LogN; ++i)
        m[i][u] = m[i - 1][m[i - 1][u]];
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr) {
        dp[e[u][i]] = dp[u] + 1;
        dfs(e[u][i], u);
    }
}

int lca(int a, int b) {
    if (dp[a] > dp[b])
        swap(a, b);
    for (int i = LogN - 1; i >= 0; --i)
    if (dp[m[i][b]] >= dp[a])
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

void build_dp(int u, int pr) {
    int y = pr;
    for (int i = 0; i < e1[u].size(); i = i)
    if (e1[u][i] != pr) {
        build_dp(e1[u][i], u);
        ++i;
    } else {
        swap(e1[u][i], e1[u][e1[u].size() - 1]);
        e1[u].resize(e1[u].size() - 1);
    }
    if (a[u] != 0) {
        d[u][1] = 1;
        for (int i = 0; i < e1[u].size(); ++i)
            d[u][1] = (d[u][1] * (d[e1[u][i]][0] + d[e1[u][i]][1])) % mod;
    } else {
        vector <long long> suf, pr;
        pr.resize(e1[u].size() + 1);
        suf.resize(e1[u].size() + 1);
        d[u][0] = 1;
        pr[0] = 1;
        for (int i = 0; i < e1[u].size(); ++i) {
            d[u][0] = (d[u][0] * (d[e1[u][i]][0] + d[e1[u][i]][1])) % mod;
            pr[i + 1] = (pr[i] * (d[e1[u][i]][0] + d[e1[u][i]][1])) % mod;
        }
        d[u][1] = 0;
        suf[e1[u].size()] = 1;
        for (int i = e1[u].size() - 1; i >= 0; --i)
            suf[i] = (suf[i + 1] * (d[e1[u][i]][0] + d[e1[u][i]][1])) % mod;
        for (int i = 0; i < e1[u].size(); ++i)
            d[u][1] = (d[u][1] + (((pr[i] * suf[i + 1]) % mod) * d[e1[u][i]][1]) % mod) % mod;
    }
}

int main() {
    int i, j, n, k, c, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] != 0)
            v[a[i]].push_back(i);
    }
    for (i = 1; i < n; ++i) {
        cin >> c >> b;
        e[c].push_back(b);
        e[b].push_back(c);
    }
    dp[0] = -1;
    dfs(1, 0);
    for (i = 1; i <= k; ++i)
    if (v[i].size() != 0) {
        int u = v[i][0];
        for (j = 1; j < v[i].size(); ++j) {
            int u1 = lca(u, v[i][j]);
            if (u1 != v[i][j]) {
                int p = m[0][v[i][j]];
                while (a[p] == 0 && p != u1) {
                    a[p] = i;
                    p = m[0][p];
                }
                if (p == u1 && a[p] == 0)
                    a[p] = i;
                if (p != 0 && a[p] != i) {
                    cout << 0;
                    return 0;
                }
            }
            if (u != u1) {
                int p = m[0][u];
                while (a[p] == 0 && p != u1) {
                    a[p] = i;
                    p = m[0][p];
                }
                if (p == u1 && a[p] == 0)
                    a[p] = i;
                if (p != 0 && a[p] != i) {
                    cout << 0;
                    return 0;
                }
            }
            u = u1;
        }
    }
    int y = -1;
    for (i = 1; i <= k; ++i)
    if (v[i].size() != 0)
        t[i] = v[i][0];
    for (i = 1; i <= n; ++i)
    for (j = 0; j < e[i].size(); ++j) {
        int u = i, v = e[i][j];
        if (a[u] != 0)
            u = t[a[u]];
        if (a[v] != 0)
            v = t[a[v]];
        if (u != v) {
            y = u;
            e1[u].push_back(v);
        }
    }
    if (y < 0)
        cout << 1;
    else {
        build_dp(y, 0);
        cout << d[y][1];
    }
}