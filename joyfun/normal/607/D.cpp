#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200005;
const int MOD = 1000000007;

int val[N], left[N], right[N], n, q, fa[N];
vector<int> g[N];

struct OP {
    int tp, p, v;
    void read() {
        scanf("%d", &tp);
        if (tp == 1) scanf("%d%d", &p, &v);
        else scanf("%d", &v);
    }
} op[N];

int idx = 0;
void dfs(int u, int p) {
    left[u] = ++idx;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        dfs(v, u);
    }
    right[u] = idx;
}

#define lson(x) ((x<<1)+1)
#define rson(x) ((x<<1)+2)

struct Node {
    int l, r, sum, cnt;
} node[N * 4];

void pushup(int x) {
    node[x].sum = (node[lson(x)].sum + node[rson(x)].sum) % MOD;
}

void pushdown(int x) {
    if (node[x].cnt != 1) {
        int tmp = node[x].cnt;
        node[x].cnt = 1;
        node[lson(x)].sum = 1LL * node[lson(x)].sum * tmp % MOD;
        node[lson(x)].cnt = 1LL * node[lson(x)].cnt * tmp % MOD;
        node[rson(x)].sum = 1LL * node[rson(x)].sum * tmp % MOD;
        node[rson(x)].cnt = 1LL * node[rson(x)].cnt * tmp % MOD;
    }
}

void build(int l, int r, int x = 0) {
    node[x].l = l; node[x].r = r;
    node[x].sum = 0; node[x].cnt = 1;
    if (l == r) return;
    int mid = (l + r)>>1;
    build(l, mid, lson(x));
    build(mid + 1, r, rson(x));
}

void mul(int l, int r, int w, int x = 0) {
    if (node[x].l >= l && node[x].r <= r) {
        node[x].cnt = 1LL * node[x].cnt * w % MOD;
        node[x].sum = 1LL * node[x].sum * w % MOD;
        return;
    }
    int mid = (node[x].l + node[x].r)>>1;
    pushdown(x);
    if (l <= mid) mul(l, r, w, lson(x));
    if (r > mid) mul(l, r, w, rson(x));
    pushup(x);
}

void add(int v, int w, int x = 0) {
    if (node[x].l == node[x].r) {
        node[x].sum = (node[x].sum + w) % MOD;
        return;
    }
    pushdown(x);
    int mid = (node[x].l + node[x].r)>>1;
    if (v <= mid) add(v, w, lson(x));
    else add(v, w, rson(x));
    pushup(x);
}

int getsum(int l, int r, int x = 0) {
    if (node[x].l >= l &&  node[x].r <= r)
        return node[x].sum;
    int mid = (node[x].l + node[x].r)>>1;
    pushdown(x);
    int ans = 0;
    if (l <= mid) ans = (ans + getsum(l, r, lson(x))) % MOD;
    if (r > mid) ans = (ans + getsum(l, r, rson(x))) % MOD;
    pushup(x);
    return ans;
}

int getcnt(int v, int x = 0) {
    if (node[x].l == node[x].r) return node[x].cnt;
    int mid = (node[x].l + node[x].r)>>1;
    int ans = 0;
    pushdown(x);
    if (v <= mid) ans = getcnt(v, lson(x));
    else ans = getcnt(v, rson(x));
    pushup(x);
    return ans;
}

int deg[N];

int pow_mod(int x, int k) {
    int ans = 1;
    while (k) {
        if (k&1) ans = 1LL * ans * x % MOD;
        x = 1LL * x * x % MOD;
        k >>= 1;
    }
    return ans;
}

int main() {
    scanf("%d%d", &val[1], &q); n = 1;
    deg[1] = 1;
    for (int i = 0; i < q; i++) {
        op[i].read();
        if (op[i].tp == 1) {
            g[op[i].p].push_back(++n);
            val[n] = op[i].v;
            fa[n] = op[i].p;
        }
    }
    dfs(1, 1);
    build(1, n);
    add(left[1], val[1]);
    int u = 1;
    for (int i = 0; i < q; i++) {
        if (op[i].tp == 1) {
            ++u;
            int p = op[i].p, v = op[i].v;
            mul(left[p], right[p], 1LL * (1 + deg[p]) * pow_mod(deg[p], MOD - 2) % MOD);
            deg[p]++; deg[u] = 1;
            add(left[u], 1LL * getcnt(left[u]) * v % MOD);
        } else {
            int v = op[i].v;
            int ans = getsum(left[v], right[v]);
            if (v != 1) ans = 1LL * ans * pow_mod(getcnt(left[fa[v]]), MOD - 2) % MOD;
            printf("%d\n", ans);
        }
    }
    return 0;
}