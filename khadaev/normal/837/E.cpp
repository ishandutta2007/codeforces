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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b;
    cin >> a >> b;
    vector<ll> divs;
    for (ll i = 1; i * i <= a; ++i) {
        divs.eb(i);
        if (i * i < a) divs.eb(a / i);
    }
    sort(all(divs));
    ll ans = 0;
    ll d = __gcd(a, b);
    while (b) {
        //cerr << d << '\n';
        ll nxt = 0;
        for (ll x : divs) {
            if (x % d) continue;
            ll res = b % x;
            if (res == 0) continue;
            if (__gcd(b - res, a) <= d) continue;
            setmax(nxt, b - res);
        }
        ans += (b - nxt) / d;
        b = nxt;
        d = __gcd(a, b);
    }
    cout << ans << '\n';
}