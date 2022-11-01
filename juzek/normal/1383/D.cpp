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

int tab[257][257];
int res[257][257];

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    set<int> poziome, pionowe;
    for (int i = 1; i <= N; i++) {
        int maxi = 0;
        for (int w = 1; w <= M; w++) {
            scanf("%d", &tab[i][w]);
            maxi = max(maxi, tab[i][w]);
        }
        poziome.insert(maxi);
    }
    for (int i = 1; i <= M; i++) {
        int maxi = 0;
        for (int w = 1; w <= N; w++)
            maxi = max(maxi, tab[w][i]);
        pionowe.insert(maxi);
    }
    queue<pii> Q;
    int W = 0, H = 0;
    for (int i = N * M; i >= 1; i--) {
        if (poziome.count(i))
            H++;
        if (pionowe.count(i))
            W++;
        if (poziome.count(i) || pionowe.count(i))
            res[H][W] = i;
        else {
            pii pos = Q.front();
            Q.pop();
            res[pos.first][pos.second] = i;
        }
        if (pionowe.count(i))
            for (int w = H - 1; w >= 1; w--)
                Q.push({w, W});
        if (poziome.count(i))
            for (int w = W - 1; w >= 1; w--)
                Q.push({H, w});
    }
    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= M; w++)
            printf("%d ", res[i][w]);
        printf("\n");
    }
    return 0;
}