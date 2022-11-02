#include <bits/stdc++.h>

const int N = 300054, D = 54;

int V, E, d, Es = 0, T = 1;
int u[N], v[N], w[N];
int to[N], first[N], next[N];
int DAG[N], deg[N], top[N];
int dep[N], que[N], cyc[N];
char val[N][D];
int tot[N][D], dp[N][D];

int cnt = 0, id[N], low[N];
int stc = 0, sta[N];
bool used[N], ok[N][D], instack[N];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline void up(int &x, const int y) { x < y ? x = y : 0; }
inline void down(int &x, const int y) { x > y ? x = y : 0; }
inline void addedge(int u, int v, int *fst) {
    to[++Es] = v;
    next[Es] = fst[u];
    fst[u] = Es;
}

void dfs(int x) {
    int i, y;
    id[x] = low[x] = ++cnt;
    instack[x] = 1;
    sta[stc++] = x;
    for (i = first[x]; i; i = next[i])
        if (!id[y = to[i]])
            dep[y] = dep[x] + 1, dfs(y), down(low[x], low[y]);
        else if (instack[y])
            down(low[x], id[y]);
    if (id[x] == low[x])
        for (y = 0; y != x;) y = sta[--stc], instack[y] = 0, top[y] = x;
}

void trans(int x, int tx) {
    if (x == tx) return;
    int i, Dist = (dep[tx] - dep[x]) % d;
    Dist += Dist >> 31 & d;
    for (i = 0; i < d; ++i) ok[tx][(i + Dist) % d] |= ok[x][i];
}

void dfs2(int x, int scc) {
    int i, j, y;
    for (y = cyc[scc], i = 0; i < 2 * d; ++i) ok[x][(i + y) % d] |= ok[x][i % d];
    used[x] = true;
    for (i = first[x]; i; i = next[i])
        if (!used[y = to[i]] && top[y]) {
            for (j = 0; j < d; ++j) ok[y][(j + 1) % d] |= ok[x][j];
            if (top[y] == scc)
                dfs2(y, scc);
            else if (trans(y, top[y]), !--deg[top[y]])
                que[T++] = top[y];
        }
}

int main() {
    int i, j, h, x, y, dist, ans = 0;
    scanf("%d%d%d", &V, &E, &d);
    for (i = 0; i < E; ++i) scanf("%d%d", u + i, v + i), addedge(u[i], v[i], first);
    for (i = 1; i <= V; ++i) scanf("%s", val[i]);
    dfs(1), ok[1][0] = true, que[0] = 1;
    for (i = 0; i < E; ++i)
        if (u[i][top] && v[i][top]) {
            if (u[i][top] == v[i][top])
                cyc[u[i][top]] = gcd(cyc[u[i][top]], abs(1 + u[i][dep] - v[i][dep]));
            else {
                ++deg[v[i][top]], addedge(u[i][top], v[i][top], DAG);
                dist = (1 + u[i][dep] - u[i][top][dep] + v[i][dep] - v[i][top][dep]) % d;
                w[Es] = dist + (dist >> 31 & d);
            }
        }
    for (i = 1; i <= V; ++i)
        if (top[i] == i) cyc[i] = gcd(cyc[i], d);
    for (h = 0; h < T; ++h) dfs2(que[h], que[h]);
    for (i = 1; i <= V; ++i) {
        dist = (dep[top[i]] - dep[i]) % d, dist += dist >> 31 & d;
        for (j = 0; j < cyc[top[i]]; ++j)
            for (h = j; h < d; h += cyc[top[i]])
                if (val[i][h] & ok[i][h]) {
                    ++tot[top[i]][(j + dist) % cyc[top[i]]];
                    break;
                }
    }
    for (h = 0; h < T; ++h) {
        for (x = que[h], i = 0; i < cyc[x]; ++i) up(ans, dp[x][i] += tot[x][i]);
        for (i = DAG[x]; i; i = next[i])
            for (y = to[i], j = 0; j < d; ++j) up(dp[y][(j + w[i]) % cyc[y]], dp[x][j % cyc[x]]);
    }
    printf("%d\n", ans);
    return 0;
}