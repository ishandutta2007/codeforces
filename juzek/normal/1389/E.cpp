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

int brut(int M, int D, int W) {
    int K = min(M, D);
    int ile = 0;
    for (int x = 1; x <= K; x++) {
        for (int y = x + 1; y <= K; y++) {
            if (((x - 1) * D + y) % W == ((y - 1) * D + x) % W) {
//                debug << imie(x) imie(y) imie(y - x);
                ile++;
            }
        }
    }
    return ile;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int M, D, W;
        scanf("%d%d%d", &M, &D, &W);
        int x = __gcd(D - 1, W);
        int odw = W / x;
        int K = min(M, D);
        int wsp = 1;
        while (2 * wsp <= K)
            wsp *= 2;
        int ile = 0;
        while (wsp != 0) {
            if ((ll) odw * (ile + wsp) <= K)
                ile += wsp;
            wsp /= 2;
        }
        ll hmm = ll(ile) * (ile + 1) / 2;
        printf("%lld\n", (ll) K * ile - hmm * odw);
    }
    return 0;
}