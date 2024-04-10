#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5, INF = 0x7f7f7f7f;

struct node_t { int l, r, mn, tag; } p[N << 2];

vector < pair <int, int> > q[N];
int f[N], a[N], ans[N];
int n, m;

inline int lowbit(int x) { return x & -x; }

void add(int x) {
    while (x <= n) {
        ++f[x];
        x += lowbit(x);
    }
}

int qry(int x) {
    int ans = 0;
    while (x) {
        ans += f[x];
        x ^= lowbit(x);
    }
    return ans;
}

void update(int u) { p[u].mn = min(p[u << 1].mn, p[u << 1 | 1].mn); }

void add_tag(int u, int x) {
    p[u].tag += x;
    p[u].mn += x;
}

void pushdown(int u) {
    if (p[u].tag) {
        add_tag(u << 1, p[u].tag);
        add_tag(u << 1 | 1, p[u].tag);
        p[u].tag = 0;
    }
}

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
    if (l == r) {
        p[u].mn = INF;
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    update(u);
}

int query(int u) {
    if (p[u].l == p[u].r) return p[u].l;
    pushdown(u);
    if (p[u << 1].mn <= 0) return query(u << 1);
    return query(u << 1 | 1);
}

void add(int u, int l, int r, int x) {
    if (l <= p[u].l && p[u].r <= r) {
        add_tag(u, x);
        return;
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if (mid >= l) add(u << 1, l, r, x);
    if (mid + 1 <= r) add(u << 1 | 1, l, r, x);
    update(u);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > i) a[i] = n + 1;
        else a[i] = i - a[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        q[l + 1].emplace_back(n - r, i);
    }
    for (int i = n; i >= 1; i--) {
        add(1, i, i, -INF + a[i]);
        while (p[1].mn <= 0) {
            int pos = query(1);
            add(pos);
            if (pos != n) add(1, pos + 1, n, -1);
            add(1, pos, pos, INF);
        }
        for (auto j : q[i]) ans[j.second] = qry(j.first);
    }
    for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
    return 0;
}