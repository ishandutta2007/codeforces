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

#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "19
#define imie(r) "[" #r ": " << (r) << "] "
#define range(a, b) "[[" #a ", " #b "): " << range(a, b) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
using pii = pair<int, int>;
using ld = long double;
using ll = long long;

ll rozwal(ll rozm, ll x) {
    if (rozm == 1)
        return 0;
    ll czesc = rozm / 4;
    if (x >= czesc * 3) {
        return czesc + rozwal(rozm / 4, x - czesc * 3);
    } else if (x >= czesc * 2) {
        return 3 * czesc + rozwal(rozm / 4, x - czesc * 2);
    } else if (x >= czesc) {
        return 2 * czesc + rozwal(rozm / 4, x - czesc);
    } else {
        return rozwal(rozm / 4, x);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        ll n;
        scanf("%lld", &n);
        ll cc = (n - 1) / 3;
        ll rozm = 1;
        ll suma = 0;
        while (suma + rozm <= cc) {
            suma += rozm;
            rozm *= 4;
        }
        ll a = cc - suma + rozm;
        ll b = rozm * 2 + rozwal(rozm, cc - suma);
        ll c = a ^ b;
        if (n % 3 == 1)
            printf("%lld\n", a);
        else if (n % 3 == 2)
            printf("%lld\n", b);
        else
            printf("%lld\n", c);
    }
    return 0;
}