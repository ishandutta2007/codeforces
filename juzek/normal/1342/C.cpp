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

int ile_[1000007];

int main() {
    int T;
    scanf("%d", &T);
    int *ile = ile_ + 1;
    while (T--) {
        int a, b, q;
        scanf("%d%d%d", &a, &b, &q);
        int wsum = 0;
        for (int i = 0; i < a * b; i++)
            ile[i] = ile[i - 1] + (((i % a) % b) != ((i % b) % a));
        wsum = ile[a * b - 1];
        while (q--) {
            ll l, r;
            scanf("%lld%lld", &l, &r);
            ll pier = (l / (a * b));
            ll drug = (r / (a * b) + 1);
            ll wyn = (drug - pier) * wsum;
            wyn -= ile[l % (a * b) - 1];
            wyn -= wsum - ile[r % (a * b)];
            printf("%lld ", wyn);
        }
        printf("\n");
    }
    return 0;
}