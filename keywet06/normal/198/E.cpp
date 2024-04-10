#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int N = 250100;
const int M = 1000010000;

struct Node {
    int64 d, r;
    int m, p;
} q[N];

int MIN(int x, int y) {
    if (x < y) return x;
    return y;
}

bool cmp(Node x, Node y) { return x.d < y.d; }

struct Tr {
    int l, r, id;
} p[4 * N];

void init(int nu, int l, int r) {
    p[nu].l = l;
    p[nu].r = r;
    if (l == r) {
        p[nu].id = l;
        return;
    }
    int mid = (l + r) / 2;
    init(nu * 2, l, mid);
    init(nu * 2 + 1, mid + 1, r);
    if (q[p[nu * 2].id].m < q[p[nu * 2 + 1].id].m) {
        p[nu].id = p[nu * 2].id;
    } else {
        p[nu].id = p[nu * 2 + 1].id;
    }
}

int mi(int nu, int l, int r) {
    if (p[nu].l == l && p[nu].r == r) return q[p[nu].id].m;
    int mid = (p[nu].l + p[nu].r) / 2;
    if (r <= mid) {
        return mi(nu * 2, l, r);
    } else if (l > mid) {
        return mi(nu * 2 + 1, l, r);
    } else {
        int a = mi(nu * 2, l, mid);
        int b = mi(nu * 2 + 1, mid + 1, r);
        return MIN(a, b);
    }
}

int read(int nu, int l, int r) {
    if (p[nu].l == l && p[nu].r == r) return p[nu].id;
    int mid = (p[nu].l + p[nu].r) / 2;
    if (r <= mid) {
        return read(nu * 2, l, r);
    } else if (l > mid) {
        return read(nu * 2 + 1, l, r);
    } else {
        int a = read(nu * 2, l, mid);
        int b = read(nu * 2 + 1, mid + 1, r);
        if (q[a].m < q[b].m) {
            return a;
        } else {
            return b;
        }
    }
}

void update(int nu, int po) {
    if (p[nu].l == po && p[nu].r == po) {
        q[p[nu].id].m = M;
        return;
    }
    int mid = (p[nu].l + p[nu].r) / 2;
    if (po <= mid) {
        update(nu * 2, po);
    } else if (po > mid) {
        update(nu * 2 + 1, po);
    }
    if (q[p[nu * 2].id].m < q[p[nu * 2 + 1].id].m) {
        p[nu].id = p[nu * 2].id;
    } else {
        p[nu].id = p[nu * 2 + 1].id;
    }
}

int64 sqr(int64 x) { return x * x; }

int n;

int find(int64 x) {
    int lo = -1, up = n, mid;
    while (lo + 1 < up) {
        mid = (lo + up) / 2;
        if (q[mid].d <= x) {
            lo = mid;
        } else {
            up = mid;
        }
    }
    return lo;
}

int x, y, tx, ty, P, R, tr, i, top, tail, Q[N], T, id;

int main() {
    while (~scanf("%d%d%d%d%d", &x, &y, &P, &R, &n)) {
        for (i = 0; i < n; ++i) {
            scanf("%d%d%d%d%d", &tx, &ty, &q[i].m, &q[i].p, &tr);
            q[i].d = sqr(tx - x) + sqr(ty - y);
            q[i].r = sqr(tr);
        }
        sort(q, q + n, cmp);
        init(1, 0, n - 1);
        id = find((int64)R * R);
        top = 0;
        tail = 0;
        if (id != -1) {
            while (mi(1, 0, id) <= P) {
                T = read(1, 0, id);
                ++tail;
                Q[tail] = T;
                update(1, T);
            }
        };
        while (top < tail) {
            ++top;
            id = find(q[Q[top]].r);
            if (id != -1) {
                while (mi(1, 0, id) <= q[Q[top]].p) {
                    T = read(1, 0, id);
                    ++tail;
                    Q[tail] = T;
                    update(1, T);
                }
            }
        }
        cout << tail << endl;
    }
    return 0;
}