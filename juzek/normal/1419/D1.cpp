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

const int maxn = 100007;
int tab[maxn];
int n;

std::vector<int> odp;

bool sprawdz(int rozm) {
    std::vector<int> duze, male;
    for (int i = 0; i < rozm; i++)
        male.push_back(tab[i]);
    for (int i = rozm; i < n; i++)
        duze.push_back(tab[i]);
    std::reverse(duze.begin(), duze.end());
    int poprz = -1337133713;
    odp.clear();
    for (auto it : male) {
        if (poprz <= it) {
            while (!duze.empty() && duze.back() <= it)
                duze.pop_back();
            if (duze.empty())
                return false;
            odp.push_back(duze.back());
            duze.pop_back();
        }
        odp.push_back(it);
        while (!duze.empty() && duze.back() <= it)
            duze.pop_back();
        if (duze.empty())
            return false;
        poprz = duze.back();
        odp.push_back(duze.back());
        duze.pop_back();
    }
    for (auto it : duze)
        odp.push_back(it);
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &tab[i]);
    std::sort(tab, tab + n);
    int pocz = 0, kon = n;
    while (pocz != kon - 1) {
        int sr = (pocz + kon) / 2;
        if (sprawdz(sr))
            pocz = sr;
        else
            kon = sr;
    }
    printf("%d\n", pocz);
    if (pocz == 0) {
        for (int i = 0; i < n; i++)
            printf("%d ", tab[i]);
        return 0;
    }
    sprawdz(pocz);
    for (auto it : odp)
        printf("%d ", it);
    return 0;
}