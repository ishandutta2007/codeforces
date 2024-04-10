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

int tab[2048 * 2048 + 7];

bool f(int i, int g) {
    int lewy = 2 * i, prawy = 2 * i + 1;
    if (tab[lewy] == 0 && tab[prawy] == 0) {
        if (g <= 0) {
            tab[i] = 0;
            return true;
        } else
            return false;
    } else {
        if (tab[lewy] > tab[prawy]) {
            int tmp = tab[lewy];
            if (f(lewy, g - 1)) {
                tab[i] = tmp;
                return true;
            } else
                return false;
        } else {
            int tmp = tab[prawy];
            if (f(prawy, g - 1)) {
                tab[i] = tmp;
                return true;
            } else
                return false;
        }
    }
}

vector<int> odp;

ll suma = 0;

void rozwal(int x, int g) {
    if (tab[x] == 0)
        return;
    int ter = tab[x];
    while (ter != 0 && f(x, g)) {
        odp.push_back(x);
        suma -= ter;
        ter = tab[x];
    }
    if (ter == 0)
        return;
    rozwal(x * 2, g - 1);
    rozwal(x * 2 + 1, g - 1);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int h, g;
        scanf("%d%d", &h, &g);
        int N = 1;
        for (int i = 0; i < h; i++)
            N *= 2;
        memset(tab, 0, sizeof(int) * N * 2);
        N--;
        suma = 0;
        for (int i = 1; i <= N; i++) {
            scanf("%d", &tab[i]);
            suma += tab[i];
        }
        rozwal(1, g);
        printf("%lld\n", suma);
        for (auto it : odp)
            printf("%d ", it);
        odp.clear();
        printf("\n");
    }
    return 0;
}