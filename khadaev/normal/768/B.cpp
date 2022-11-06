#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
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

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

ll len(ll n) {
    if (n <= 1) return 1;
    return 2 * len(n / 2) + 1;
}

ll solve(ll n, ll l, ll r) {
    ll x = len(n);
    l = max(l, 0ll);
    r = min(r, x - 1);
    if (l > r) return 0;
    if (n <= 1) return n;
    ll ans = solve(n / 2, l, r);
    if (l <= x / 2 && x / 2 <= r) ans += n % 2;
    ans += solve(n / 2, l - x / 2 - 1, r - x / 2 - 1);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, l, r;
    cin >> n >> l >> r;
    --l, --r;
    cout << solve(n, l, r) << '\n';
}