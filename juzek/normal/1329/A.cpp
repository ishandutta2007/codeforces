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

vector<int> odp;

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    vector<int> ziomki;
    bool kk = true;
    ll suma = 0;
    for (int i = 0; i < M; i++) {
        int a;
        scanf("%d", &a);
        ziomki.push_back(a);
        odp.push_back(i + 1);
        if (i + a > N)
            kk = false;
        suma += a;
    }
    if (!kk || suma < N) {
        printf("-1");
        return 0;
    }
    int doPokrycia = N;
    for (int i = M - 1; i >= 0; i--) {
        if (odp[i] + ziomki[i] - 1 < doPokrycia)
            odp[i] = doPokrycia - ziomki[i] + 1;
        doPokrycia = odp[i] - 1;
    }
    for (int i = 0; i < M; i++)
        printf("%d ", odp[i]);
    return 0;
}