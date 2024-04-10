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

const int MAXN = 3 * 100007;
bool spec[MAXN];
int zysk[MAXN], koszt[MAXN];
vector<pii> v[MAXN];
int gl[MAXN], ch[MAXN];
bool odw[MAXN];
bool zla_kr[MAXN];

void dfs(int a, int mgl, int kr) {
    odw[a] = true;
    ch[a] = gl[a] = mgl;
    for (auto it : v[a])
        if (!odw[it.first])
            dfs(it.first, mgl + 1, it.second);
    for (auto it : v[a]) {
        if (gl[it.first] == gl[a] - 1)
            continue;
        else if (gl[it.first] < gl[a])
            ch[a] = min(ch[a], gl[it.first]);
        else
            ch[a] = min(ch[a], ch[it.first]);
    }
    if (ch[a] == gl[a])
        zla_kr[kr] = true;
}

int rep[MAXN];
ll nzysk[MAXN];
bool nspec[MAXN];
int ziomo[MAXN];
ll dp[MAXN];
ll mdp[MAXN];
vector<pii> nv[MAXN];

void dfs2(int a, int nr) {
    odw[a] = true;
    rep[a] = nr;
    nzysk[nr] += zysk[a];
    for (auto it : v[a])
        if (!odw[it.first] && !zla_kr[it.second])
            dfs2(it.first, nr);
}

void dfs26(int a, int oj, int z) {
    ziomo[a] = z;
    for (auto it : nv[a])
        if (it.first != oj)
            dfs26(it.first, a, z);
}

void dfs25(int a, int oj) {
    ziomo[a] = nspec[a] ? 0 : -1;
    for (auto it : nv[a]) {
        if (it.first != oj) {
            dfs25(it.first, a);
            if (ziomo[it.first] == 0)
                ziomo[a] = 0;
        }
    }
    if (ziomo[a] == 0)
        for (auto it : nv[a])
            if (it.first != oj && ziomo[it.first] != 0)
                dfs26(it.first, a, a);
}

void dfs3(int a, int oj) {
    dp[a] = nzysk[a];
    for (auto it : nv[a]) {
        if (it.first != oj && ziomo[it.first] == 0) {
            dfs3(it.first, a);
            dp[a] += max(dp[it.first] - koszt[it.second], 0LL);
        }
    }
}

void dfs4(int a, ll ojdp, int oj) {
    mdp[a] = ojdp + dp[a];
    for (auto it : nv[a]) {
        if (it.first != oj && ziomo[it.first] == 0) {
            ll ndp = max(mdp[a] - max(dp[it.first] - koszt[it.second], 0LL) - koszt[it.second], 0LL);
            dfs4(it.first, ndp, a);
        }
    }
}

int main() {
    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    int cokolwiek;
    for (int i = 0; i < K; i++) {
        int a;
        scanf("%d", &a);
        cokolwiek = a;
        spec[a] = true;
    }
    for (int i = 1; i <= N; i++)
        scanf("%d", zysk + i);
    for (int i = 1; i <= M; i++)
        scanf("%d", koszt + i);
    for (int i = 1; i <= M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back({b, i});
        v[b].push_back({a, i});
    }
    dfs(1, 1, 0);
    memset(odw, 0, sizeof(odw));
    int nn = 0;
    for (int i = 1; i <= N; i++)
        if (!odw[i])
            dfs2(i, ++nn);
    for (int i = 1; i <= N; i++)
        for (auto it : v[i])
            if (zla_kr[it.second])
                nv[rep[i]].push_back({rep[it.first], it.second});
    for (int i = 1; i <= N; i++)
        nspec[rep[i]] |= spec[i];
    cokolwiek = rep[cokolwiek];
    dfs25(cokolwiek, -1);
    for (int i = 1; i <= nn; i++)
        if (ziomo[i] != 0)
            nzysk[ziomo[i]] += nzysk[i];
    dfs3(cokolwiek, -1);
    dfs4(cokolwiek, 0, -1);
    for (int i = 1; i <= N; i++) {
        int rrep = rep[i];
        if (ziomo[rrep] != 0)
            rrep = ziomo[rrep];
        printf("%lld ", mdp[rrep]);
    }
    return 0;
}