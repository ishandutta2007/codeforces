#include <bits/stdc++.h>

#define N 111111
typedef long long ll;

int val[N][10];
ll nvals[10];
struct tree {
    int i, j;
    ll vals[10];
    int s[10];
    tree *l, *r;
    tree(int i, int j): i(i), j(j) {
        for (int d = 0; d < 10; d++) {
            s[d] = d;
        }
        if (j - i == 1) {
            l = r = NULL;
            for (int d = 0; d < 10; d++) {
                vals[d] = val[i][d];
            }
        } else {
            int k = i + j >> 1;
            l = new tree(i, k);
            r = new tree(k, j);
            combine();
        }
    }
    inline void combine() {
        for (int d = 0; d < 10; d++) vals[d] = l->vals[d] + r->vals[d];
    }
    void visit() {
        if (l) {
            for (int d = 0; d < 10; d++) {
                l->s[d] = s[l->s[d]];
                r->s[d] = s[r->s[d]];
            }
        }
        for (int d = 0; d < 10; d++) nvals[s[d]] += vals[d], s[d] = d;
        for (int d = 0; d < 10; d++) vals[d] = nvals[d], nvals[d] = 0;
    }
    void set(int I, int J, int x, int y) {
        if (I <= i && j <= J) {
            for (int d = 0; d < 10; d++) if (s[d] == x) s[d] = y;
            visit();
        } else {
            visit();
            if (!(J <= i || j <= I)) {
                l->set(I, J, x, y);
                r->set(I, J, x, y);
                combine();
            }
        }
    }
    ll sum(int I, int J) {
        visit();
        if (I <= i && j <= J) {
            ll t = 0;
            for (int d = 0; d < 10; d++) t += vals[d] * d;
            return t;
        } else if (J <= i || j <= I) {
            return 0;
        } else {
            return l->sum(I, J) + r->sum(I, J);
        }
    }
};

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        for (int p10 = 1; a; a /= 10, p10 *= 10) {
            val[i][a % 10] += p10;
        }
    }

    tree *tr = new tree(0, n);
    while (q--) {
        int t, l, r;
        scanf("%d%d%d", &t, &l, &r);
        l--;
        if (t == 1) {
            int x, y;
            scanf("%d%d", &x, &y);
            tr->set(l, r, x, y);
        } else {
            printf("%lld\n", tr->sum(l, r));
        }
    }
}