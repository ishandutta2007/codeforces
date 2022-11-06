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

int m;

pair<ll, ll> solve(ll h, ll a, ll x, ll y) {
    vector<char> used(m, 0);
    int fst = 0;
    while (h != a) {
        if (used[h]) return {-1, -1};
        used[h] = 1;
        h = (h * x + y) % m;
        ++fst;
    }
    int per = 0;
    fill(all(used), 0);
    do {
        if (used[h]) return {fst, -1};
        used[h] = 1;
        h = (h * x + y) % m;
        ++per;
    } while (h != a);
    return {fst, per};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m;
    int h, a, x, y;
    cin >> h >> a >> x >> y;
    pair<ll, ll> p = solve(h, a, x, y);
    cin >> h >> a >> x >> y;
    pair<ll, ll> q = solve(h, a, x, y);
    ll ans = -1;
    if (p.fs != -1 && q.fs != -1) {
        if (p.sn == -1) swap(p, q);
        if (p.sn == -1) {
            if (p.fs == q.fs) ans = p.fs;
        } else if (q.sn == -1) {
            if ((q.fs - p.fs) % p.sn == 0 && q.fs >= p.fs)
                ans = q.fs;
        } else {
            if (p.fs < q.fs) swap(p, q);
            ll d = __gcd(p.sn, q.sn);
            if (p.fs % d == q.fs % d) {
                for (ll i = 0; ;++i) {
                    ll val = p.fs + i * p.sn;
                    if ((val - q.fs) % q.sn == 0) {
                        ans = val;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}