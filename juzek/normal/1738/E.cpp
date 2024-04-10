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

    sim mor const c &) { ris; }

#endif
};

#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r) "[" #r ": " << (r) << "] "
#define range(a, b) "[[" #a ", " #b "): " << range(a, b) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
using pii = pair<int, int>;
using ld = long double;
using ll = long long;

const int maxn = 100007;
const int mod = 998244353;
int tab[maxn];

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b != 0) {
        if (b % 2 == 1) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b /= 2;
    }
    return res;
}

ll silnie[maxn];

pii count_zeros(int l, int r) {
    int l0 = 0, r0 = 0;
    for (int i = l; i <= r; i++)
        if (tab[i] == 0)
            l0 += 1;
        else
            break;
    for (int i = r; i >= l; i--)
        if (tab[i] == 0)
            r0 += 1;
        else
            break;
    return {l0, r0};
}

ll solve(int l, int r) {
    debug << imie(l) imie(r);
    if (l > r)
        return 1;
    auto[l0, r0] = count_zeros(l, r);
    if (l0 == r - l + 1) {
        ll res = 1;
        for (int i = 1; i < l0; i++)
            res = (res * 2) % mod;
        return res;
    }
    if (l0 > 0 && r0 > 0) {
        ll sum = 0;
        for (int k = 0; k <= l0 && k <= r0; k++) {
            ll res = 1;
            ll odw = 1;
            res = (res * silnie[l0]) % mod;
            res = (res * silnie[r0]) % mod;
            odw = (odw * silnie[k]) % mod;
            odw = (odw * silnie[k]) % mod;
            odw = (odw * silnie[l0 - k]) % mod;
            odw = (odw * silnie[r0 - k]) % mod;
            res = (res * binpow(odw, mod - 2)) % mod;
            sum = (sum + res) % mod;
        }
        return (sum * solve(l + l0, r - r0)) % mod;
    }
    ll sumL = 0, sumR = 0;
    int wsk = r + 1;
    int nl = -1, nr = -1;
    for (int i = l; i < r; i++) {
        sumL += tab[i];
        while (wsk > i + 1 && sumR < sumL) {
            wsk--;
            sumR += tab[wsk];
        }
        if (sumL > 0 && sumL == sumR) {
            nl = i + 1;
            nr = wsk - 1;
            break;
        }
        if (i == wsk - 1)
            break;
    }
    if (nl == -1)
        return 1;
    auto[nl0, nr0] = count_zeros(nl, nr);
    if (nr >= nl && nl0 == nr - nl + 1) {
        ll res = solve(nl, nr);
        res = (res * 4) % mod;
        return res;
    }
    ll sum = 0;
    l0 = nl0 + 1, r0 = nr0 + 1;
    for (int k = 0; k <= l0 && k <= r0; k++) {
        ll res = 1;
        ll odw = 1;
        res = (res * silnie[l0]) % mod;
        res = (res * silnie[r0]) % mod;
        odw = (odw * silnie[k]) % mod;
        odw = (odw * silnie[k]) % mod;
        odw = (odw * silnie[l0 - k]) % mod;
        odw = (odw * silnie[r0 - k]) % mod;
        res = (res * binpow(odw, mod - 2)) % mod;
        sum = (sum + res) % mod;
    }
    return (sum * solve(nl + nl0, nr - nr0)) % mod;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &tab[i]);
        silnie[0] = 1;
        for (int i = 1; i <= n; i++)
            silnie[i] = (silnie[i - 1] * i) % mod;
        auto rozw = solve(1, n);
        debug << imie(rozw);
        printf("%lld\n", rozw);
    }
    return 0;
}