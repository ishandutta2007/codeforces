#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005;
const int M = 200005;
const int MOD = 1000000007;

int dep[N], fa[N], son[N], sz[N], top[N], id[N], idx;
int w[N][2];

struct Edge {
    int u, v, w;
    Edge() {}
    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
} edge[M];

int head[N], nxt[M], en;

void init() {
    en = 0;
    idx = 0;
    memset(head, -1, sizeof(head));
}

void add_Edge(int u, int v, int w) {
    edge[en] = Edge(u, v, w);
    nxt[en] = head[u];
    head[u] = en++;
}

void dfs1(int u, int f, int d) {
    dep[u] = d;
    sz[u] = 1;
    fa[u] = f;
    son[u] = 0;
    for (int i = head[u]; i + 1; i = nxt[i]) {
        int v = edge[i].v;
        if (v == f) continue;
        dfs1(v, u, d + 1);
        sz[u] += sz[v];
        if (sz[son[u]] < sz[v])
            son[u] = v;
    }
}

void dfs2(int u, int tp) {
    id[u] = ++idx;
    top[u] = tp;
    if (son[u]) dfs2(son[u], tp);
    for (int i = head[u]; i + 1; i = nxt[i]) {
        int v = edge[i].v;
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

void gaomodify(int u, int v) {
    int tp1 = top[u], tp2 = top[v];
    int f = 1;
    while (tp1 != tp2) {
        if (dep[tp1] < dep[tp2]) {
            swap(tp1, tp2);
            swap(u, v);
            f = !f;
        }
        w[id[u] + 1][f]--;
        w[id[tp1]][f]++;
        u = fa[tp1];
        tp1 = top[u];
    }
    if (dep[u] > dep[v]) {
        swap(u, v);
    } else f = !f;

    if (u != v) {
        w[id[v] + 1][f]--;
        w[id[son[u]]][f]++;
    }
}

int n;

int pow2[1000005];

int main() {
    pow2[0] = 1;
    for (int i = 1; i < 1000005; i++)
        pow2[i] = pow2[i - 1] * 2 % MOD;
    scanf("%d", &n);
    init();
    int u, v, W;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d%d", &u, &v, &W);
        add_Edge(u, v, W);
        add_Edge(v, u, W);
    }
    dfs1(1, 1, 1);
    dfs2(1, 1);

    int K;
    scanf("%d", &K);
    int s = 1, ss;
    for (int i = 1; i <= K; i++) {
        scanf("%d", &ss);
        gaomodify(s, ss);
        s = ss;
    }

    for (int i = 1; i <= n; i++) {
        w[i][0] += w[i - 1][0];
        w[i][1] += w[i - 1][1];
    }

    int ans = 0;
    for (int i = 0; i < en; i += 2) {
        if (edge[i].w == 0) continue;
        if (dep[edge[i].u] < dep[edge[i].v]) ans = ((ans + pow2[w[id[edge[i].v]][1]] - 1) % MOD + MOD) % MOD;
        else ans = ((ans + pow2[w[id[edge[i].u]][0]] - 1) % MOD + MOD) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}