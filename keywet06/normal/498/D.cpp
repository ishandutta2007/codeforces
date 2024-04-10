#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int a[N];

struct Seg {
    int l, r, mid;
    int t[60];
} seg[3 * N];

void up(int n) {
    for (int i = 0; i < 60; ++i) {
        int tmp = i + seg[2 * n].t[i];
        seg[n].t[i] = tmp - i + seg[2 * n + 1].t[tmp % 60];
    }
}

void build(int l, int r, int n) {
    seg[n].l = l;
    seg[n].r = r;
    seg[n].mid = (l + r) >> 1;
    if (l == r) {
        for (int i = 0; i < 60; ++i) seg[n].t[i] = (i % a[l] == 0) + 1;
        return;
    }
    build(l, seg[n].mid, 2 * n);
    build(seg[n].mid + 1, r, 2 * n + 1);
    up(n);
}

void update(int u, int n, int x) {
    if (seg[n].l == seg[n].r) {
        a[u] = x;
        for (int i = 0; i < 60; ++i) seg[n].t[i] = (i % a[u] == 0) + 1;
        return;
    }
    update(u, 2 * n + (u > seg[n].mid), x), up(n);
}

int query(int l, int r, int n, int t) {
    if (l <= seg[n].l && seg[n].r <= r) return t + seg[n].t[t % 60];
    if (seg[n].mid >= l) t = query(l, r, 2 * n, t);
    if (seg[n].mid < r) t = query(l, r, 2 * n + 1, t);
    return t;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    build(1, n, 1);
    int m;
    scanf("%d", &m);
    char op[2];
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%s%d%d", op, &u, &v);
        if (op[0] == 'A') {
            printf("%d\n", query(u, v - 1, 1, 0));
        } else {
            update(u, 1, v);
        }
    }
    return 0;
}