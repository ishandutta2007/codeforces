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

const int maxn = 100007;
std::vector<int> v[maxn];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int minK = 0, maxK = n;
        int starting = -1;
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            v[x].push_back(i);
            if (x == 0 || x == n + 1)
                starting = x;
            if (i < x) {
                minK = max(minK, i);
                maxK = min(maxK, x - 1);
            } else {
                maxK = min(maxK, i - 1);
                minK = max(minK, x);
            }
        }
        int now = starting;
        vector<int> result;
        while (now != -1) {
            int next = -1;
            for (auto it: v[now])
                if (!v[it].empty())
                    next = it;
                else
                    result.push_back(it);
            if (next != -1)
                result.push_back(next);
            now = next;
        }
        printf("%d\n", minK);
        for (auto it : result)
            printf("%d ", it);
        printf("\n");
        for (int i = 0; i <= n + 1; i++)
            v[i].clear();
    }
    return 0;
}