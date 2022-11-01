#include <cstdio>
#include <algorithm>
#include <array>
using namespace std;

constexpr int maxn = 1 << 18;

struct Node {
    bool inverted;
    array<int, 6> a, b;

    void init(int m) {
        inverted = false;
        for (int i = 0; i <= m; i++) {
            a[i] = (i + 1) % (m + 1);
            b[i] = min(i + 1, m);
        }
    }

    void invert() {
        inverted ^= 1;
        swap(a, b);
    }

    void merge(Node &lhs, Node &rhs, int m) {
        for (int i = 0; i <= m; i++) {
            a[i] = lhs.a[rhs.a[i]];
            b[i] = lhs.b[rhs.b[i]];
        }
        if (inverted)
            swap(a, b);
    }
} nodes[maxn * 2 - 1];

void invert(int l, int r, int m,
            int nl = 0, int nr = maxn, int k = 0) {
    if (l <= nl && nr <= r) {
        nodes[k].invert();
    } else if (!(r <= nl || nr <= l)) {
        int nm = (nl + nr) >> 1;
        invert(l, r, m, nl, nm, 2 * k + 1);
        invert(l, r, m, nm, nr, 2 * k + 2);
        nodes[k].merge(nodes[2 * k + 1], nodes[2 * k + 2], m);
    }
}

int query(int l, int r, int x, bool inverted,
          int nl = 0, int nr = maxn, int k = 0) {
    if (l <= nl && nr <= r) {
        return (inverted ? nodes[k].b : nodes[k].a)[x];
    } else if (r <= nl || nr <= l) {
        return x;
    } else {
        int nm = (nl + nr) >> 1;
        int y = query(l, r, x, inverted ^ nodes[k].inverted,
                      nm, nr, 2 * k + 2);
        int z = query(l, r, y, inverted ^ nodes[k].inverted,
                      nl, nm, 2 * k + 1);
        return z;
    }
}

int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 0; i < maxn; i++)
        nodes[maxn - 1 + i].init(m);

    for (int i = 0; i < n; i++) {
        long long x;
        scanf("%lld", &x);
        if ((x - 1) & 1)
            nodes[maxn - 1 + i].invert();
    }

    for (int i = maxn - 2; i >= 0; i--)
        nodes[i].merge(nodes[2 * i + 1], nodes[2 * i + 2], m);

    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int l, r;
            long long d;
            scanf("%d%d%lld", &l, &r, &d);
            l--;
            if (d & 1) {
                invert(l, r, m);
            }
        } else if (t == 2) {
            int l, r;
            scanf("%d%d", &l, &r);
            l--;
            printf("%d\n", query(l, r, m, false) ? 1 : 2);
        }
    }
}