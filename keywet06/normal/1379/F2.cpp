#include <bits/stdc++.h>

using namespace std;

struct node {
    int l, r, minw, maxb, ok;
    node *lson, *rson;
    inline void upd() {
        if (l < r) {
            ok = (lson->minw > rson->maxb);
            ok &= lson->ok;
            ok &= rson->ok;
            minw = min(lson->minw, rson->minw);
            maxb = max(lson->maxb, rson->maxb);
        } else {
            ok = (minw > maxb);
        }
    }
};

int top;
int T, n, m, q;

node *root, pool[1111111];

set<int> b[233333], w[233333];

node *build(int l, int r) {
    node *tmp = &pool[top++];
    tmp->l = l, tmp->r = r, tmp->minw = m + 1, tmp->maxb = 0, tmp->ok = 1;
    if (l >= r) return tmp;
    int mid = (l + r) / 2;
    return tmp->lson = build(l, mid), tmp->rson = build(mid + 1, r), tmp;
}

void changew(node *cur, int pos, int val) {
    if (cur->l == cur->r) return cur->minw = val, cur->upd();
    changew(pos <= cur->lson->r ? cur->lson : cur->rson, pos, val), cur->upd();
}

void changeb(node *cur, int pos, int val) {
    if (cur->l == cur->r) return cur->maxb = val, cur->upd();
    changeb(pos <= cur->lson->r ? cur->lson : cur->rson, pos, val), cur->upd();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) b[i].insert(0), w[i].insert(m + 1);
    root = build(1, n);
    int x, y;
    for (int i = 1; i <= q; i++) {
        cin >> x >> y;
        if (x % 2 == 1) {
            x = (x + 1) / 2, y = (y + 1) / 2;
            if (w[x].find(y) != w[x].end()) {
                w[x].erase(y);
            } else {
                w[x].insert(y);
            }
            changew(root, x, *w[x].begin());
        } else {
            x = x / 2, y = y / 2;
            if (b[x].find(y) != b[x].end()) {
                b[x].erase(y);
            } else {
                b[x].insert(y);
            }
            changeb(root, x, *--b[x].end());
        }
        if (root->ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}