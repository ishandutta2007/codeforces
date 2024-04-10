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

const int maxn = 500007;

vector<int> v[maxn];
int maxgl;
int oj[maxn];
bool odw[maxn];
vector<int> ziomki[maxn];

void dfs(int a, int gl = 1) {
    odw[a] = true;
    maxgl = max(maxgl, gl);
    ziomki[gl].push_back(a);
    for (auto it : v[a]) {
        if (!odw[it]) {
            oj[it] = a;
            dfs(it, gl + 1);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        maxgl = 0;
        dfs(1);
        if (maxgl >= (n + 1) / 2) {
            printf("PATH\n");
            printf("%d\n", maxgl);
            int a = ziomki[maxgl].back();
            while (a != 0) {
                printf("%d ", a);
                a = oj[a];
            }
            printf("\n");
        } else {
            printf("PAIRING\n");
            vector<pair<int, int>> pary;
            for (int i = 1; i <= n; i++)
                for (int w = 0; w < ziomki[i].size() - (ziomki[i].size() % 2); w += 2)
                    pary.push_back({ziomki[i][w], ziomki[i][w + 1]});
            printf("%d\n", (int) pary.size());
            for (auto it : pary)
                printf("%d %d\n", it.first, it.second);
        }
        for (int i = 1; i <= n; i++) {
            v[i].clear();
            odw[i] = false;
            ziomki[i].clear();
        }
    }
    return 0;
}