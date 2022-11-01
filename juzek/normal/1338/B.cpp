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

vector<int> v[1000007];
bool kk = true;
bool odw[1000007];

void dfs(int a, int oj, int war) {
    if (v[a].size() == 1 && war == 1)
        kk = false;
    for (auto it : v[a])
        if (it != oj)
            dfs(it, a, !war);
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
    int liscie = 0;
    int lisc = -1;
    for (int i = 1; i <= N; i++) {
        if (v[i].size() == 1) {
            liscie++;
            lisc = i;
        }
    }
    dfs(lisc, -1, 0);
    int spoko = 0;
    for (int i = 1; i <= N; i++) {
        if (v[i].size() != 1) {
            spoko++;
        } else {
            spoko += !odw[v[i][0]];
            odw[v[i][0]] = true;
        }
    }
    printf("%d %d\n", kk ? 1 : 3, spoko - 1);
    return 0;
}