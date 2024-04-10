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

bool tab[3][1000007];
char s[1000007];

int dp[1000007][8];
bool komp[8][8];

int help[3][3];

bool sprawdz(int x, int y, int n) {
    bitset<3> xx(x);
    bitset<3> yy(y);
    for (int i = 0; i < n; i++)
        help[0][i] = xx[i];
    for (int i = 0; i < n; i++)
        help[1][i] = yy[i];
    for (int i = 0; i < n - 1; i++) {
        int suma = help[0][i] + help[1][i] + help[0][i + 1] + help[1][i + 1];
        if (suma % 2 == 0)
            return false;
    }
    return true;
}

int koszt(int n, int w, int co) {
    bitset<3> xx(co);
    int ret = 0;
    for (int i = 0; i < n; i++)
        ret += xx[i] != tab[i][w];
    return ret;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int buflen = m;
    if (n == 1 || m == 1) {
        printf("0");
        return 0;
    }
    if (n >= 4 && m >= 4) {
        printf("-1");
        return 0;
    }
    int ter = buflen;
    auto czytaj = [&]() {
        if (ter == buflen) {
            scanf(" %s", s);
            ter = 0;
        }
        return s[ter++] - '0';
    };
    if (n < m) {
        for (int i = 0; i < n; i++)
            for (int w = 1; w <= m; w++)
                tab[i][w] = czytaj();
    } else {
        swap(n, m);
        for (int w = 1; w <= m; w++)
            for (int i = 0; i < n; i++)
                tab[i][w] = czytaj();
    }
    int ile = (1 << n);
    for (int i = 0; i < ile; i++)
        for (int w = 0; w < ile; w++)
            komp[i][w] = sprawdz(i, w, n);
    for (int j = 1; j <= m; j++) {
        for (int i = 0; i < ile; i++)
            dp[j][i] = 1337133713;
        for (int w = 0; w < ile; w++) {
            int k = koszt(n, j, w);
            for (int i = 0; i < ile; i++)
                if (komp[i][w])
                    dp[j][w] = min(dp[j][w], dp[j - 1][i] + k);
        }
    }
    int mini = 1337133713;
    for (int i = 0; i < ile; i++)
        mini = min(mini, dp[m][i]);
    printf("%d", mini);
    return 0;
}