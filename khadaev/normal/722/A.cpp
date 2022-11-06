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

int dist(int x, int y) {
    int ans = 0;
    while (x || y) {
        ans += (x % 10 != y % 10);
        x /= 10;
        y /= 10;
    }
    return ans;
}

void show(int x) {
    cout << x / 10 << x % 10 ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int x, y;
    char c;
    cin >> x >> c >> y;
    int dx = INF, optx = -1;
    if (t == 12) {
        fore(xx, 1, 12) {
            if (dist(x, xx) < dx) {
                dx = dist(x, xx);
                optx = xx;
            }
        }
    } else {
        forn(xx, 0, 24) {
            if (dist(x, xx) < dx) {
                dx = dist(x, xx);
                optx = xx;
            }
        }
    }
    int dy = INF, opty = -1;
    forn(yy, 0, 60) {
        if (dist(y, yy) < dy) {
            dy = dist(y, yy);
            opty = yy;
        }
    }
    show(optx);
    cout << ':';
    show(opty);
    cout << '\n';
}