#include <bits/stdc++.h>
const int N = 1000005;
const int M = N << 1;
int n, m, cnt = 1;
int head[N];
int v[M], u[M], nx[M];
inline void add(int uu, int vv) {
    u[++cnt] = uu, v[cnt] = vv, nx[cnt] = head[uu];
    head[uu] = cnt;
}
int cv[M], cu[M], cnx[M];
int cn = 1, ch[N];
inline void cadd(int uu, int vv) {
    cu[++cn] = uu, cv[cn] = vv, cnx[cn] = ch[uu];
    ch[uu] = cn;
}
int low[N], dfn[N], dfc;
int mx, rt;
int st[N], top;
bool ins[N];
int au[M], av[M];
void tarjan(int x, int fe) {
    low[x] = dfn[x] = ++dfc;
    st[++top] = x;
    ins[x] = 1;
    for (int i = head[x]; i; i = nx[i]) {
        if (i == fe) continue;
        if (!dfn[v[i]]) {
            tarjan(v[i], i ^ 1);
            low[x] = std::min(low[x], low[v[i]]);
        } else if (ins[v[i]]) {
            low[x] = std::min(low[x], dfn[v[i]]);
        }
    }
    if (low[x] == dfn[x]) {
        int sz = 0;
        while (st[top + 1] != x) {
            sz++;
            ins[st[top]] = 0;
            top--;
        }
        if (sz > mx) mx = sz, rt = x;
    }
}
bool vis[N];
void dfs2(int x) {
    vis[x] = 1;
    for (int i = head[x]; i; i = nx[i]) {
        if (vis[v[i]]) {
            au[i >> 1] = x;
            av[i >> 1] = v[i];
            continue;
        }
        if (low[v[i]] != low[x]) {
            au[i >> 1] = v[i];
            av[i >> 1] = x;
        } else {
            au[i >> 1] = x;
            av[i >> 1] = v[i];
        }
        dfs2(v[i]);
    }
}
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 1, a, b; i <= m; ++i) {
        std::cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    tarjan(1, 0);
    std::cout << mx << '\n';
    dfs2(rt);
    for (int i = 1; i <= m; ++i) std::cout << au[i] << ' ' << av[i] << '\n';
    return 0;
}