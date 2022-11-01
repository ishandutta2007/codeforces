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


int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> types;
        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);
            types.push_back(a);
        }
        vector<int> zeros, ones;
        ll damage = 0;
        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);
            damage += a * 2;
            if (types[i] == 0)
                zeros.push_back(a);
            else
                ones.push_back(a);
        }
        sort(zeros.begin(), zeros.end());
        sort(ones.begin(), ones.end());
        if (zeros.size() < ones.size())
            swap(zeros, ones);
        int bad = zeros.size() - ones.size();
        for (int i = 0; i < bad; i++)
            damage -= zeros[i];
        if (bad == 0) {
            damage -= min(zeros[0], ones[0]);
        }
        printf("%lld\n", damage);
    }
    return 0;
}