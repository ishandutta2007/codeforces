#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

const int N = 200005;

#define lson(x) ((x<<1)+1)
#define rson(x) ((x<<1)+2)

struct Node {
    int l, r, val, lazy;
    void gao(int la) {
        val = max(la, val);
        lazy = max(lazy, la);
    }
};

struct SegTree {
    Node node[N * 8];

    void pushdown(int x) {
        if (node[x].lazy) {
            node[lson(x)].gao(node[x].lazy);
            node[rson(x)].gao(node[x].lazy);
            node[x].lazy = 0;
        }
    }

    void build(int l, int r, int x = 0) {
        node[x].l = l; node[x].r = r;
        node[x].val = 0;
        node[x].lazy = 0;
        if (l == r) return;
        int mid = (l + r)>>1;
        build(l, mid, lson(x));
        build(mid + 1, r, rson(x));
    }

    void add(int l, int r, int val, int x = 0) {
        if (l > r) return;
        if (node[x].l >= l && node[x].r <= r) {
            node[x].gao(val);
            return;
        }
        int mid = (node[x].l + node[x].r)>>1;
        pushdown(x);
        if (l <= mid) add(l, r, val, lson(x));
        if (r > mid) add(l, r, val, rson(x));
    }

    int query(int v, int x = 0) {
        if (node[x].l == node[x].r) return node[x].val;
        int mid = (node[x].l + node[x].r)>>1;
        pushdown(x);
        if (v <= mid) return query(v, lson(x));
        else return query(v, rson(x));
    }
} tree[2];

struct Q {
    int x, y, op;
} query[N];

int H[N * 2], hn;

int find(int x) {
    return lower_bound(H, H + hn, x) - H;
}

set<pair<int, int> > S;

int n, q;
int main() {
    scanf("%d%d", &n, &q);
    int x, y;
    char op[2];
    H[hn++] = 0;
    for (int i = 0; i < q; i++) {
        scanf("%d%d%s", &x, &y, op);
        query[i].x = x;
        query[i].y = y;
        H[hn++] = x;
        H[hn++] = y;
        query[i].op = (op[0] != 'U');
    }
    H[hn++] = n;
    sort(H, H + hn);
    hn = unique(H, H + hn) - H;
    tree[0].build(0, hn - 1);
    tree[1].build(0, hn - 1);
    for (int i = 0; i < q; i++) {
        x = query[i].x; y = query[i].y; int o = query[i].op;
        if (S.find(make_pair(x, y)) != S.end()) {
            printf("0\n");
            continue;
        } else {
            S.insert(make_pair(x, y));
        }
        if (o) {
            int tmp = tree[o].query(find(x));
            printf("%d\n", x - tmp);
            tree[!o].add(find(y) + 1, find(n - tmp), y);
        } else {
            int tmp = tree[o].query(find(y));
            printf("%d\n", y - tmp);
            tree[!o].add(find(x) + 1, find(n - tmp), x);
        }
    }
    return 0;
}