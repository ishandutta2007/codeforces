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

int kolor[5007];
int ktory[5007];
int bylo[5007];
vector<int> krowy[5007];
vector<int> pozycje[5007];

int szukaj(vector<int> &krowy, vector<int> &pozycje, int limit, bool odw) {
    int pocz = -1, kon = krowy.size();
    while (pocz != kon - 1) {
        int sr = (pocz + kon) / 2;
        int dk = odw ? pozycje[pozycje.size() - krowy[sr]] : pozycje[krowy[sr] - 1];
        bool spoko = !odw ? dk < limit : limit < dk;
        if (spoko)
            pocz = sr;
        else
            kon = sr;
    }
    return pocz + 1;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &kolor[i]);
        pozycje[kolor[i]].push_back(i);
        bylo[kolor[i]]++;
        ktory[i] = bylo[kolor[i]];
    }
    for (int i = 1; i <= M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (pozycje[a].size() >= b)
            krowy[a].push_back(b);
    }
    const int mod = 1000000007;
    for (int i = 1; i <= N; i++)
        sort(krowy[i].begin(), krowy[i].end());
    int odpIle = 0;
    ll odp = 1;
    for (int i = 0; i <= N; i++) {
        int pojdzie = 0;
        ll sposoby = 1;
        int elo = 0;
        if (binary_search(krowy[kolor[i]].begin(), krowy[kolor[i]].end(), ktory[i]))
            elo = kolor[i];
        if (elo == 0 && i != 0)
            continue;
        debug << imie(i) imie(elo);
        for (int w = 1; w <= N; w++) {
            int poLewej = szukaj(krowy[w], pozycje[w], i, false);
            int poPrawej = szukaj(krowy[w], pozycje[w], i, true);
            if (w == elo) {
                poLewej = 0;
                pojdzie += 1;
                int ziomo = ktory[i];
                if (i < pozycje[w][pozycje[w].size() - ziomo])
                    poPrawej--;
            }
            if (krowy[w].size() != 0)
                debug << imie(w) imie(poLewej) imie(poPrawej);
            if (poLewej == 0 && poPrawej == 0) {
                continue;
            } else if (poLewej == 0 || poPrawej == 0 || (poLewej == poPrawej && poLewej == 1)) {
                pojdzie += 1;
                if (poLewej == poPrawej && poLewej == 1) {
                    sposoby *= 2;
                    sposoby %= mod;
                } else {
                    sposoby *= max(poLewej, poPrawej);
                    sposoby %= mod;
                }
            } else {
                pojdzie += 2;
                int mini = min(poLewej, poPrawej);
                int maxi = max(poLewej, poPrawej);
                ll dod = ll(mini) * (mini - 1);
                dod %= mod;
                dod += ll(maxi - mini) * mini;
                dod %= mod;
                sposoby *= dod;
                sposoby %= mod;
            }
        }
        debug << imie(pojdzie) imie(sposoby);
        if (odpIle < pojdzie) {
            odpIle = pojdzie;
            odp = 0;
        }
        if (odpIle == pojdzie) {
            odp += sposoby;
            odp %= mod;
        }
    }
    if (odpIle == 0)
        odp = 1;
    printf("%d %lld", odpIle, odp);
    return 0;
}