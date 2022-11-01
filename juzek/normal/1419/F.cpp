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

const int maxn = 1007;
pii pos[maxn];
int n;
int rep[maxn];

int find(int a) {
    if (rep[a] == a)
        return a;
    return rep[a] = find(rep[a]);
}

bool ok(pii a, int b, int t) {
    if (a.first == pos[b].first)
        return abs(a.second - pos[b].second) <= t;
    if (a.second == pos[b].second)
        return abs(a.first - pos[b].first) <= t;
    return false;
}

bool ok(int a, int b, int t) {
    if (pos[a].first == pos[b].first)
        return abs(pos[a].second - pos[b].second) <= t;
    if (pos[a].second == pos[b].second)
        return abs(pos[a].first - pos[b].first) <= t;
    return false;
}

bool sprawdz(int t) {
    for (int i = 1; i <= n; i++)
        rep[i] = i;
    int spojne = n;
    for (int i = 1; i <= n; i++) {
        for (int w = i + 1; w <= n; w++) {
            if (ok(i, w, t) && find(i) != find(w)) {
                rep[find(i)] = find(w);
                spojne--;
            }
        }
    }
    if (spojne == 1)
        return true;
    if (spojne == 2) {
        for (int i = 1; i <= n; i++) {
            for (int w = i + 1; w <= n; w++) {
                if (find(i) != find(w)) {
                    if (pos[i].first == pos[w].first && abs(pos[i].second - pos[w].second) <= 2 * t)
                        return true;
                    if (pos[i].second == pos[w].second && abs(pos[i].first - pos[w].first) <= 2 * t)
                        return true;
                    if (abs(pos[i].first - pos[w].first) <= t && abs(pos[i].second - pos[w].second) <= t)
                        return true;
                }
            }
        }
    }
    if (spojne == 3) {
        vector<pii> odc;
        for (int i = 1; i <= n; i++)
            for (int w = i + 1; w <= n; w++)
                if (find(i) != find(w) && ok(i, w, INT_MAX))
                    odc.emplace_back(i, w);
        for (int i = 1; i <= n; i++) {
            for (auto it : odc) {
                if (find(i) != find(it.first) && find(i) != find(it.second)) {
                    bool ok1 = abs(pos[i].first - pos[it.first].first) <= t &&
                               abs(pos[i].second - pos[it.first].second) <= t;
                    bool ok2 = abs(pos[i].first - pos[it.second].first) <= t &&
                               abs(pos[i].second - pos[it.second].second) <= t;
                    if (ok1 && ok2)
                        return true;
                }
            }
        }
    }
    if (spojne == 4) {
        vector<pii> odc1, odc2;
        for (int i = 1; i <= n; i++)
            for (int w = i + 1; w <= n; w++) {
                if (find(i) != find(w) && pos[i].first == pos[w].first)
                    odc1.emplace_back(i, w);
                if (find(i) != find(w) && pos[i].second == pos[w].second)
                    odc2.emplace_back(i, w);
            }
        for (auto ss : odc1) {
            for (auto ff : odc2) {
                set<int> test = {find(ss.first), find(ss.second), find(ff.first), find(ff.second)};
                if (test.size() != 4)
                    continue;
                pii prz = {pos[ss.first].first, pos[ff.first].second};
                if (ok(prz, ss.first, t) && ok(prz, ss.second, t) && ok(prz, ff.first, t) && ok(prz, ff.second, t))
                    return true;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d", &n);
    std::vector<pii> v;
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        pos[i] = {x, y};
    }
    ll pocz = 0, kon = 2000000007;
    while (pocz != kon - 1) {
        ll sr = (pocz + kon) / 2;
        if (sprawdz(sr))
            kon = sr;
        else
            pocz = sr;
    }
    if (kon == 2000000007) {
        printf("-1\n");
        return 0;
    }
    printf("%lld\n", kon);
    return 0;
}