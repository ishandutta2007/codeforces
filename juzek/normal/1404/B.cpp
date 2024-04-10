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

const int maxn = 1000007;
vector<int> v[maxn];
int sr, odl[maxn], wdol[maxn];

void dfs(int a, int oj = 0) {
    wdol[a] = 1;
    odl[a] = odl[oj] + 1;
    int b1 = 0, b2 = 0;
    for (auto it : v[a]) {
        if (it != oj) {
            dfs(it, a);
            if (wdol[it] >= b1) {
                b2 = b1;
                b1 = wdol[it];
            } else if (wdol[it] > b2) {
                b2 = wdol[it];
            }
        }
    }
    wdol[a] += b1;
    sr = max(sr, 1 + b1 + b2);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, a, b, da, db;
        scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
        for (int i = 1; i < n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        sr = 0;
        odl[0] = -1;
        dfs(a);
        for (int i = 1; i <= n; i++)
            v[i].clear();
        if (odl[b] <= da) {
            printf("Alice\n");
        } else if (2 * da >= sr - 1) {
            printf("Alice\n");
        } else if (2 * da < db) {
            printf("Bob\n");
        } else {
            printf("Alice\n");
        }
    }
    return 0;
}