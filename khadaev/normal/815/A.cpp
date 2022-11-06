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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    forn(i, 0, n) forn(j, 0, m) cin >> a[i][j];
    int ans = INF, opt = -1;
    fore(d, 0, 500) {
        vector<int> x(m), y(n);
        x[0] = d;
        forn(i, 0, n) y[i] = a[i][0] - x[0];
        forn(j, 1, m) x[j] = a[0][j] - y[0];
        bool ok = true;
        forn(i, 0, n) if (y[i] < 0) ok = false;
        forn(j, 0, m) if (x[j] < 0) ok = false;
        forn(i, 0, n)
            forn(j, 0, m) {
                if (a[i][j] != y[i] + x[j]) ok = false;
            }
        if (ok) {
            int loc = 0;
            forn(i, 0, n) loc += y[i];
            forn(j, 0, m) loc += x[j];
            if (loc < ans) {
                ans = loc;
                opt = d;
            }
        }
    }
    if (ans == INF) {
        cout << "-1\n";
        return 0;
    }
    cout << ans << '\n';
    int d = opt;
    vector<int> x(m), y(n);
    x[0] = d;
    forn(i, 0, n) y[i] = a[i][0] - x[0];
    forn(j, 1, m) x[j] = a[0][j] - y[0];
    forn(i, 0, n) {
        forn(_, 0, y[i]) cout << "row " << 1 + i << '\n';
    }
    forn(j, 0, m) {
        forn(_, 0, x[j]) cout << "col " << 1 + j << '\n';
    }
}