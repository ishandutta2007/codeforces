#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (ll i = a; i < n; ++i)
#define ford(i, a, n) for (ll i = n - 1; i >= a; --i)
#define fore(i, a, n) for (ll i = a; i <= n; ++i)
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
    ll w, h, n;
    cin >> w >> h >> n;
    set<ll> xp = {0, w}, xn = {-w, 0}, yp = {0, h}, yn = {-h, 0};
    multiset<ll> dx = {-w}, dy = {-h};
    forn(i, 0, n) {
        char c;
        cin >> c;
        if (c == 'H') {
            ll y;
            cin >> y;
            ll prv = -*yn.lower_bound(-y), nxt = *yp.lower_bound(y);
            auto it = dy.find(- nxt + prv);
            dy.erase(it);
            dy.insert(prv - y);
            dy.insert(y - nxt);
            yp.insert(y);
            yn.insert(-y);
        } else {
            ll x;
            cin >> x;
            ll prv = -*xn.lower_bound(-x), nxt = *xp.lower_bound(x);
            auto it = dx.find(- nxt + prv);
            dx.erase(it);
            dx.insert(prv - x);
            dx.insert(x - nxt);
            xp.insert(x);
            xn.insert(-x);
        }
        cout << *dx.begin() * *dy.begin() << '\n';
    }
}