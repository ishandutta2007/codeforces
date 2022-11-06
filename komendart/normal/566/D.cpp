#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 2;

int dsu[maxn];
int srank[maxn];

int dsu_seg[maxn];
int srank_seg[maxn];
int border[maxn];

void build_dsu(int n) {
    for (int i = 0; i <= n; i++) {
        dsu[i] = i;
        srank[i] = 1;
        dsu_seg[i] = i;
        srank_seg[i] = 1;
        border[i] = i;
    }
}

int find_set(int v) {
    if (v == dsu[v]) return v;
    return dsu[v] = find_set(dsu[v]);
}

int find_set_seg(int v) {
    if (v == dsu_seg[v]) return v;
    return dsu_seg[v] = find_set_seg(dsu_seg[v]);
}

void unite(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    if (srank[a] < srank[b]) swap(a, b);
    srank[a] += srank[b];
    dsu[b] = a;
}

void unite_seg(int a, int b) {
    a = find_set_seg(a);
    b = find_set_seg(b);
    if (a == b) return;
    if (srank_seg[a] < srank_seg[b]) swap(a, b);
    dsu_seg[b] = a;
    srank_seg[a] += srank_seg[b];
    border[a] = max(border[a], border[b]);
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);

    build_dsu(n);

    for (int i = 0; i < q; i++) {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        if (t == 1) {
            unite(x, y);
        } else if (t == 2) {
            for (int r = border[find_set_seg(x)]; r <= y - 1; r = border[find_set_seg(r)]) {
                unite(r, r + 1);
                unite_seg(r, r + 1);
            }
        } else {
            if (find_set(x) == find_set(y)) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }
}