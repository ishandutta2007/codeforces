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

const int MAXN = 500007;
vector<int> v[MAXN];
int kolor[MAXN];
long long war[MAXN];

long long nwd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, M;
        scanf("%d%d", &N, &M);
        int licznik = 1;
        for (int i = 1; i <= N; i++)
            kolor[i] = 1;
        for (int i = 1; i <= N; i++)
            scanf("%lld", &war[i]);
        for (int i = 1; i <= M; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            v[a].push_back(b);
        }
        for (int i = 1; i <= N; i++) {
            map<int, vector<int>> grupki;
            for (auto it : v[i])
                grupki[kolor[it]].push_back(it);
            for (auto &gr : grupki) {
                licznik++;
                for (auto it : gr.second)
                    kolor[it] = licznik;
            }
        }
        map<int, long long> grupki;
        for (int i = 1; i <= N; i++)
            if (kolor[i] != 1)
                grupki[kolor[i]] += war[i];
        long long wyn = 0;
        for (auto it : grupki)
            wyn = nwd(wyn, it.second);
        printf("%lld\n", wyn);
        for (int i = 1; i <= N; i++)
            v[i].clear();
    }
    return 0;
}