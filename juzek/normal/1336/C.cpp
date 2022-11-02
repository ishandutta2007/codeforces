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

int dp[3007][3007];
const int mod = 998244353;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    ll odp = 0;
    int q = s1.size();
    for (int i = (int) q - 1; i >= 0; i--) {
        if (i + 1 >= s2.size())
            dp[i + 1][0] += 1;
        for (int w = 1; w <= q - i; w++)
            if (w - 1 >= s2.size() || s1[i] == s2[w - 1])
                dp[i][w] += dp[i + 1][w - 1];
        for (int w = 0; q - i - w > 0; w++) {
            int bylo_jedynek = q - i - w;
            if (q - bylo_jedynek >= s2.size() || s1[i] == s2[q - bylo_jedynek])
                dp[i][w] += dp[i + 1][w];
        }
        for (int w = 0; w <= q - i; w++)
            if (dp[i][w] >= mod)
                dp[i][w] -= mod;
    }
    for (int w = 0; w <= s1.size(); w++) {
        odp += dp[0][w];
        odp %= mod;
    }

    printf("%lld", odp);
    return 0;
}