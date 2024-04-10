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

    sim, class m mor pair<m, c> r) { ris << "(" << r.first << ", " << r.second << ")"; }

#else
    sim mor const c&){ris;}
#endif
};

#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r...) "[" #r ": " << (r) << "] "
#define range(a, b) "[[" #a ", " #b "): " << range(a, b) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
using pii = pair<int, int>;
using ld = long double;
using ll = long long;

const int MAXN = 400007;
vector<int> liczby[25];
int maski[25];

int main() {
    int N;
    scanf("%d", &N);
    maski[0] = 1;
    for (int i = 1; i < 25; i++)
        maski[i] = maski[i - 1] * 2 + 1;
    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);
        for (int w = 0; w < 25; w++)
            liczby[w].push_back(a & maski[w]);
    }
    int odp = 0;
    for (int i = 0, pot = 1; i < 25; i++, pot *= 2) {
        sort(liczby[i].begin(), liczby[i].end());
        int maxi = maski[i];
        int mini = maski[i] / 2;
        int maxi_maxi = maxi * 2 - mini;
        int maxi_pos = N - 1;
        int mini_pos = N - 1;
        int maxi_maxi_pos = N - 1;
        long long ile = 0;
        for (int w = 0; w < N; w++) {
            while (maxi_pos > w && liczby[i][w] + liczby[i][maxi_pos] > maxi)
                maxi_pos--;
            while (maxi_maxi_pos > w && liczby[i][w] + liczby[i][maxi_maxi_pos] > maxi_maxi)
                maxi_maxi_pos--;
            while (mini_pos > w && liczby[i][w] + liczby[i][mini_pos] > mini)
                mini_pos--;
            maxi_maxi_pos = max(maxi_maxi_pos, w);
            mini_pos = max(mini_pos, w);
            if (maxi_pos >= mini_pos)
                ile += maxi_pos - mini_pos;
            ile += N - maxi_maxi_pos - 1;
        }
        if (ile % 2 == 1)
            odp += pot;
    }
    printf("%d", odp);
    return 0;
}