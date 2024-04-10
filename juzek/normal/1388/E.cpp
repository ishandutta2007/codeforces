#ifndef LOCAL
#pragma GCC optimize("O3")
#endif

#include "bits/stdc++.h"
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define st first
#define nd second

using namespace std;

//~ #include <ext/pb_ds/assoc_container.hpp>
//~ #include <ext/pb_ds/tree_policy.hpp>
//~ using namespace __gnu_pbds;
//~ template <typename T>
//~ using ordered_set =
//~ tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim>
struct rge {
    c b, e;
};

sim> rge<c> range(c i, c j) { return rge<c>{i, j}; }

sim> auto dud(c *x) -> decltype(cerr << *x, 0);

sim> char dud(...);

struct debug {
#ifdef LOCAL

    ~debug() { cerr << endl; }

    eni(!=) cerr << boolalpha << i;
        ris; }

    eni(==) ris << range(begin(i), end(i)); }

    sim, class b dor(pair<b, c> d) {
        ris << "(" << d.first << ", " << d.second << ")";
    }

    sim dor(rge<c> d) {
        *this << "[";
        for (auto it = d.b; it != d.e; ++it)
            *this << ", " + 2 * (it == d.b) << *it;
        ris << "]";
    }

#else
    sim dor(const c&) { ris; }
#endif
};

debug debug;

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#ifdef LOCAL
mt19937 rng(unsigned(69));
#else
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif
#define rand rng

using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
using vi=vector<int>;
using vll=vector<ll>;

const int MAXN = 2007;

int x1[MAXN], x2[MAXN], y[MAXN];

double oblicz(int x, int y, double delta) {
    return y * delta + x;
}

int N;

pii znajdz(double delta) {
    int pierw = 0, ost = 0;
    for (int i = 0; i < N; i++) {
        if (oblicz(x1[pierw], y[pierw], delta) > oblicz(x1[i], y[i], delta))
            pierw = i;
        if (oblicz(x2[ost], y[ost], delta) < oblicz(x2[i], y[i], delta))
            ost = i;
    }
    return {pierw, ost};
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d%d%d", x1 + i, x2 + i, y + i);
    vector<pair<double, pii>> v;
    vector<pair<double, double>> zle;
    for (int i = 0; i < N; i++) {
        for (int w = i + 1; w < N; w++) {
            if (y[i] == y[w])
                continue;
            double wpoi = double(x1[w] - x2[i]) / (y[i] - y[w]);
            double ipow = double(x1[i] - x2[w]) / (y[w] - y[i]);
            v.push_back({wpoi, {i, w}});
            v.push_back({ipow, {w, i}});
            debug << imie(i) imie(w) imie(ipow) imie(wpoi) << "\n";
            zle.push_back({min(wpoi, ipow), max(wpoi, ipow)});
        }
    }
    sort(zle.begin(), zle.end());
    vector<pair<double, double>> zle_zlaczone;
    double koniec = -INFINITY;
    for (auto it : zle) {
        if (it.first >= koniec)
            zle_zlaczone.push_back(it);
        else
            zle_zlaczone.back().second = max(zle_zlaczone.back().second, it.second);
        koniec = max(koniec, it.second);
    }
    debug << imie(zle) << "\n";
    debug << imie(zle_zlaczone) << "\n";
    v.push_back({0, {-1, -1}});
    sort(v.begin(), v.end());
    debug << imie(v) << "\n";
    pii kto = znajdz(v[0].first);
    double best = INFINITY;
    auto ter = zle_zlaczone.begin();
    for (int i = 0; i < (int) v.size(); i++) {
        auto it = v[i];
        if (it.second.second == kto.first)
            kto.first = it.second.first;
        if (it.second.first == kto.second)
            kto.second = it.second.second;
//        debug << imie(kto) imie(znajdz(v[i].first)) imie(v[i].first) << "\n";
        while (ter != zle_zlaczone.end() && ter->second <= it.first)
            ter++;
        if (ter == zle_zlaczone.end() || ter->first >= it.first)
            if (i == (int) v.size() - 1 || v[i].first != v[i + 1].first)
                best = min(best, oblicz(x2[kto.second], y[kto.second], v[i].first) - oblicz(x1[kto.first], y[kto.first], v[i].first));
    }
    printf("%.7lf", best);
    return 0;
}