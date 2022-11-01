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

ll dp[10007][1007];
int pos[100007];

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= K; i++) {
        scanf("%d", &pos[i]);
        for (int w = 0; w <= 1000; w++)
            dp[i][w] = LLONG_MAX;
    }
    sort(pos + 1, pos + K + 1);
    int G, R;
    scanf("%d%d", &G, &R);
    vector<pair<ll, pii>> Q, Q2;
    dp[1][0] = 0;
    Q2.push_back({0, {1, 0}});
    while (!Q2.empty()) {
        Q = move(Q2);
        while (!Q.empty()) {
            pair<ll, pii> ter = Q.back();
            Q.pop_back();
            int a = ter.second.first, r = ter.second.second;
            if (dp[a][r] != ter.first)
                continue;
            debug << ter;
            if (a != K && r + pos[a + 1] - pos[a] <= G) {
                int nr = r + pos[a + 1] - pos[a];
                ll nc = pos[a + 1] - pos[a] + ter.first;
                auto* nq = &Q;
                if (nr == G) {
                    nr = 0;
                    nc += R;
                    nq = &Q2;
                }
                if (dp[a + 1][nr] > nc) {
                    dp[a + 1][nr] = nc;
                    nq->push_back({nc, {a + 1, nr}});
                }
            }
            if (a != 1 && r + pos[a] - pos[a - 1] <= G) {
                int nr = r + pos[a] - pos[a - 1];
                ll nc = pos[a] - pos[a - 1] + ter.first;
                auto* nq = &Q;
                if (nr == G) {
                    nr = 0;
                    nc += R;
                    nq = &Q2;
                }
                if (dp[a - 1][nr] > nc) {
                    dp[a - 1][nr] = nc;
                    nq->push_back({nc, {a - 1, nr}});
                }
            }
        }
    }
    ll mini = LLONG_MAX;
    bool kk = false;
    for (int i = 0; i < G; i++) {
        if (dp[K][i] != LLONG_MAX) {
            mini = min(mini, dp[K][i] - (i == 0) * R);
            kk = true;
        }
    }
    if (kk)
        printf("%lld", mini);
    else
        printf("-1");
    return 0;
}