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
    vector<int> a(n);
    forn(i, 0, n) cin >> a[i];
    vector<int> bnd;
    forn(i, 0, n)
        for (int j = 1; j * j <= a[i]; ++j) {
            bnd.eb(j);
            bnd.eb((a[i] + j - 1) / j);
        }
    ll mx = 0;
    sort(all(bnd));
    forn (j, 0, bnd.size()) {
        if (j && bnd[j] == bnd[j - 1]) continue;
        int d = bnd[j];
        ll nw = 0;
        forn(i, 0, n) {
            if (a[i] % d)
                nw += d - a[i] % d;
        }
        if (nw > k) continue;
        ll coeff = 0;
        forn(i, 0, n)
            coeff += (a[i] % d ? 1 : 0) + a[i] / d;
        ll add = (k - nw) / coeff;
        setmax(mx, d + add);
    }
    cout << mx << '\n';
}