#include <cstdio>
#include <cstring>
#include <bitset>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100005;

int n, m, a[N];
vector<int> g[N];
int id[N], to[N], last[N], idx;
bitset<1000> vis;

void dfs(int u, int p) {
    id[u] = ++idx;
    to[idx] = u;
    for (int i = 0 ; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        dfs(v, u);
    }
    last[u] = idx;
}

#define lson(x) (x<<1)
#define rson(x) (x<<1)|1
struct Node {
    bitset<1000> s;
    int lazy;

    void gao(int f) {
        f %= m;
        lazy = (lazy + f) % m;
        s = (s>>(m - f))|(s<<f);
    }
} node[N * 4];

void pushup(int x) {
    node[x].s = (node[lson(x)].s|node[rson(x)].s);
}

void pushdown(int x) {
    if (node[x].lazy) {
        node[lson(x)].gao(node[x].lazy);
        node[rson(x)].gao(node[x].lazy);
        node[x].lazy = 0;
    }
}

void build(int L = 1, int R = n, int x = 1) {
    if (L == R) {
        node[x].s[a[to[L]] % m] = true;
        return;
    }
    int mid = (L + R)>>1;
    build(L, mid, lson(x));
    build(mid + 1, R, rson(x));
    pushup(x);
}

void add(int l, int r, int val, int L = 1, int R = n, int x = 1) {
    if (L >= l && R <= r) {
        node[x].gao(val);
        return;
    }
    int mid = (L + R)>>1;
    pushdown(x);
    if (l <= mid) add(l, r, val, L, mid, lson(x));
    if (r > mid) add(l, r, val, mid + 1, R, rson(x));
    pushup(x);
}

bitset<1000> get(int l, int r, int L = 1, int R = n, int x = 1) {
    if (L >= l && R <= r) return node[x].s;
    int mid = (L + R)>>1;
    bitset<1000> ans;
    pushdown(x);
    if (l <= mid && r > mid) ans = (get(l, r, L, mid, lson(x))|get(l, r, mid + 1, R, rson(x)));
    else if (l <= mid) ans = get(l, r, L, mid, lson(x));
    else if (r > mid) ans = get(l, r, mid + 1, R, rson(x));
    pushup(x);
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) vis[i] = 1;
    vis[0] = vis[1] = 0;
    for (int i = 2; i < m; i++) {
        if (!vis[i]) continue;
        for (int j = i * i; j < m; j += i)
            vis[j] = 0;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int u, v;
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    build();
    int q;
    scanf("%d", &q);
    int tp, x;
    while (q--) {
        scanf("%d%d", &tp, &v);
        if (tp == 1) {
            scanf("%d", &x);
            add(id[v], last[v], x);
        } else printf("%d\n", (get(id[v], last[v])&vis).count());
    }
    return 0;
}