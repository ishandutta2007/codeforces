#include <bits/stdc++.h>

#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template <typename T>
inline bool chkmin(T &a, const T &b) {
    return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
    return a < b ? a = b, 1 : 0;
}
template <typename T>
inline bool smin(T &a, const T &b) {
    return a > b ? a = b : a;
}
template <typename T>
inline bool smax(T &a, const T &b) {
    return a < b ? a = b : a;
}

using int64 = long long;

const int N = 30005;

int Size[N], mark[N], cyc[N];

int64 dp[N], Alo[N];

std::vector<int> c;
std::vector<int> adj[N];

int Dfs1(int v, int p = -1) {
    if (mark[v]++) return v + 1;
    for (int u : adj[v]) {
        if (u != p) {
            int Man = Dfs1(u, v);
            if (Man == -1) return -1;
            if (Man) {
                cyc[v] = 1, c.push_back(v);
                if (v + 1 == Man) return -1;
                return Man;
            }
        }
    }
    return 0;
}

int n, par[N];

void Dfs2(int v, int p = -1) {
    Size[v] = 1, par[v] = p;
    for (int u : adj[v]) {
        if (u != p && !cyc[u]) Dfs2(u, v), Size[v] += Size[u], Alo[v] += Alo[u] + Size[u];
    }
}

int Rev[N], Sum[N];

int main() {
    std::cin >> n;
    for (int j = 0, u, v; j < n; ++j) std::cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
    Dfs1(0);
    for (int cur : c) Dfs2(cur);
    for (int j = 0; j < (int)c.size(); ++j) Rev[c[j]] = j;
    int m = (int)c.size();
    for (int j = 0; j < m; ++j) c.push_back(c[j]);
    for (int j = 0; j < 2 * m; ++j) Sum[j + 1] = Sum[j] + Size[c[j]];
    for (int Size = 1; Size <= m - 1; ++Size) {
        if (Size == 1) {
            for (int j = 0; j < 2 * m; ++j) {
                int cur = c[j];
                dp[j] = ::Size[cur] + Alo[cur];
            }
        } else {
            for (int j = 0; j + Size - 1 < 2 * m; ++j) {
                int sum_all = Sum[j + Size] - Sum[j], nx = c[j + Size - 1];
                dp[j] = std::max(dp[j] + sum_all + Alo[nx], dp[j + 1] + sum_all + Alo[c[j]]);
            }
        }
    }
    int64 Res = 0;
    for (int stv = 0; stv < n; ++stv) {
        int v = stv;
        int64 Cures = 0, tAd = 0;
        while (par[v] != -1) Cures += n - tAd, Cures -= Size[v], tAd = Size[v], v = par[v];
        Cures += Alo[v], Cures += n - tAd;
        Cures += dp[Rev[v] + 1], Res = std::max(Res, Cures);
    }
    std::cout << Res << std::endl;
    return 0;
}