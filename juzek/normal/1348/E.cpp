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

bool moge[507];
bool nowe_moge[507];
int a[100007], b[10007];

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    int sa = 0, sb = 0;
    ll ziomki = 0;
    ll ssa = 0, ssb = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d%d", a + i, b + i);
        sa += a[i], sb += b[i];
        ssa += a[i], ssb += b[i];
        sa %= K;
        sb %= K;
    }
    ziomki += ssa / K;
    ziomki += ssb / K;
    debug << imie(ziomki);
    debug << imie(sa) imie(sb);
    nowe_moge[sa] = true;
    for (int i = 0; i < N; i++) {
        memcpy(moge, nowe_moge, sizeof(moge));
        for (int aa = 0; aa <= min(a[i], K); aa++) {
            int bb = K - aa;
            if (bb > b[i])
                continue;
            for (int q = 0; q < K; q++)
                nowe_moge[(q + bb) % K] |= moge[q];
        }
    }
    debug << range(nowe_moge, nowe_moge + K);
    int maxi = 0;
    for (int i = 0; i < K; i++) {
        if (nowe_moge[i]) {
            int za = i - sa;
            if (za < 0)
                za += K;
            int zb = K - za;
            int na = sa + za;
            int nb = sb + zb;
            na %= K;
            nb %= K;
            int ile = 0;
            ile += na == 0;
            ile += nb == 0;
            maxi = max(maxi, ile);
        }
    }
    if (maxi == 2) {
        printf("%lld\n", (ssa + ssb) / K);
    } else if (maxi == 1) {
        printf("%lld\n", (ssa + ssb) / K);
    } else {
        printf("%lld\n", ziomki);
    }
    return 0;
}