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

vector<int> v[5007];
int poprz_[3][5007], odl_[3][5007];
bool odw[5007];

void bfs(int a, int* poprz, int* odl) {
    memset(odw, 0, sizeof(odw));
    odw[a] = true;
    poprz[a] = a;
    odl[a] = 0;
    queue<int> Q;
    Q.push(a);
    while (!Q.empty()) {
        a = Q.front();
        Q.pop();
        for (auto it : v[a]) {
            if (!odw[it]) {
                odw[it] = true;
                odl[it] = odl[a] + 1;
                poprz[it] = a;
                Q.push(it);
            }
        }
    }
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ta = 1, tb = 1, tc = 1;
    printf("%d %d %d\n", ta, tb, tc);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    for (int i = 1; i < N; i++) {
        vector<int> sas = v[x];
        while (sas.size() < 3)
            sas.push_back(sas[0]);
        vector<int> perm;
        for (int w = 0; w < 3; w++)
            perm.push_back(w);
        bfs(ta, poprz_[0], odl_[0]);
        bfs(tb, poprz_[1], odl_[1]);
        bfs(tc, poprz_[2], odl_[2]);
        vector<int> minPerm;
        int minWyn = 1337133713;
        do {
            int terWyn = 0;
            for (int w = 0; w < 3; w++)
                terWyn += odl_[w][sas[perm[w]]];
            if (terWyn < minWyn) {
                minWyn = terWyn;
                minPerm = perm;
            }
        } while (next_permutation(perm.begin(), perm.end()));
        auto znajdz = [](int ch, int x, int a, int* poprz) {
            if (x == a)
                return ch;
            while (poprz[x] != a)
                x = poprz[x];
            return x;
        };
        ta = znajdz(x, sas[minPerm[0]], ta, poprz_[0]);
        tb = znajdz(x, sas[minPerm[1]], tb, poprz_[1]);
        tc = znajdz(x, sas[minPerm[2]], tc, poprz_[2]);
        printf("%d %d %d\n", ta, tb, tc);
        if (ta == x || tb == x || tc == x)
            break;
        fflush(stdout);
        scanf("%d", &x);
        if (ta == x || tb == x || tc == x)
            break;
    }
    return 0;
}