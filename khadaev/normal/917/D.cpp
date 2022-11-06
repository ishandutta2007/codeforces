#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n) - 1; i >= (int)(a); --i)
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

const int N = 101;

ll Pow(ll a, ll b) {
    ll x = 1, y = a;
    while (b) {
        if (b % 2) (x *= y) %= MOD;
        (y *= y) %= MOD;
        b /= 2;
    }
    return x;
}

ll Inv(ll a) {
    return Pow(a, MOD - 2);
}


using poly = vector<ll>;

poly operator+ (poly a, poly b) {
    int sz = max(a.size(), b.size());
    poly ans(sz);
    forn(i, 0, a.size()) ans[i] += a[i];
    forn(i, 0, b.size()) ans[i] += b[i];
    forn(i, 0, sz) if (ans[i] >= MOD) ans[i] -= MOD;
    return ans;
}

poly operator* (poly a, poly b) {
    int sz = a.size() + b.size() - 1;
    poly ans(sz);
    forn(i, 0, a.size()) forn(j, 0, b.size())
        (ans[i + j] += a[i] * b[j]) %= MOD;
    return ans;
}

void operator*= (poly& a, ll x) {
    for (auto& y : a)
        (y *= x) %= MOD;
}
ll a[N][N];
ll det(int n) {
    ll ans = 1;
    for (int i = 0; i < n; ++i) {
        int pos = i;
        for (int j = i; j < n; ++j)
            if (a[j][i]) {
                pos = j;
                break;
            }
        if (pos != i) {
            ans = MOD - ans;
            for (int j = 0; j < n; ++j)
                swap(a[pos][j], a[i][j]);
        }
        ll inv = Inv(a[i][i]);
        (ans *= a[i][i]) %= MOD;
        for (int j = i; j < n; ++j) {
            (a[i][j] *= inv) %= MOD;
            a[i][j] = MOD - a[i][j];
        }
        for (int j = i + 1; j < n; ++j)
            for (int k = i + 1; k < n; ++k)
                (a[j][k] += a[i][k] * a[j][i]) %= MOD;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    //n = 100;
    vector<pair<int, int>> e;
    forn(i, 1, n) {
        int u, v;
        cin >> u >> v;
        //u = i, v = i + 1;
        --u, --v;
        e.eb(u, v);
    }
    vector<ll> vals(n);
    forn(x, 0, n) {
        forn(i, 0, n) forn(j, 0, n) a[i][j] = MOD - 1;
        for (auto p : e) {
            int u = p.fs, v = p.sn;
            a[u][v] = MOD - x;
            a[v][u] = MOD - x;
        }
        forn(i, 0, n) {
            a[i][i] = 0;
            forn(j, 0, n) if (j != i) a[i][i] += a[i][j];
            a[i][i] = (MOD - a[i][i] % MOD) % MOD;
        }
        vals[x] = det(n - 1);
    }
    poly ans;
    forn(i, 0, n) {
        poly add = {1};
        ll mult = 1;
        forn(j, 0, n) if (j != i) {
            poly mon = {MOD - j, 1};
            add = add * mon;
            (mult *= (MOD + i - j)) %= MOD;
        }
        add *= Inv(mult);
        add *= vals[i];
        //trace(add);
        ans = ans + add;
    }
    ans.resize(n);
    for (ll x : ans) cout << x << ' ';
}