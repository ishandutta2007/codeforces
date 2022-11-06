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
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a;
    bool start = true;
    forn(i, 0, n) {
        ll x;
        cin >> x;
        if (x == 0 && start) continue;
        a.eb(x);
        start = false;
    }
    n = a.size();
    forn(i, 0, n) if (a[i] >= k) {
        cout << 0 << '\n';
        return 0;
    }

    if (n == 2) {
        ll q = a[0], w = a[1];
        cout << (k - w + q - 1) / q << '\n';
        return 0;
    } 
    if (n == 3) {
        ll l = 0, r = 2e9;
        while (l + 1 < r) {
            ll t = (l + r) / 2;
            ll x = t * (t + 1) / 2;
            if (k / a[0] < x) {
                r = t;
                continue;
            }
            x *= a[0];
            x += a[1] * t + a[2];
            if (x >= k) r = t;
            else l = t;
        }
        cout << r << '\n';
        return 0;
    }
    for (int it = 1; ; ++it) {
        if (it % 1000000 == 0) cerr << it / 1000000 << '\n';
        //cerr << a.back() << '\n';
        forn(j, 1, n) {
            a[j] += a[j - 1];
            if (a[j] >= k) {
                cout << it << '\n';
                return 0;
            }
        }
    }    
}