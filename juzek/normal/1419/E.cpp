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

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        std::vector<int> dzielniki;
        dzielniki.push_back(n);
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                dzielniki.push_back(i);
                if (i * i != n)
                    dzielniki.push_back(n / i);
            }
        }
        sort(dzielniki.begin(), dzielniki.end());
        vector<int> pierwsze;
        set<int> zlozone;
        map<int, int> dzielnik;
        for (auto it : dzielniki) {
            bool ok = true;
            for (auto it2 : pierwsze) {
                if (it % it2 == 0) {
                    ok = false;
                    dzielnik[it] = it2;
                    break;
                }
            }
            if (ok)
                pierwsze.push_back(it);
            else
                zlozone.insert(it);
        }
        if (pierwsze.size() == 1) {
            for (auto it : dzielniki)
                printf("%d ", it);
            printf("\n%d\n", 0);
            continue;
        }
        if (zlozone.size() == 1) {
            for (auto it : dzielniki)
                printf("%d ", it);
            printf("\n%d\n", 1);
            continue;
        }
        map<int, vector<int>> dodatki;
        map<int, int> po;
        for (int i = 0; i < pierwsze.size() - 1; i++) {
            int a = pierwsze[i], b = pierwsze[i + 1];
            po[a] = a * b;
            zlozone.erase(a * b);
        }
        po[pierwsze.back()] = n;
        zlozone.erase(n);
        for (auto it : zlozone)
            dodatki[dzielnik[it]].push_back(it);
        for (auto it : pierwsze) {
            printf("%d ", it);
            for (auto it2 : dodatki[it])
                printf("%d ", it2);
            printf("%d ", po[it]);
        }
        printf("\n0\n");
    }
    return 0;
}