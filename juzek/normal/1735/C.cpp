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

char s[100007], result[100007];
bool mam_poprz['z' + 7];
bool mam_nast['z' + 7];
char poprz['z' + 7];
char nast['z' + 7];
int mam_nast_counter = 0;

char assign(char c) {
    if (mam_poprz[c])
        return poprz[c];
    char zakaz = c;
    while (mam_nast[zakaz])
        zakaz = nast[zakaz];
    for (int i = 'a'; i <= 'z'; i++) {
        if (!mam_nast[i] && i != c && (i != zakaz || mam_nast_counter == 'z' - 'a')) {
            mam_nast_counter += 1;
            mam_nast[i] = true;
            mam_poprz[c] = true;
            poprz[c] = char(i);
            nast[i] = c;
            break;
        }
    }
    return poprz[c];
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        scanf(" %s", s + 1);
        mam_nast_counter = 0;
        for (int i = 'a'; i <= 'z'; i++) {
            mam_nast[i] = false;
            mam_poprz[i] = false;
        }
        for (int i = 1; i <= n; i++)
            result[i] = assign(s[i]);
        result[n + 1] = 0;
        printf("%s\n", result + 1);
    }
    return 0;
}