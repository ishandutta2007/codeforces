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

tuple<ll, int, int> get(ll t) {
    int x = 0, y = 0;
    while (t % 2 == 0) {
        t /= 2;
        ++x;
    }
    while (t % 3 == 0) {
        t /= 3;
        ++y;
    }
    return tuple<ll, int, int> (t, x, y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    ll p1, p2;
    int x1, y1, x2, y2;
    tie(p1, x1, y1) = get(a1 * b1);
    tie(p2, x2, y2) = get(a2 * b2);
    if (p1 != p2) {
        cout << "-1\n";
        return 0;
    }
    int ans = 0;
    while (y1 > y2) {
        if (a1 % 3 == 0) a1 /= 3, a1 *= 2, ++x1;
        else b1 /= 3, b1 *= 2, ++x1;
        --y1;
        ++ans;
    }
    while (y1 < y2) {
        if (a2 % 3 == 0) a2 /= 3, a2 *= 2, ++x2;
        else b2 /= 3, b2 *= 2, ++x2;
        --y2;
        ++ans;
    }
    while (x1 > x2) {
        if (a1 % 2 == 0) a1 /= 2;
        else b1 /= 2;
        ++ans;
        --x1;
    }
    while (x1 < x2) {
        if (a2 % 2 == 0) a2 /= 2;
        else b2 /= 2;
        ++ans;
        --x2;
    }
    cout << ans << '\n';
    cout << a1 << ' ' << b1 << '\n';
    cout << a2 << ' ' << b2 << '\n';
}