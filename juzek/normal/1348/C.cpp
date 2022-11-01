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

char s[1000007];
int jest['z' + 7];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(jest, 0, sizeof(jest));
        int N, K;
        scanf("%d%d", &N, &K);
        scanf(" %s", s);
        sort(s, s + N);
        for (int i = 0; i < N; i++)
            jest[s[i]]++;
        if (K == 1) {
            printf("%s\n", s);
            continue;
        }
        int rozne = 1;
        for (int i = 1; i < N; i++)
            if (s[i] != s[i - 1])
                rozne++;
        if (rozne == 1) {
            int ile = (N + K - 1) / K;
            for (int i = 0; i < ile; i++)
                printf("%c", s[0]);
            printf("\n");
        } else if (rozne == 2) {
            if (jest[s[0]] > K) {
                printf("%c", s[0]);
                for (int i = K; i < N; i++)
                    printf("%c", s[i]);
                printf("\n");
            } else if (jest[s[0]] == K) {
                printf("%c", s[0]);
                for (int i = K; i < N; i += K)
                    printf("%c", s[i]);
                printf("\n");
            } else {
                printf("%c\n", s[N - 1]);
            }
        } else {
            if (jest[s[0]] >= K) {
                printf("%c", s[0]);
                for (int i = K; i < N; i++)
                    printf("%c", s[i]);
                printf("\n");
            } else {
                char maxi = 0;
                for (int i = 0; i < K; i++)
                    maxi = max(maxi, s[i]);
                printf("%c\n", maxi);
            }
        }
    }
    return 0;
}