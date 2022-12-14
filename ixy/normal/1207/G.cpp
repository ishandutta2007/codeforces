#include <bits/stdc++.h>

inline int readAlpha() {
    char c; for (c = getchar(); !isalpha(c); c = getchar()); return c;
}

const int N = 1e6 + 5, C = 26;

int n, m, qq, np, tms, idi, ans[N], pos[N], dfn[N], siz[N];
std::vector<int> q[N], qi[N], to[N];
char st[N << 2], str[N << 2];

int id[N], idq[N];

struct List {
    int tot, fst[N], nxt[N], to[N]; char val[N];

    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int v, char w) {
        nxt[tot] = fst[u]; to[tot] = v; val[tot] = w; fst[u] = tot++;
    }
} e;

struct FenwickTree {
    int n, f[N];

    inline void modify(int u, int x) { for (; u <= n; u += u & -u) { f[u] += x; } }
    inline int query(int u) { int res = 0; for (; u; u ^= u & -u) { res += f[u]; } return res; }
    inline int query(int l, int r) { return query(r) - query(l - 1); }
} fwt;

struct AcAutomaton {
    int tot, fa[N], fail[N], son[N][C];

    AcAutomaton() { memset(son[0], -1, C << 2); tot = 1; }
    void build() {
        std::queue<int> que;
        for (int i = 0; i < C; i++) { if (son[1][i]) { que.push(son[1][i]); fail[son[1][i]] = 1; } }
        for (int u, v; !que.empty(); que.pop()) {
            u = que.front();
            for (int i = 0; i < C; i++) {
                if (son[u][i]) {
                    que.push(son[u][i]); v = fail[u];
                    for (; !son[v][i]; v = fail[v]);
                    fail[son[u][i]] = v ? son[v][i] : 1;
                } else { son[u][i] = son[fail[u]][i]; }
            }
        }
    }
    void buildTree() {
        for (int i = 2; i <= tot; i++) { to[fail[i]].push_back(i); }
    }
} aam;

int dfs(int u) {
    dfn[u] = ++tms; siz[u] = 1;
    for (auto v : to[u]) { siz[u] += dfs(v); } return siz[u];
}

void dfs1(int u) {
    if (u) {
        str[++n] = 'P';
        id[u] = ++idi;
    }
    for (int i = e.fst[u], v; ~i; i = e.nxt[i]) {
        v = e.to[i]; char w = e.val[i];
        str[++n] = w;
        dfs1(v);
        str[++n] = 'B';
    }
}

int main() {
    scanf("%d", &qq);
    for (int i = 1; i <= qq; i++) {
        int opt, u; scanf("%d", &opt);
        if (opt == 1) {
            u = 0;
        } else {
            scanf("%d", &u);
        }
        char w = readAlpha();
        e.insert(u, i, w);
    }
    dfs1(0);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int u; scanf("%d %s", &u, st + 1); int len = strlen(st + 1);
        for (int j = 1; j <= len; j++) { str[++n] = st[j]; }
        str[++n] = 'P'; idq[i] = ++idi;
        for (int j = 1; j <= len; j++) { str[++n] = 'B'; }
        q[id[u]].push_back(idq[i]); qi[id[u]].push_back(i);
    }
    for (int i = 1, u = 1; i <= n; i++) {
        if (str[i] == 'P') { pos[++np] = u; }
        else if (str[i] == 'B') { u = aam.fa[u]; }
        else if (aam.son[u][str[i] - 'a']) { u = aam.son[u][str[i] - 'a']; }
        else { aam.son[u][str[i] - 'a'] = ++aam.tot; aam.fa[aam.tot] = u; u = aam.tot; }
    }
    aam.build(); aam.buildTree(); dfs(1); fwt.n = aam.tot;
    for (int i = 1, pi = 0, u = 1, x; i <= n; i++) {
        if (str[i] == 'P') {
            pi++;
            for (int j = 0; j < (int) q[pi].size(); j++) {
                x = pos[q[pi][j]]; ans[qi[pi][j]] = fwt.query(dfn[x], dfn[x] + siz[x] - 1);
            }
        } else if (str[i] == 'B') { fwt.modify(dfn[u], -1); u = aam.fa[u]; }
        else { u = aam.son[u][str[i] - 'a']; fwt.modify(dfn[u], 1); }
    }
    for (int i = 1; i <= m; i++) { printf("%d\n", ans[i]); }
    return 0;
}