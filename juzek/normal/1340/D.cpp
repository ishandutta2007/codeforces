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

vector<int> v[100007];
vector<pii> odp;

void dfs(int a, int oj, int war) {
    odp.push_back({a, war});
    if (a == 1) {
        for (auto it : v[a]) {
            dfs(it, a, ++war);
            odp.push_back({a, war});
        }
    } else {
        int skoncze = war - 1;
        int synowie = v[a].size() - 1;
        bool juz = false;
        for (auto it : v[a]) {
            if (it != oj) {
                if (skoncze - synowie < 0) {
                    dfs(it, a, ++war);
                    odp.push_back({a, war});
                } else {
                    if (!juz) {
                        juz = true;
                        war = skoncze - synowie;
                        odp.push_back({a, war});
                    }
                    dfs(it, a, ++war);
                    odp.push_back({a, war});
                }
                synowie--;
            }
        }
        if (war != skoncze)
            odp.push_back({a, skoncze});
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 2; i <= N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0, 0);
    printf("%d\n", int(odp.size()));
    for (auto it : odp)
        printf("%d %d\n", it.first, it.second);
    return 0;
}