#include <bits/stdc++.h>

struct node {
    node *l, *r;
    int x;
    node() { l = r = nullptr, x = 0; }
};

node *build(int tl, int tr) {
    node *v = new node();
    if (tl + 1 == tr) return v;
    int m = (tl + tr) >> 1;
    v->l = build(tl, m);
    v->r = build(m, tr);
    return v;
}

node *add(node *v, int tl, int tr, int x) {
    node *u = new node();
    *u = *v;
    ++u->x;
    if (tl + 1 == tr) return u;
    int m = (tl + tr) >> 1;
    if (x < m) {
        u->l = add(u->l, tl, m, x);
    } else {
        u->r = add(u->r, m, tr, x);
    }
    return u;
}

int kth(node *vr, node *vl, int tl, int tr, int k) {
    if (tl + 1 == tr) return tl;
    int sz = vr->l->x - vl->l->x;
    int m = (tl + tr) >> 1;
    if (sz >= k) {
        return kth(vr->l, vl->l, tl, m, k);
    } else {
        return kth(vr->r, vl->r, m, tr, k - sz);
    }
}

int get(node *v, int tl, int tr, int x) {
    if (tl + 1 == tr) return v->x;
    int m = (tl + tr) >> 1;
    if (x < m)
        return get(v->l, tl, m, x);
    else
        return get(v->r, m, tr, x);
}

int n, q;
int a[310000];

node *nd[310000];

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i), --a[i];
    }
    node *root;
    nd[0] = root = build(0, n);
    for (int i = 0; i < n; ++i) {
        nd[i + 1] = root = add(root, 0, n, a[i]);
    }
    for (int i = 0; i < q; ++i) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        --l;
        int rq = (r - l) / k + 1;
        int fl = 0;
        for (int j = rq; j <= r - l; j += rq) {
            int x = kth(nd[r], nd[l], 0, n, j);
            if (get(nd[r], 0, n, x) - get(nd[l], 0, n, x) >= rq) {
                printf("%d\n", x + 1);
                fl = 1;
                break;
            }
        }
        if (!fl) printf("-1\n");
    }
    return 0;
}