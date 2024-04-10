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

ll silnie[200007];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<ll> v;
    for (int i = 1; i <= n; i++) {
        ll a;
        scanf("%lld", &a);
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    auto sumy = v;
    for (int i = sumy.size() - 2; i >= 0; i--)
        sumy[i] = (sumy[i] + sumy[i + 1]) % mod;
    silnie[0] = 1;
    for (int i = 1; i <= n; i++)
        silnie[i] = (silnie[i - 1] * i) % mod;
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int pos = lower_bound(v.begin(), v.end(), ll(b)) - v.begin();
        int ile = n - pos;
        ll pduze = max(ile - a, 0) * binpow(ile, mod - 2) % mod;
        ll pmale = max(ile + 1 - a, 0) * binpow(ile + 1, mod - 2) % mod;
        ll wyn = (sumy[pos] * pduze) % mod;
        wyn += (sumy[0] - sumy[pos]) * pmale % mod;
        wyn %= mod;
        wyn += mod;
        wyn %= mod;
        printf("%lld\n", wyn);
    }
    return 0;
}