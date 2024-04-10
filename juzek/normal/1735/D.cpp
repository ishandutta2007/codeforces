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

set<string> all_set;
vector<string> all_vec;
int ile[1007];

string get_cand(string const &a, string const &b) {
    int n = a.size();
    string res = "";
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i])
            res += a[i];
        else {
            for (char x = '0'; x <= '2'; x++)
                if (x != a[i] && x != b[i])
                    res += x;
        }
    }
    return res;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        string s = "";
        for (int w = 0; w < k; w++) {
            int x;
            scanf("%d", &x);
            s += char('0' + x);
        }
        all_set.insert(s);
        all_vec.push_back(s);
    }
    for (int i = 0; i < n; i++) {
        for (int w = i + 1; w < n; w++) {
            string cand = get_cand(all_vec[i], all_vec[w]);
            if (all_set.count(cand) > 0) {
                ile[i] += 1;
                ile[w] += 1;
            }
        }
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
        ll x = ile[i] / 2;
        assert(ile[i] % 2 == 0);
        res += x * (x - 1) / 2;
    }
    printf("%lld\n", res);
    return 0;
}