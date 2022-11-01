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

    sim, class m mor pair<m, c> r) { ris << "(" << r.first << ", " << r.second << ")"; }

#else
    sim mor const c&){ris;}
#endif
};

#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r...) "[" #r ": " << (r) << "] "
#define range(a, b) "[[" #a ", " #b "): " << range(a, b) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
using pii = pair<int, int>;
using ld = long double;
using ll = long long;

vector<int> pierwsze;
bool sito[5007];
int ile[5007];
vector<pii> dzielniki[5007];
int ile_dzielnikow[5007];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 2; i <= 5000; i++) {
        if (!sito[i]) {
            pierwsze.push_back(i);
            for (int w = i + i; w <= 5000; w += i)
                sito[w] = true;
        }
    }
    for (int i = 1; i <= 5000; i++) {
        for (auto it : pierwsze) {
            int ile = 0;
            int ziomo = it;
            while (i / ziomo > 0) {
                ile += i / ziomo;
                ziomo *= it;
            }
            if (ile > 0)
                dzielniki[i].push_back({it, ile});
            ile_dzielnikow[i] += ile;
        }
    }
    ll wynik = 0;
    for (int i = 1; i <= N; i++) {
        int a;
        scanf("%d", &a);
        wynik += ile_dzielnikow[a];
        ile[a]++;
    }
    vector<pair<int, int>> dostepne;
    for (int i = 1; i <= 5000; i++)
        if (ile[i] > 0)
            dostepne.push_back({i, ile[i]});
    while (true) {
        vector<pii> nowe;
        bool spoczko = false;
        for (auto dziel : pierwsze) {
            int spoko = 0;
            for (auto it : dostepne)
                if (!dzielniki[it.first].empty() && dzielniki[it.first].back().first == dziel)
                    spoko += it.second;
            if (spoko > N / 2) {
                debug << imie(dziel);
                wynik -= spoko;
                wynik += N - spoko;
                for (auto it : dostepne)
                    if (!dzielniki[it.first].empty() && dzielniki[it.first].back().first == dziel) {
                        dzielniki[it.first].back().second--;
                        if (dzielniki[it.first].back().second == 0)
                            dzielniki[it.first].pop_back();
                        nowe.push_back(it);
                    }
                spoczko = true;
                break;
            }
        }
        if (!spoczko)
            break;
        dostepne = move(nowe);
    }
    printf("%lld", wynik);
    return 0;
}