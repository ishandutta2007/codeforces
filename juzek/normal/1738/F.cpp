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

const int maxn = 1007;
int repr[maxn];
bool used[maxn];

int finder(int a) {
    if (repr[a] == a)
        return a;
    return (repr[a] = finder(repr[a]));
}

void unioner(int a, int b) {
    a = finder(a), b = finder(b);
    repr[a] = b;
}

int pytaj(int a) {
    printf("? %d\n", a);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    return x;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<pii> degrees;
        for (int i = 1; i <= n; i++) {
            repr[i] = i;
            used[i] = false;
        }
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            degrees.emplace_back(x, i);
        }
        sort(degrees.begin(), degrees.end());
        reverse(degrees.begin(), degrees.end());
        for (auto it: degrees) {
            int a = it.second;
            if (used[a])
                continue;
            used[a] = true;
            for (int i = 1; i <= it.first; i++) {
                int x = pytaj(a);
                unioner(a, x);
                if (used[x])
                    break;
                used[x] = true;
            }
        }
        printf("! ");
        for (int i = 1; i <= n; i++) {
            printf("%d ", finder(i));
        }
        printf("\n");
        fflush(stdout);
    }
    return 0;
}