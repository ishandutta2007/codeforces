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

const int maxn = 500007;
const int z = 1024 * 512;

std::deque<int> pozycje[maxn];
pii drzewo[z * 2 + 7];
int sp[z * 2 + 7];

void spychaj(int v) {
    sp[v * 2] += sp[v];
    drzewo[v * 2].first += sp[v];
    sp[v * 2 + 1] += sp[v];
    drzewo[v * 2 + 1].first += sp[v];
    sp[v] = 0;
}

void dodaj(int war, int ll, int rr, int v = 1, int l = 1, int r = z) {
    if (r < ll || rr < l)
        return;
    if (ll <= l && r <= rr) {
        sp[v] += war;
        drzewo[v].first += war;
        return;
    }
    spychaj(v);
    int sr = (l + r) / 2;
    dodaj(war, ll, rr, v * 2, l, sr);
    dodaj(war, ll, rr, v * 2 + 1, sr + 1, r);
    drzewo[v].first = min(drzewo[v * 2].first, drzewo[v * 2 + 1].first);
    drzewo[v].second = 0;
    drzewo[v].second += (drzewo[v].first == drzewo[v * 2].first) ? drzewo[v * 2].second : 0;
    drzewo[v].second += (drzewo[v].first == drzewo[v * 2 + 1].first) ? drzewo[v * 2 + 1].second : 0;
}

void dodajD(int war, int ll, int rr) {
    debug << imie(ll) imie(rr) imie(war);
    dodaj(war, ll, rr);
}

int czytaj(int ll, int rr, int v = 1, int l = 1, int r = z) {
    if (r < ll || rr < l)
        return 0;
    if (ll <= l && r <= rr) {
        if (drzewo[v].first == 0)
            return drzewo[v].second;
        else
            return 0;
    }
    spychaj(v);
    int sr = (l + r) / 2;
    return czytaj(ll, rr, v * 2, l, sr) + czytaj(ll, rr, v * 2 + 1, sr + 1, r);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 2 * z - 1; i >= 1; i--) {
        if (i >= z) drzewo[i].second = 1;
        else drzewo[i].second = drzewo[i * 2].second + drzewo[i * 2 + 1].second;
    }
    ll wyn = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        pozycje[a].push_back(i);
        if (pozycje[a].size() == 5) {
            dodajD(-1, 1, pozycje[a][0]);
            dodajD(-1, pozycje[a][1] + 1, pozycje[a][3]);
            pozycje[a].pop_front();
            dodajD(1, 1, pozycje[a][0]);
            dodajD(1, pozycje[a][1] + 1, pozycje[a][3]);
        } else if (pozycje[a].size() == 4) {
            dodajD(-1, pozycje[a][0] + 1, pozycje[a][2]);
            dodajD(1, 1, pozycje[a][0]);
            dodajD(1, pozycje[a][1] + 1, pozycje[a][3]);
        } else if (pozycje[a].size() == 3) {
            dodajD(-1, 1, pozycje[a][1]);
            dodajD(1, pozycje[a][0] + 1, pozycje[a][2]);
        } else if (pozycje[a].size() == 2) {
            dodajD(1, pozycje[a][0] + 1, pozycje[a][1]);
        } else {
            dodajD(1, 1, pozycje[a][0]);
        }
        int dod = czytaj(1, i);
        debug << imie(dod);
        wyn += dod;
    }
    printf("%lld", wyn);
    return 0;
}