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
char s1[maxn], s2[maxn];
set<int> chce['z' + 7];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        scanf(" %s %s", s1, s2);
        for (int i = 'a'; i <= 'z'; i++)
            chce[i].clear();
        for (int i = 0; i < n; i++)
            if (s1[i] != s2[i])
                chce[s1[i]].insert(s2[i]);
        bool ok = true;
        int ile = 0;
        for (int i = 'a'; i <= 'z'; i++) {
            auto it = chce[i].begin();
            if (it != chce[i].end()) {
                if (*it < i) {
                    ok = false;
                    break;
                }
                int gdzie = *it;
                ile++;
                it++;
                while (it != chce[i].end()) {
                    chce[gdzie].insert(*it);
                    it++;
                }
            }
        }
        if (ok)
            printf("%d\n", ile);
        else
            printf("-1\n");
    }
    return 0;
}