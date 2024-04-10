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

const char* ziomki[10] = {"1110111", "0010010", "1011101", "1011011", "0111010",
                     "1101011", "1101111", "1010010", "1111111", "1111011"};

char s[2007];
int koszty[2007][2007];
bool dp[2007][2007];

int koszt(const char* a, const char* b) {
    int ret = 0;
    for (int i = 0; i < 7; i++)
        if (a[i] == '0' && b[i] == '1')
            ret++;
        else if (b[i] == '0' && a[i] == '1')
            return 13371337;
    return ret;
}

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf(" %s", s);
        for (int w = 0; w <= 9; w++)
            koszty[i][w] = koszt(s, ziomki[w]);
    }
    dp[N + 1][0] = true;
    for (int i = N; i >= 1; i--)
        for (int ile = 0; ile <= K; ile++)
            for (int w = 0; w <= 9; w++)
                if (ile - koszty[i][w] >= 0)
                    dp[i][ile] |= dp[i + 1][ile - koszty[i][w]];
    if (!dp[1][K]) {
        printf("-1");
        return 0;
    }
    for (int i = 1; i <= N; i++) {
        for (int w = 9; w >= 0; w--) {
            if (K - koszty[i][w] >= 0 && dp[i + 1][K - koszty[i][w]]) {
                printf("%d", w);
                K -= koszty[i][w];
                break;
            }
        }
    }
    return 0;
}