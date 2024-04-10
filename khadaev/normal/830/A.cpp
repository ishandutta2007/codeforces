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

int n, k;
ll p;

bool check(vector<ll> &a, vector<ll> &b, ll d) {
    set<ll> keys;
    for (auto x : b) keys.insert(x);
    for (int i = 0; i < n; ++i) {
        if (a[i] >= p) break;
        if (d < p - a[i]) return false;
        ll mx = (d - (p - a[i])) / 2;
        auto it = keys.lower_bound(a[i] - mx);
        if (it == keys.end()) return false;
        if (abs(a[i] - *it) + abs(*it - p) > d) return false;
        keys.erase(it);
    }
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] < p) break;
        if (d < a[i] - p) return false;
        ll mx = (d - (a[i] - p)) / 2;
        auto it = keys.upper_bound(a[i] + mx);
        if (it == keys.begin()) return false;
        --it;
        if (abs(a[i] - *it) + abs(*it - p) > d) return false;
        keys.erase(it);
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> p;
    vector<ll> a(n);
    forn(i, 0, n) cin >> a[i];
    vector<ll> b(k);
    forn(i, 0, k) cin >> b[i];
    sort(all(a));
    sort(all(b));
    ll l = -1, r = 2e9 + 100;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        if (check(a, b, m))
            r = m;
        else
            l = m;
    }
    cout << r << '\n';
}