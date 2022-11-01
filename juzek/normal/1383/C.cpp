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
int pot[24];
int maski[24];
bool dp[1 << 21];
bool jest[24];
int rep[24];

int find(int a) {
    if (rep[a] == a)
        return a;
    return rep[a] = find(rep[a]);
}

int main() {
    int t;
    scanf("%d", &t);
    pot[0] = 1;
    for (int i = 1; i <= 20; i++)
        pot[i] = pot[i - 1] * 2;
    while (t--) {
        int n;
        scanf("%d", &n);
        scanf(" %s %s", s1, s2);
        memset(maski, 0, sizeof(maski));
        memset(dp, 0, sizeof(dp));
        memset(jest, 0, sizeof(jest));
        for (int i = 0; i < 20; i++)
            rep[i] = i;
        int zl = 0;
        int ile = 0;
        for (int i = 0; i < n; i++)
            if (s1[i] != s2[i]) {
                maski[s1[i] - 'a'] |= pot[s2[i] - 'a'];
                ile += !jest[s1[i] - 'a'];
                jest[s1[i] - 'a'] = true;
                ile += !jest[s2[i] - 'a'];
                jest[s2[i] - 'a'] = true;
                if (find(s1[i] - 'a') != find(s2[i] - 'a')) {
                    rep[find(s1[i] - 'a')] = find(s2[i] - 'a');
                    zl++;
                }
            }
        const int maxpot = 20;
        int maxi = 0;
        dp[0] = true;
        for (int i = 1; i < pot[maxpot]; i++) {
            bool out = false;
            for (int j = 0; j < maxpot; j++)
                if ((i & pot[j]) && jest[j])
                    out |= dp[i ^ pot[j]] && ((maski[j] & i) == 0);
            dp[i] = out;
            if (out)
                maxi = max(maxi, __builtin_popcount(i));
        }
        printf("%d\n", 2 * ile - maxi - (ile - zl));
    }
    return 0;
}