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
int cnt[2 * N];
ll prefsum[2 * N];
int prefcnt[2 * N];
char prime[N];

int main() {
    int n;
    scanf("%d", &n);
    ll x, y;
    scanf("%lld %lld", &x, &y);
    forn(i, 0, n) {
        int q;
        scanf("%d", &q);
        ++cnt[q];
    }
    forn(i, 0, N) prime[i] = 1;
    forn(i, 2, N) if (prime[i]) {
        for (int j = 2 * i; j < N; j += i) prime[j] = 0;
    }
    forn(i, 1, 2 * N) prefcnt[i] = prefcnt[i - 1] + cnt[i];
    forn(i, 1, 2 * N) prefsum[i] = prefsum[i - 1] + (ll)i * cnt[i];
    ll best = LINF;
    ll max_add = x / y;
    forn(p, 2, N) if (prime[p]) {
        ll cur = 0;
        for (int r = 1; p * (r - 1) < N; ++r) {
            ll pt = p > max_add ? p * r - max_add - 1 : p * (r - 1);
            ll to_add = prefcnt[p * r] - prefcnt[pt];
            ll to_rem = prefcnt[pt] - prefcnt[p * (r - 1)];
            ll sum_to_add = prefsum[p * r] - prefsum[pt];
            ll to_y = p * r * to_add - sum_to_add;
            cur += to_y * y + to_rem * x;
        }
        setmin(best, cur);
    }
    printf("%lld\n", best);
}