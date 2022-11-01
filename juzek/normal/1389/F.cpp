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

const int z = 4 * 1024 * 256;

int _drzewo[2][z * 2 + 7], _sp[2][z * 2 + 7];

void spychaj(int *drzewo, int *sp, int v) {
    drzewo[v * 2] += sp[v];
    drzewo[v * 2 + 1] += sp[v];
    sp[v * 2] += sp[v];
    sp[v * 2 + 1] += sp[v];
    sp[v] = 0;
}

void wrzuc(int *drzewo, int *sp, int ll, int rr, int war, int v = 1, int l = 0, int r = z - 1) {
    if (r < ll || rr < l)
        return;
    if (ll <= l && r <= rr) {
        drzewo[v] += war;
        sp[v] += war;
        return;
    }
    spychaj(drzewo, sp, v);
    int sr = (l + r) / 2;
    wrzuc(drzewo, sp, ll, rr, war, v * 2, l, sr);
    wrzuc(drzewo, sp, ll, rr, war, v * 2 + 1, sr + 1, r);
    drzewo[v] = max(drzewo[v * 2], drzewo[v * 2 + 1]);
}

int czytaj(int *drzewo, int *sp, int ll, int rr, int v = 1, int l = 0, int r = z - 1) {
    if (r < ll || rr < l)
        return 0;
    if (ll <= l && r <= rr)
        return drzewo[v];
    spychaj(drzewo, sp, v);
    int sr = (l + r) / 2;
    return max(czytaj(drzewo, sp, ll, rr, v * 2, l, sr), czytaj(drzewo, sp, ll, rr, v * 2 + 1, sr + 1, r));
}

int main() {
    int N;
    scanf("%d", &N);
    vector<pair<pii, int>> v;
    map<int, int> skala;
    for (int i = 0; i < N; i++) {
        int l, r, t;
        scanf("%d%d%d", &l, &r, &t);
        skala[l] = 0;
        skala[r] = 0;
        v.push_back({{l, r}, t});
    }
    sort(v.begin(), v.end(), [](pair<pii, int> const& a, pair<pii, int> const& b) {
        return a.first.second < b.first.second;
    });
    int zeit = 0;
    for (auto &it : skala)
        it.second = ++zeit;
//    for (auto &it : skala)
//        it.second = it.first;
    int maxi = 0;
    for (auto it : v) {
        int l = skala[it.first.first], r = skala[it.first.second], t = it.second - 1;
        debug << imie(l) imie(r) imie(t);
        wrzuc(_drzewo[t], _sp[t], 0, l - 1, 1);
        int hmm = czytaj(_drzewo[t], _sp[t], 0, l - 1);
        int hmm2 = czytaj(_drzewo[!t], _sp[!t], r, r);
        debug << imie(hmm) imie(hmm2);
        maxi = max(maxi, hmm);
        if (hmm2 < hmm)
            wrzuc(_drzewo[!t], _sp[!t], r, r, hmm - hmm2);
    }
    printf("%d", maxi);
    return 0;
}