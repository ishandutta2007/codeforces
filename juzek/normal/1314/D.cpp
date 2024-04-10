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

int v[87][87];
vector<pair<int, int>> best[87][87];
ll wynik = LLONG_MAX;
int N, K;

bool zajete[80];

void adam(int k, vector<int> &wybrane) {
    if (k == 0) {
        wybrane.push_back(1);
        for (auto it : wybrane)
            zajete[it] = true;
        ll odp = 0;
        bool kk = true;
        for (int i = 1; i < wybrane.size(); i++) {
            int sk = wybrane[i - 1];
            int dk = wybrane[i];
            bool spoczko = false;
            for (auto it : best[sk][dk])
                if (!zajete[it.second]) {
                    odp += it.first;
                    spoczko = true;
                    break;
                }
            if (!spoczko) {
                kk = false;
                break;
            }
        }
        for (auto it : wybrane)
            zajete[it] = false;
        if (kk)
            wynik = min(wynik, odp);
        wybrane.pop_back();
        return;
    }
    for (int i = 1; i <= N; i++) {
        wybrane.push_back(i);
        adam(k - 1, wybrane);
        wybrane.pop_back();
    }
}

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++)
        for (int w = 1; w <= N; w++)
            scanf("%d", &v[i][w]);
    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= N; w++) {
            vector<pair<int, int>> odl;
            for (int z = 1; z <= N; z++)
                if (z != i && z != w)
                    odl.push_back({v[i][z] + v[z][w], z});
            sort(odl.begin(), odl.end());
            while (odl.size() > 6)
                odl.pop_back();
            best[i][w] = odl;
        }
    }
    vector<int> wybrane = {1};
    adam(K / 2 - 1, wybrane);
    printf("%lld", wynik);
    return 0;
}