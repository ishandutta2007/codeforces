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

int tab[507][507];

int main() {
    int N;
    scanf("%d", &N);
    if (N <= 2) {
        printf("-1");
        return 0;
    }
    tab[0][0] = 10 - 9;
    tab[0][1] = 10 - 8;
    tab[0][2] = 10 - 6;
    tab[1][0] = 10 - 5;
    tab[1][1] = 10 - 3;
    tab[1][2] = 10 - 2;
    tab[2][0] = 10 - 1;
    tab[2][1] = 10 - 7;
    tab[2][2] = 10 - 4;
    int ter = 10;
    bool pocz = true;
    for (int i = 3; i < N; i++) {
        if (pocz) {
            for (int w = 0; w < i; w++)
                tab[i][w] = ter++;
            tab[i][i] = ter++;
            for (int w = i - 1; w >= 0; w--)
                tab[w][i] = ter++;
        } else {
            for (int w = 0; w < i; w++)
                tab[w][i] = ter++;
            tab[i][i] = ter++;
            for (int w = i - 1; w >= 0; w--)
                tab[i][w] = ter++;
        }
        pocz = !pocz;
    }
    int qq = N * N + 1;
    for (int i = 0; i < N; i++) {
        for (int w = 0; w < N; w++) {
            printf("%2d ", qq - tab[i][w]);
        }
        printf("\n");
    }
    return 0;
}