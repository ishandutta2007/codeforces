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
/*
int f(int x, int y, int z) {
    cerr << x << ' ' << y << ' ' << z << '\n';
    if (x < 0) return 0;
    if (x == 0) {
        if (y == 0 && z == 0) return 1;
        else return 0;
    }
    return f(y - 1, x, z) + f(z - 1, x, y);
}
*/

int remsq(int n) {
    for (int i = 2; i * i <= n; ++i) {
        while (n % (i * i) == 0)
            n /= (i * i);
    }
    return n;
}

const int N = 333;
ll fact[N], tcaf[N];

ll Pow(ll a, ll b) {
    ll x = 1, y = a;
    while (b) {
        if (b % 2) x = x * y % MOD;
        y = y * y % MOD;
        b /= 2;
    }
    return x;
}

ll Inv(ll x) {
    return Pow(x, MOD - 2);
}

ll binom(int x, int y) {
    if (y < 0) return 0;
    if (y > x) return 0;
    return fact[x] * tcaf[y] % MOD * tcaf[x - y] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //int x, y, z;
    //cin >> x >> y >> z;
    //cout << f(x - 1, y, z) + f(y - 1, x, z) + f(z - 1, x, y);
    int n;
    cin >> n;
    map<int, int> cnt;
    forn(i, 0, n) {
        int x;
        cin >> x;
        ++cnt[remsq(x)];
    }
    fact[0] = 1;
    forn(i, 1, N) fact[i] = fact[i - 1] * i % MOD;
    tcaf[N - 1] = Inv(fact[N - 1]);
    ford(i, 0, N - 1) {
        tcaf[i] = tcaf[i + 1] * (i + 1) % MOD;
    }
    vector<int> q;
    for (auto p : cnt) q.eb(p.sn);
    ll ans = 1;
    int m = q.size();
    forn(i, 0, m)
        ans = ans * fact[q[i]] % MOD;
    vector<ll> dp(n);
    dp[0] = 1;
    int sz = 0;
    forn(i, 0, m) {
        vector<ll> dpn(n);
        int x = q[i];
        forn(j, 0, n)
            forn(k, 0, n) {
                fore(add, 0, x) {
                    int rem = j + add - k;
                    int rest = x - (add + rem);
                    if (rem < 0 || rest < 0) continue;
                    ll nw = 1;
                    nw *= binom(j, rem);
                    nw %= MOD;
                    nw *= binom(sz + 1 - j, rest);
                    nw %= MOD;
                    nw *= binom(x - 1, add);
                    nw %= MOD;
                    dpn[k] += dp[j] * nw;
                    dpn[k] %= MOD;
                }
            }
        sz += x;
        dp = dpn;
    }
    cout << ans * dp[0] % MOD << '\n';
}