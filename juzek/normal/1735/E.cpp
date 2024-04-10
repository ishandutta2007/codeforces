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

    sim mor const c &) { ris; }

#endif
};

#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r) "[" #r ": " << (r) << "] "
#define range(a, b) "[[" #a ", " #b "): " << range(a, b) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
using pii = pair<int, int>;
using ld = long double;
using ll = long long;

const int maxn = 2007;
int tab[maxn];
int connections[maxn];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= 2 * n; i++)
            scanf("%d", &tab[i]);
        for (int i = 1; i <= 2 * n; i++)
            connections[i] = -1;
        vector<pair<int, pii>> v;
        for (int i = 1; i <= n; i++) {
            for (int w = n + 1; w <= 2 * n; w++) {
                int a = i, b = w;
                if (tab[a] >= tab[b]) {
                    int d1 = tab[a] - tab[b];
                    v.push_back({d1, {a, b}});
                    int d2 = tab[a] + tab[b];
                    v.push_back({d2, {a, b}});
                }
                swap(a, b);
                if (tab[a] >= tab[b]) {
                    int d1 = tab[a] - tab[b];
                    v.push_back({d1, {a, b}});
                    int d2 = tab[a] + tab[b];
                    v.push_back({d2, {a, b}});
                }
            }
        }
        sort(v.begin(), v.end(), [](pair<int, pii> a, pair<int, pii> b) {
            return pii(a.first, -tab[a.second.first]) < pii(b.first, -tab[b.second.first]);
        });
        debug << range(v.begin(), v.end());
        bool yes = false;
        for (int i = 0; i < v.size(); i++) {
            if (i != 0 && v[i].first == v[i - 1].first)
                continue;
            int d = v[i].first;
            int ile = 0;
            for (int w = i; w < v.size() && v[w].first == d; w++) {
                int a = v[w].second.first, b = v[w].second.second;
                if (connections[a] == -1 && connections[b] == -1) {
                    connections[a] = b;
                    connections[b] = a;
                    ile++;
                }
            }
            if (ile == n) {
                yes = true;
                printf("YES\n");
                int p1 = 0, p2 = d;
                std::vector<int> results;
                for (int w = 1; w <= n; w++) {
                    int a = w, b = connections[w];
                    if (tab[b] - tab[a] == d) {
                        results.push_back(-tab[a]);
                    } else {
                        results.push_back(tab[a]);
                    }
                }
                sort(results.begin(), results.end());
                int mini = min(results[0], 0);
                for (auto x: results) {
                    printf("%d ", x - mini);
                }
                printf("\n");
                printf("%d %d\n", p1 - mini, p2 - mini);
            }
            for (int w = i; w < v.size() && v[w].first == d; w++) {
                int a = v[w].second.first, b = v[w].second.second;
                connections[a] = -1;
                connections[b] = -1;
            }
            if (yes)
                break;
        }
        if (!yes)
            printf("NO\n");
    }
    return 0;
}