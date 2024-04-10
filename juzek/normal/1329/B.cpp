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
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "pii
using pii = pair<int, int>;
using ld = long double;
using ll = long long;

ll potegi[40];

int main() {
    potegi[0] = 1;
    for (int i = 1; potegi[i - 1] <= 5000000000LL; i++)
        potegi[i] = potegi[i - 1] * 2;
    int T;
    scanf("%d", &T);
    while (T--) {
        int d, m;
        scanf("%d%d", &d, &m);
        int koniec = -1;
        while (potegi[koniec + 1] <= d)
            koniec++;
        ll tmp = potegi[koniec];
        potegi[koniec] = d - tmp + 1;
        ll ter = 0;
        for (int i = 0; i <= koniec; i++) {
            ter = ter + potegi[i] + ter * potegi[i];
            ter %= m;
        }
        potegi[koniec] = tmp;
        printf("%lld\n", ter);
    }
    return 0;
}