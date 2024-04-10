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
set<int> spoko;
int odl1[1000007];
int odlN[1000007];

bool odw[1000007];

void bfs(int a, int *odl) {
    queue<int> Q;
    memset(odw, 0, sizeof(odw));
    Q.push(a);
    odw[a] = true;
    memset(odl, 107, sizeof(int) * 1000005);
    odl[a] = 0;
    while (!Q.empty()) {
        a = Q.front();
        Q.pop();
        for (auto it : v[a]) {
            if (!odw[it]) {
                odw[it] = true;
                odl[it] = odl[a] + 1;
                Q.push(it);
            }
        }
    }
}

int main() {
    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= K; i++) {
        int a;
        scanf("%d", &a);
        spoko.insert(a);
    }
    for (int i = 1; i <= M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(1, odl1);
    bfs(N, odlN);
    vector<pii> ziomki;
    for (auto it : spoko)
        ziomki.push_back({odl1[it] - odlN[it], it});
    sort(ziomki.begin(), ziomki.end());
    int maxiN = -1;
    int maxi = 0;
    for (int i = 0; i < ziomki.size(); i++) {
        if (maxiN != -1)
            maxi = max(maxi, odlN[ziomki[i].second] + maxiN + 1);
        maxiN = max(maxiN, odl1[ziomki[i].second]);
    }
    printf("%d", min(maxi, odl1[N]));
    return 0;
}