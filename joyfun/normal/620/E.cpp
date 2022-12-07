#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 400005;

int n, m, c[N], L[N], R[N], to[N], idx;
vector<int> g[N];

void dfs(int u, int p) {
    L[u] = ++idx;
    to[idx] = u;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p)continue;
        dfs(v, u);
    }
    R[u] = idx;
}

#define lson(x) ((x<<1)+1)
#define rson(x) ((x<<1)+2)

struct Node {
   int l, r;
   long long s;
} node[N * 4];

int bitcount(long long x) {
    int ans = 0;
    while (x) {
        ans += (x&1);
        x >>= 1;
    }
    return ans;
}

void pushup(int x) {
    node[x].s = (node[lson(x)].s | node[rson(x)].s);
}

void pushdown(int x) {
    if (bitcount(node[x].s) == 1) {
        node[lson(x)].s = node[rson(x)].s = node[x].s;
    }
}

void build(int l, int r, int x = 0) {
    node[x].l = l;
    node[x].r = r;
    if (l == r) {
        node[x].s = (1LL<<c[to[l]]);
        return;
    }
    int mid = (l + r)>>1;
    build(l, mid, lson(x));
    build(mid + 1, r, rson(x));
    pushup(x);
}

void add(int l, int r, int c, int x = 0) {
    if (node[x].l >= l && node[x].r <= r) {
        node[x].s = (1LL<<c);
        return;
    }
    pushdown(x);
    int mid = (node[x].l + node[x].r)>>1;
    if (l <= mid) add(l, r, c, lson(x));
    if (r > mid) add(l, r, c, rson(x));
    pushup(x);
}

long long query(int l, int r, int x = 0) {
    if (node[x].l >= l && node[x].r <= r) {
        return node[x].s;
    }
    pushdown(x);
    long long ans = 0;
    int mid = (node[x].l + node[x].r)>>1;
    if (l <= mid) ans |= query(l, r, lson(x));
    if (r > mid) ans |= query(l, r, rson(x));
    pushup(x);
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    idx = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    int u, v;
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    build(1, n);
    int tp, x, c;
    while (m--) {
        scanf("%d%d", &tp, &x);
        if(tp == 1) {
            scanf("%d", &c);
            add(L[x], R[x], c);
        } else {
            printf("%d\n", bitcount(query(L[x], R[x])));
        }
    }
    return 0;
}