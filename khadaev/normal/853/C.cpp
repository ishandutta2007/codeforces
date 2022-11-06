#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

template<typename T>
inline void setmax(T& a, T b) {
    if (a < b) a = b;
}

template<typename T>
inline void setmin(T& a, T b) {
    if (a > b) a = b;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

ll c2(int x) {
    return 1ll * x * (x - 1) / 2;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    vector<int> p(n);
    forn(i, 0, n) {
        scanf("%d", &p[i]);
        --p[i];
    }
    vector<int> l(q), r(q), u(q), d(q);
    forn(i, 0, q) {
        scanf("%d %d %d %d", &l[i], &d[i], &r[i], &u[i]);
        --l[i], --d[i], --r[i], --u[i];
    }
    vector<ll> ans(q, 0);

    forn(i, 0, q) {
        ans[i] += c2(l[i]);
        ans[i] += c2(n - 1 - r[i]);
        ans[i] += c2(d[i]);
        ans[i] += c2(n - 1 - u[i]);
    }
    //forn(i, 0, q) printf("%lld ", c2(n) - ans[i]);
    //printf("\n");

    vector<vector<pair<int, int>>> q1(n), q2(n);
    forn(i, 0, q) {
        q1[l[i]].eb(d[i], i);
        q2[l[i]].eb(u[i], i);
    }
    ordered_set<int> s1;
    forn(i, 0, n) {
        for (auto x : q1[i]) {
            int cnt = s1.order_of_key(x.fs);
            ans[x.sn] -= c2(cnt);
        }
        for (auto x : q2[i]) {
            int cnt = (int)s1.size() - s1.order_of_key(x.fs + 1);
            ans[x.sn] -= c2(cnt);
        }
        s1.insert(p[i]);
    }
    vector<vector<pair<int, int>>> q3(n), q4(n);
    forn(i, 0, q) {
        q3[r[i]].eb(d[i], i);
        q4[r[i]].eb(u[i], i);
    }
    ordered_set<int> s2;
    ford(i, 0, n) {
        for (auto x : q3[i]) {
            int cnt = s2.order_of_key(x.fs);
            ans[x.sn] -= c2(cnt);
        }
        for (auto x : q4[i]) {
            int cnt = (int)s2.size() - s2.order_of_key(x.fs + 1);
            ans[x.sn] -= c2(cnt);
        }
        s2.insert(p[i]);
    }
    forn(i, 0, q) printf("%lld ", c2(n) - ans[i]);
}