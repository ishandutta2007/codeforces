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

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    scanf("%s", s + 1);
    int ile = 0;
    int ziomy = 0;
    vector<int> L;
    L.push_back(0);
    for (int i = 1; i <= N; i++)
        if (s[i] == 'L') {
            ile += i - 1 - ziomy;
            L.push_back(i);
            ziomy++;
        }
    if (ile < K) {
        printf("-1");
        return 0;
    }
    vector<vector<int>> op;
    vector<int> sensowne;
    for (int i = 1; i < L.size(); i++)
        if (L[i - 1] != L[i] - 1)
            sensowne.push_back(i);
    while (K != 0) {
        K--;
        op.push_back({});
        vector<int> noweSensowne;
        while (!sensowne.empty()) {
            int ter = sensowne.back();
            sensowne.pop_back();
            int pos = L[ter];
            swap(s[pos], s[pos - 1]);
            if (ter + 1 < L.size() && L[ter + 1] == pos + 1)
                noweSensowne.push_back(ter + 1);
            if (pos - 2 > 0 && s[pos - 2] == 'R')
                noweSensowne.push_back(ter);
            op.back().push_back(pos - 1);
            L[ter]--;
            ile--;
            if (ile == K)
                break;
        }
        while (!noweSensowne.empty()) {
            int a = noweSensowne.back();
            noweSensowne.pop_back();
            sensowne.push_back(a);
        }
        reverse(op.back().begin(), op.back().end());
    }
    if (ile != 0)
        printf("-1");
    else {
        for (auto &it : op) {
            printf("%d ", (int) it.size());
            for (auto it2 : it)
                printf("%d ", it2);
            printf("\n");
        }
    }
    return 0;
}