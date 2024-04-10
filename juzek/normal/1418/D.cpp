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

set<int> pos;
multiset<int> roz;
const int inf = 1337133713;

void dodaj(int x) {
    int po = *pos.lower_bound(x), przed = *--pos.lower_bound(x);
    if (po != inf && przed != -inf)
        roz.erase(roz.find(po - przed));
    pos.insert(x);
    if (po != inf)
        roz.insert(po - x);
    if (przed != -inf)
        roz.insert(x - przed);
}

void usun(int x) {
    int przed = *--pos.find(x), po = *++pos.find(x);
    if (przed != -inf)
        roz.erase(roz.find(x - przed));
    if (po != inf)
        roz.erase(roz.find(po - x));
    if (przed != -inf && po != inf)
        roz.insert(po - przed);
    pos.erase(x);
}

int policz() {
    if (pos.size() <= 3)
        return 0;
    int odl = *++pos.rbegin() - *++pos.begin();
    return odl - *roz.rbegin();
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    pos.insert(-inf);
    pos.insert(inf);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        dodaj(a);
    }
    printf("%d\n", policz());
    while (q--) {
        int t, x;
        scanf("%d%d", &t, &x);
        if (t) dodaj(x);
        else usun(x);
        printf("%d\n", policz());
    }
    return 0;
}