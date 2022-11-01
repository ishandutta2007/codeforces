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

ll silnia[1000007];
const int mod = 998244353;

ll binpow(ll a, int n) {
    ll ret = 1;
    while (n != 0) {
        if (n % 2 == 1) {
            ret *= a;
            ret %= mod;
        }
        a *= a;
        a %= mod;
        n /= 2;
    }
    return ret;
}

ll dwumian(int n, int k) {
    return (((silnia[n] * binpow(silnia[k], mod - 2)) % mod) *
            binpow(silnia[n - k], mod - 2)) % mod;
}

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    silnia[0] = 1;
    for (int i = 1; i <= N; i++) {
        silnia[i] = (i * silnia[i - 1]) % mod;
    }
    if (K >= N) {
        printf("0\n");
        return 0;
    }
    int ile = N - K;
    ll wyn = dwumian(N, ile);
    ll ziomo = 0;
    for (int i = 1; i <= ile; i++) {
        ll ter = binpow(i, N - 1);
        ter *= binpow((silnia[i - 1] * silnia[ile - i]) % mod, mod - 2);
        ter %= mod;
        if ((ile - i) % 2 == 0) {
            ziomo += ter;
        } else {
            ziomo -= ter;
        }
        ziomo %= mod;
    }
    debug << ziomo;
    ziomo *= silnia[ile];
    ziomo %= mod;
    ziomo += mod;
    ziomo %= mod;
    wyn *= ziomo;
    if (K != 0)
        wyn *= 2;
    wyn %= mod;
    printf("%lld", wyn);
    return 0;
}