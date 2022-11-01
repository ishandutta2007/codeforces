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

#define int ll

ll ziomo[64];
ll pot[64];
int N, M;
ll odp[64];
const int mod = 998244353;
ll dp[131072 * 4][64];

int chujow(ll x) {
    int ret = 0;
    while (x != 0) {
        ret += x % 2;
        x /= 2;
    }
    return ret;
}

void paluj(int x, int ter) {
    if (x == M) {
        odp[chujow(ter)]++;
        return;
    }
    if (ziomo[x] == 0) {
        paluj(x + 1, ter);
        return;
    }
    paluj(x + 1, ter);
    paluj(x + 1, ter ^ ziomo[x]);
}

int32_t main() {
    scanf("%lld%lld", &N, &M);
    pot[0] = 1;
    for (int i = 1; i < M; i++)
        pot[i] = pot[i - 1] * 2;
    int niezalezne = 0;
    for (int i = 0; i < N; i++) {
        ll x;
        scanf("%lld", &x);
        for (int w = M - 1; w >= 0; w--) {
            if ((x & pot[w])) {
                if (ziomo[w] == 0) {
                    ziomo[w] = x;
                    break;
                } else
                    x ^= ziomo[w];
            }
        }
        niezalezne += x != 0;
    }
    for (int w = 0; w < M; w++)
        for (int q = w + 1; q < M; q++)
            if ((ziomo[q] & pot[w]))
                ziomo[q] ^= ziomo[w];
    for (int w = 0; w < M; w++)
        if (ziomo[w] != 0)
            debug << ziomo[w];
    ll siema = 1;
    for (int i = 0; i < N - niezalezne; i++) {
        siema *= 2;
        siema %= mod;
    }
    if (niezalezne * 2 <= M) {
        paluj(0, 0);
    } else {
        vector<int> chuj;
        vector<int> ziemniaki;
        for (int w = 0; w < M; w++)
            if (ziomo[w] == 0)
                chuj.push_back(w);
        for (int w = 0; w < M; w++) {
            if (ziomo[w] != 0) {
                int kur = 0;
                int licznik = 0;
                for (auto it : chuj) {
                    if ((ziomo[w] & pot[it]))
                        kur += pot[licznik];
                    licznik++;
                }
                ziemniaki.push_back(kur);
            }
        }
        int gowno = pot[chuj.size()];
        dp[0][0] = 1;
        for (auto it : ziemniaki) {
            for (int ile = niezalezne; ile > 0; ile--) {
                for (int maska = 0; maska < gowno; maska++) {
                    dp[maska][ile] += dp[maska ^ it][ile - 1];
                }
            }
        }
        for (int ile = 0; ile <= niezalezne; ile++) {
            for (int i = 0; i < gowno; i++) {
                odp[ile + chujow(i)] += dp[i][ile];
                odp[ile + chujow(i)] %= mod;
            }
        }
    }
    for (int i = 0; i <= M; i++)
        printf("%lld ", (siema * odp[i]) % mod);
    return 0;
}