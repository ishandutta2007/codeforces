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
const int INF = 2010000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int d[8];
char c[8];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x0, y0;
    cin >> n >> x0 >> y0;
    forn(i, 0, 8) d[i] = INF;
    while (n--) {
        char q;
        int x, y;
        cin >> q >> x >> y;
        x -= x0, y -= y0;
        int i = 0;
        if (x == 0 && y > 0 && abs(y) < d[i]) {
            d[i] = abs(y);
            c[i] = q;
        }
        ++i;
        if (x == 0 && y < 0 && abs(y) < d[i]) {
            d[i] = abs(y);
            c[i] = q;
        }
        ++i;
        if (y == 0 && x > 0 && abs(x) < d[i]) {
            d[i] = abs(x);
            c[i] = q;
        }
        ++i;
        if (y == 0 && x < 0 && abs(x) < d[i]) {
            d[i] = abs(x);
            c[i] = q;
        }
        ++i;
        if (y == x && x > 0 && abs(x) < d[i]) {
            d[i] = abs(x);
            c[i] = q;
        }
        ++i;
        if (y == x && x < 0 && abs(x) < d[i]) {
            d[i] = abs(x);
            c[i] = q;
        }
        ++i;
        if (y == -x && x > 0 && abs(x) < d[i]) {
            d[i] = abs(x);
            c[i] = q;
        }
        ++i;
        if (y == -x && x < 0 && abs(x) < d[i]) {
            d[i] = abs(x);
            c[i] = q;
        }
        ++i;
    }
    forn(i, 0, 4) if (d[i] < INF && c[i] != 'B') {
        cout << "YES\n";
        return 0;
    }
    forn(i, 4, 8) if (d[i] < INF && c[i] != 'R') {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
}