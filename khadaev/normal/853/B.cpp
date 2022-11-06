#include <bits/stdc++.h>
using namespace std;

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

const int N = 1e6 + 10;
vector<pair<int, int>> from[N], to[N];
ll before[N], after[N];

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    while (m--) {
        int d, f, t, c;
        scanf("%d %d %d %d", &d, &f, &t, &c);
        if (f == 0) from[d].eb(t - 1, c);
        else to[d].eb(f - 1, c);
    }
    vector<int> costs(n, -1);
    ll sum = 0;
    int fails = n;
    forn(i, 0, N) {
        for (auto p : to[i]) {
            if (costs[p.fs] == -1) {
                --fails;
                costs[p.fs] = p.sn;
                sum += p.sn;
            } else {
                sum -= costs[p.fs];
                setmin(costs[p.fs], p.sn);
                sum += costs[p.fs];
            }
        }
        if (fails == 0) before[i] = sum;
        else before[i] = -1;
    }
    costs = vector<int>(n, -1);
    sum = 0;
    fails = n;
    ford(i, 0, N) {
        for (auto p : from[i]) {
            if (costs[p.fs] == -1) {
                --fails;
                costs[p.fs] = p.sn;
                sum += p.sn;
            } else {
                sum -= costs[p.fs];
                setmin(costs[p.fs], p.sn);
                sum += costs[p.fs];
            }
        }
        if (fails == 0) after[i] = sum;
        else after[i] = -1;
    }
    ll ans = LINF;
    forn(i, 0, N) {
        if (i + k + 1 == N) break;
        if (before[i] != -1 && after[i + k + 1] != -1)
            setmin(ans, before[i] + after[i + k + 1]);
    }
    printf("%lld\n", ans == LINF ? -1ll : ans);
}