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

vector<int> v[3007];
int wkierunku[3007][3007];
int gl[3007];
int rozm[3007];
bool obl[3007][3007];
ll dp[3007][3007];
int moj[3007];

int dfs_gl(int a, int oj, int mgl) {
    gl[a] = mgl;
    moj[a] = oj;
    rozm[a] = 1;
    for (auto it : v[a])
        if (it != oj)
            rozm[a] += dfs_gl(it, a, mgl + 1);
    return rozm[a];
}

void dfs(int a, int sk, int oj = -1, int kier = -1) {
    wkierunku[sk][a] = kier;
    for (auto it : v[a]) {
        if (it != oj) {
            if (kier == -1)
                dfs(it, sk, a, it);
            else
                dfs(it, sk, a, kier);
        }
    }
}

int N;

ll adam(int a, int b) {
    if (gl[a] > gl[b])
        swap(a, b);
    if (obl[a][b])
        return dp[a][b];
    obl[a][b] = true;
    if (moj[b] == a) // obok
        return dp[a][b] = ll(rozm[b]) * (N - rozm[b]);
    ll dod = ll(rozm[b]) * rozm[a];
    if (moj[wkierunku[a][b]] == a)
        dod = ll(rozm[b]) * (N - rozm[wkierunku[a][b]]);
    return dp[a][b] = dod + max(adam(wkierunku[a][b], b), adam(a, wkierunku[b][a]));
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
        dfs(i, i);
    dfs_gl(1, -1, 1);
    ll maxi = 0;
    for (int i = 1; i <= N; i++)
        for (int w = i + 1; w <= N; w++)
            maxi = max(maxi, adam(i, w));
    printf("%lld", maxi);
    return 0;
}