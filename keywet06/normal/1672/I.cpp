#include <bits/stdc++.h>

#define fi first
#define se second

typedef std::pair<int, int> Pair;

const int N = 1 << 19;

int n, Ans;
int p[N];

struct BIT {
    int Tr[N];
    BIT() { memset(Tr, 0, sizeof Tr); }
    void Update(int p) {
        for (; p <= n; p += p & -p) ++Tr[p];
    }
    int Query(int p) {
        int s = 0;
        for (; p; p -= p & -p) s += Tr[p];
        return s;
    }
};

struct DS {
    int y[N], Suf[N], tg[N << 1];
    BIT sx, sy;
    Pair Se1[N << 1], Se2[N << 1];
    DS() {
        memset(y, 0x3f, sizeof y);
        memset(tg, 0, sizeof tg);
    }
    void build(int x, int L, int R) {
        if (L == R) {
            Se1[x] = std::make_pair(y[L], L);
            Se2[x] = std::make_pair(y[L] == Suf[L] ? y[L] - L : 1e9, L);
            return;
        }
        int md = L + R >> 1;
        build(x << 1, L, md);
        build(x << 1 | 1, md + 1, R);
        Se1[x] = std::min(Se1[x << 1], Se1[x << 1 | 1]);
        Se2[x] = std::min(Se2[x << 1], Se2[x << 1 | 1]);
    }
    void build() {
        Suf[n + 1] = 1e9;
        for (int i = n; i; --i) Suf[i] = std::min(Suf[i + 1], y[i]);
        build(1, 1, n);
    }
    void ptag(int x, int v) { Se2[x].fi += v, tg[x] += v; }
    void pdown(int x) {
        if (tg[x]) {
            ptag(x << 1, tg[x]);
            ptag(x << 1 | 1, tg[x]);
            tg[x] = 0;
        }
    }
    void Update(int l, int r, int x = 1, int L = 1, int R = n) {
        if (l <= L && R <= r) {
            ptag(x, -1);
            return;
        }
        int md = L + R >> 1;
        pdown(x);
        if (l <= md) Update(l, r, x << 1, L, md);
        if (md < r) Update(l, r, x << 1 | 1, md + 1, R);
        Se2[x] = std::min(Se2[x << 1], Se2[x << 1 | 1]);
    }
    void del(int p, int x = 1, int L = 1, int R = n) {
        if (L == R) {
            Se1[x].fi = Se2[x].fi = 1e9;
            return;
        }
        int md = L + R >> 1;
        pdown(x);
        if (p <= md)
            del(p, x << 1, L, md);
        else
            del(p, x << 1 | 1, md + 1, R);
        Se1[x] = std::min(Se1[x << 1], Se1[x << 1 | 1]);
        Se2[x] = std::min(Se2[x << 1], Se2[x << 1 | 1]);
    }
    void add(int p, int x = 1, int L = 1, int R = n) {
        if (L == R) {
            Se2[x].fi = y[L] - L + sx.Query(L) - sy.Query(y[L]);
            return;
        }
        int md = L + R >> 1;
        pdown(x);
        if (p <= md)
            add(p, x << 1, L, md);
        else
            add(p, x << 1 | 1, md + 1, R);
        Se2[x] = std::min(Se2[x << 1], Se2[x << 1 | 1]);
    }
    Pair Query(int p, int x = 1, int L = 1, int R = n) {
        if (p <= L) return Se1[x];
        int md = L + R >> 1;
        if (p <= md) return std::min(Query(p, x << 1, L, md), Se1[x << 1 | 1]);
        return Query(p, x << 1 | 1, md + 1, R);
    }
    int findl(int p, int x = 1, int L = 1, int R = n) {
        if (Se2[x].fi > n) return -1;
        if (L == R) return L;
        int md = L + R >> 1, Ans = -1;
        if (p > md) Ans = findl(p, x << 1 | 1, md + 1, R);
        if (Ans == -1) Ans = findl(p, x << 1, L, md);
        return Ans;
    }
    int findr(int p, int x = 1, int L = 1, int R = n) {
        if (Se2[x].fi > n) return -1;
        if (L == R) return L;
        int md = L + R >> 1, Ans = -1;
        if (p <= md) Ans = findr(p, x << 1, L, md);
        if (Ans == -1) Ans = findr(p, x << 1 | 1, md + 1, R);
        return Ans;
    }
    int findy(int p, int x = 1, int L = 1, int R = n) {
        if (L == R) return L + (Se1[x].fi < p);
        int md = L + R >> 1;
        if (Se1[x << 1 | 1].fi > p) return findy(p, x << 1, L, md);
        return findy(p, x << 1 | 1, md + 1, R);
    }
    Pair work() {
        int x = Se2[1].se;
        sx.Update(x);
        sy.Update(y[x]);
        del(x);
        int l = findl(x) + 1, r = findr(x);
        if (!l) l = 1;
        if (r == -1) r = n + 1;
        while (l < r) {
            Pair o = Query(l);
            if (o.fi > n || o.se >= r) break;
            add(o.se);
            l = o.se + 1;
        }
        return std::make_pair(x, y[x]);
    }
    void work2(int x, int y) {
        sx.Update(x);
        sy.Update(y);
        int l = findy(y);
        if (l <= x) Update(l, x);
    }
} Dl, Dr;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> p[i];
        if (i <= p[i]) {
            Dl.y[i] = p[i];
        } else {
            Dr.y[p[i]] = i;
        }
    }
    Dl.build();
    Dr.build();
    while (true) {
        int a = Dl.Se2[1].fi, b = Dr.Se2[1].fi;
        if (a > n && b > n) break;
        if (a < b) {
            Ans = std::max(Ans, a);
            Pair o = Dl.work();
            Dr.work2(o.se, o.fi);
        } else {
            Ans = std::max(Ans, b);
            Pair o = Dr.work();
            Dl.work2(o.se, o.fi);
        }
    }
    std::cout << Ans << '\n';
    return 0;
}