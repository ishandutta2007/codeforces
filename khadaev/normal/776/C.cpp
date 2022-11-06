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



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    vector<ll> goal;
    if (k == 1) {
        goal.eb(1);
    } else if (k == -1) {
        goal.eb(1);
        goal.eb(-1);
    } else {
        ll val = 1;
        while (val < 2e14) {
            goal.eb(val);
            val *= k;
        }
    }

    vector<int> a(n);
    forn(i, 0, n) cin >> a[i];

    ll ans = 0;

    map<ll, int> sums;
    ll s = 0;
    ++sums[s];
    forn(i, 0, n) {
        s += a[i];
        for (ll x : goal) {
            auto it = sums.find(s - x);
            if (it != sums.end()) ans += it->second;
        }
        ++sums[s];
    }
    /*for (ll x : goal) {
        auto it = sums.find(s - x);
        if (it != sums.end()) ans += it->second;
    }*/

    cout << ans << '\n';
}