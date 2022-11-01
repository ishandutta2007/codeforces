#ifndef LOCAL
#pragma GCC optimize("O3")
#endif

#include <bits/stdc++.h>

using namespace std;
#define sim template <class c
#define mor > muu & operator<<(
#define ris return *this
#define R22(r) sim>typename enable_if<1 r sizeof(dud<c>(0)),muu&>::type operator<<(c g) {
sim>
struct rge {
    c b, e;
};

sim> rge<c> range(c i, c j) { return rge<c>{i, j}; }

sim> auto dud(c *r) -> decltype(cerr << *r);

sim> char dud(...);

struct muu {
#ifdef LOCAL
    stringstream a;

    ~muu() { cerr << a.str() << endl; }

    R22(<) a << boolalpha << g;
        ris; }

    R22(==) ris << range(begin(g), end(g)); }

    sim mor rge<c> u) {
        a << "[";
        for (c i = u.b; i != u.e; ++i)
            *this << ", " + 2 * (i == u.b) << *i;
        ris << "]";
    }

    sim, class m mor pair<m, c> r) {
        ris << "(" << r.first << ", " << r.second << ")";
    }

#else
    sim mor const c&){ris;}
#endif
};

#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r) "[" #r ": " << (r) << "] "
#define range(a, b) "[[" #a ", " #b "): " << range(a, b) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
using pii = pair<int, int>;
using ld = long double;
using ll = long long;

struct V {
    int zyje, pociski;
};

const int z = 1024 * 512;
V drzewo[z * 2 + 7];

void dorzuc(int x, int zyje, int pociski) {
    x += z - 1;
    drzewo[x].zyje += zyje;
    drzewo[x].pociski += pociski;
    if (drzewo[x].zyje == 1 && drzewo[x].pociski == 1)
        drzewo[x].zyje = drzewo[x].pociski = 0;
    x /= 2;
    while (x != 0) {
        drzewo[x].zyje =
                max(drzewo[x * 2].zyje - drzewo[x * 2 + 1].pociski, 0) +
                drzewo[x * 2 + 1].zyje;
        drzewo[x].pociski =
                max(drzewo[x * 2 + 1].pociski - drzewo[x * 2].zyje, 0) +
                drzewo[x * 2].pociski;
        x /= 2;
    }
}

V czytaj(int v, int l, int r, int ll, int rr) {
    if (r < ll || l > rr)
        return {0, 0};
    if (ll <= l && r <= rr)
        return drzewo[v];
    int sr = (l + r) / 2;
    V lewy = czytaj(v * 2, l, sr, ll, rr);
    V prawy = czytaj(v * 2 + 1, sr + 1, r, ll, rr);
    V zlacz;
    zlacz.zyje = max(lewy.zyje - prawy.pociski, 0) + prawy.zyje;
    zlacz.pociski = max(prawy.pociski - lewy.zyje, 0) + lewy.pociski;
    return zlacz;
}

int p[1000007];
int pos[1000007];
int ter;
int N;

bool sprawdz_zywot(int x) {
    V lewy = czytaj(1, 1, z, 1, pos[x] - 1);
    V prawy = czytaj(1, 1, z, pos[x], N);
    return prawy.pociski <= lewy.zyje;
}

void wylicz_maksa() {
    while (!sprawdz_zywot(ter)) {
        dorzuc(pos[ter], 1, 0);
        ter--;
    }
}

int main() {
    scanf("%d", &N);
    ter = N;
    for (int i = 1; i <= N; i++) {
        scanf("%d", p + i);
        pos[p[i]] = i;
    }
    for (int i = 1; i <= N; i++) {
        int bobma;
        scanf("%d", &bobma);
        wylicz_maksa();
        printf("%d ", ter);
        dorzuc(bobma, 0, 1);
    }
    return 0;
}