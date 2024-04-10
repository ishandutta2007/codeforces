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

char s[100007];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        int n = strlen(s);
        bool a = false, b = false;
        for (int i = 0; i < n; i++) {
            a |= s[i] == '0';
            b |= s[i] == '1';
        }
        if (a && b) {
            printf("%c", s[0]);
            for (int i = 1; i < n; i++) {
                if (s[i] == s[i - 1]) {
                    if (s[i] == '0')
                        printf("1");
                    else
                        printf("0");
                }
                printf("%c", s[i]);
            }
            printf("\n");
        } else {
            printf("%s\n", s);
        }
    }
    return 0;
}