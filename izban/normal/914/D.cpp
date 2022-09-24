#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = (int)1e9 + 7;
const int INF = (int)1.01e9;

const int N = 1 << 19;

int n;
int a[N];
int t[N * 2];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = __gcd(t[v * 2], t[v * 2 + 1]);
}

void upd(int v, int tl, int tr, int x, int y) {
    if (tl == tr) {
        t[v] = a[tl] = y;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (x <= tm) upd(v * 2, tl, tm, x, y);
    else upd(v * 2 + 1, tm + 1, tr, x, y);
    t[v] = __gcd(t[v * 2], t[v * 2 + 1]);
}

int left(int v, int tl, int tr, int l, int r, int x) {
    if (l > r) return INF;
    if (tl == l && tr == r) {
        if (t[v] % x == 0) {
            return INF;
        }
        if (tl == tr) return tl;
    }
    int tm = (tl + tr) >> 1;
    int res = left(v * 2, tl, tm, l, min(r, tm), x);
    if (res == INF) res = left(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
    return res;
}

int right(int v, int tl, int tr, int l, int r, int x) {
    if (l > r) return -INF;
    if (tl == l && tr == r) {
        if (t[v] % x == 0) {
            return -INF;
        }
        if (tl == tr) return tl;
    }
    int tm = (tl + tr) >> 1;
    int res = right(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
    if (res == -INF) res = right(v * 2, tl, tm, l, min(r, tm), x);
    return res;
}


int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        build(1, 0, n - 1);

        int q;
        scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            int tp;
            scanf("%d", &tp);
            if (tp == 1) {
                int l, r, x;
                scanf("%d%d%d", &l, &r, &x);
                l--; r--;
                int i1 = left(1, 0, n - 1, l, r, x);
                int i2 = right(1, 0, n - 1, l, r, x);
                string s = i1 >= i2 ? "YES" : "NO";
                printf("%s\n", s.c_str());
            }
            if (tp == 2) {
                int x, y;
                scanf("%d%d", &x, &y);
                x--;
                upd(1, 0, n - 1, x, y);
            }
        }
    }

    return 0;
}