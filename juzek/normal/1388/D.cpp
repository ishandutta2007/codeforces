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

const int MAXN = 200007;

long long a[MAXN];
int b[MAXN];
bool odw[MAXN];
vector<int> asdf[MAXN], nowy[MAXN];
int st[MAXN];

void dfs(int x, int oj) {
    if (odw[x])
        return;
    odw[x] = true;
    for (auto it : asdf[x]) {
        if (it != oj) {
            dfs(it, x);
            if (a[it] > 0) {
                a[x] += a[it];
                nowy[it].push_back(x);
                st[x]++;
            } else {
                nowy[x].push_back(it);
                st[it]++;
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &b[i]);
        asdf[b[i]].push_back(i);
    }
    long long wyn = 0;
    for (int i = 1; i <= N; i++) {
        dfs(i, -1);
        wyn += a[i];
    }
    printf("%lld\n", wyn);
    vector<int> v;
    for (int i = 1; i <= N; i++)
        if (st[i] == 0)
            v.push_back(i);
    while (!v.empty()) {
        int x = v.back();
        printf("%d ", x);
        v.pop_back();
        for (auto it : nowy[x])
            if ((--st[it]) == 0)
                v.push_back(it);
    }
    return 0;
}