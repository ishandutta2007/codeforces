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

vector<int> v[200007], odv[200007];
bool odw[200007];
bool teraz[200007];
int wa[200007], wb[200007];

void dfs(int a, vector<int> *vv, int *wynik) {
    odw[a] = true;
    teraz[a] = true;
    wynik[a] = a;
    for (auto it : vv[a]) {
        if (!odw[it])
            dfs(it, vv, wynik);
        else {
            if (teraz[it]) {
                printf("-1");
                exit(0);
            }
        }
        wynik[a] = min(wynik[a], wynik[it]);
    }
    teraz[a] = false;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        v[b].push_back(a);
        odv[a].push_back(b);
    }
    for (int i = 1; i <= N; i++)
        if (!odw[i])
            dfs(i, v, wa);
    memset(odw, 0, sizeof(odw));
    for (int i = 1; i <= N; i++)
        if (!odw[i])
            dfs(i, odv, wb);
    int ile = 0;
    for (int i = 1; i <= N; i++)
        if (i == wa[i] && i == wb[i])
            ile++;
    printf("%d\n", ile);
    for (int i = 1; i <= N; i++) {
        if (i == wa[i] && i == wb[i])
            printf("A");
        else
            printf("E");
    }
    return 0;
}