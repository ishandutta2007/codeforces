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

int rozm[200007];
int ile[200007];
int ile_tmp[200007];

int gdzie[200007];
int czo[200007];
vector<int> odp[200007];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &rozm[i]);
    sort(rozm + 1, rozm + n + 1);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &ile[i]);
    }
    for (int i = 1; i <= k; i++)
        ile[i] -= ile[i + 1];
    int pocz = 0, kon = n;
    auto ch = [&](int sr) {
        int ter = 1;
        for (int i = 1; i <= k; i++)
            ile_tmp[i] = (int) min(ll(n), (ll) ile[i] * sr);
        bool kk = true;
        for (int i = 1; i <= n; i++) {
            while (rozm[i] > ter)
                ter++;
            while (ter <= k && ile_tmp[ter] == 0)
                ter++;
            if (ter == k + 1)
                kk = false;
            else {
                gdzie[i] = ter;
                ile_tmp[ter]--;
            }
        }
        return kk;
    };
    while (pocz != kon - 1) {
        int sr = (pocz + kon) / 2;
        if (ch(sr))
            kon = sr;
        else
            pocz = sr;
    }
    printf("%d\n", kon);
    ch(kon);
    for (int i = 1; i <= k; i++)
        ile_tmp[i] = (int) ile[i];
    for (int i = 1; i <= n; i++) {
        if (ile_tmp[gdzie[i]] == 0) {
            ile_tmp[gdzie[i]] = ile[gdzie[i]];
            czo[gdzie[i]]++;
        }
        ile_tmp[gdzie[i]]--;
        odp[czo[gdzie[i]]].push_back(rozm[i]);
    }
    for (int i = 0; i < kon; i++) {
        printf("%d ", (int) odp[i].size());
        for (auto it : odp[i])
            printf("%d ", it);
        printf("\n");
    }
    return 0;
}