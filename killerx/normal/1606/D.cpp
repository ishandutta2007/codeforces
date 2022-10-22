#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e6 + 5;

std::mt19937_64 rng;
uint64_t va[mxn];
struct INIT {
    INIT() {
        rep(i, mxn) va[i] = rng();
    }
} __INIT;

int n, m, buf[mxn], *a[mxn];

struct Range { int l, r, i; };

bool operator < (const Range &a, const Range &b) { return a.l < b.l; }

void Main() {
    scanf("%d %d", &n, &m);
    a[0] = buf;
    rep(i, n) a[i + 1] = a[i] + m;
    rep(i, n) rep(j, m) scanf("%d", &a[i][j]);
    static std::vector <int> premin[mxn], premax[mxn], sufmin[mxn], sufmax[mxn];
    rep(i, n) {
        premin[i].resize(m), premax[i].resize(m), sufmin[i].resize(m), sufmax[i].resize(m);
        rep(j, m) premin[i][j] = std::min((j ? premin[i][j - 1] : 0x3f3f3f3f), a[i][j]);
        rep(j, m) premax[i][j] = std::max((j ? premax[i][j - 1] : -0x3f3f3f3f), a[i][j]);
        for (int j = m - 1; ~j; -- j) sufmin[i][j] = std::min((j + 1 < m ? sufmin[i][j + 1] : 0x3f3f3f3f), a[i][j]);
        for (int j = m - 1; ~j; -- j) sufmax[i][j] = std::max((j + 1 < m ? sufmax[i][j + 1] : -0x3f3f3f3f), a[i][j]);
    }
    for (int K = 0; K < m - 1; ++ K) {
        std::vector <int> uf(n);
        std::function <int(int)> find = [&] (int x) {
            return x == uf[x] ? x : uf[x] = find(uf[x]);
        };
        std::function <void(int, int)> merge = [&] (int x, int y) {
            uf[find(x)] = find(y);
        };
        std::set <Range> S;
        std::function <void(int, int, int)> add = [&] (int l, int r, int i) {
            auto it = S.lower_bound({l, r, i});
            if (it != S.begin()) {
                -- it;
                if (it->r < l) ++ it;
            }
            int L = l, R = r;
            while (it != S.end() && std::max(it->l, l) <= std::min(it->r, r)) {
                L = std::min(L, it->l);
                R = std::max(R, it->r);
                merge(it->i, i);
                it = S.erase(it);
            }
            S.insert({L, R, i});
        };
        std::function <std::vector <uint64_t>()> DO = [&] () {
            std::vector <uint64_t> V(n);
            rep(i, n) V[find(i)] ^= va[i];
            return V;
        };
        S.clear(); std::iota(uf.begin(), uf.end(), 0);
        rep(i, n) add(premin[i][K], premax[i][K], i);
        auto Sl = S;
        auto Vl = DO();
        auto ufl = uf;
        S.clear(); std::iota(uf.begin(), uf.end(), 0);
        rep(i, n) add(sufmin[i][K + 1], sufmax[i][K + 1], i);
        auto Sr = S;
        auto Vr = DO();
        auto ufr = uf;
        std::set <uint64_t> st;
        {
            uint64_t x = 0;
            for (auto it = Sr.rbegin(); it != Sr.rend(); ++ it)
                st.insert(x ^= Vr[it->i]);
        }
        {
            uint64_t x = 0;
            for (auto it = Sl.begin(); it != Sl.end(); ++ it) {
                if (st.find(x) != st.end()) {
                    std::vector <bool> ok(n);
                    for (auto jt = Sl.begin(); jt != it; ++ jt) ok[jt->i] = true;
                    std::vector <bool> col(n);
                    uf = ufl;
                    rep(i, n) if (ok[find(i)]) col[i] = true;
                    puts("YES");
                    rep(i, n) putchar("RB"[col[i]]);
                    printf(" %d\n", K + 1);
                    return ;
                }
                x ^= Vl[it->i];
            }
        }
    }
    puts("NO");
}

int main() {
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif
    int T; scanf("%d", &T);
    while (T --) Main();
    return 0;
}