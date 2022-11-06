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

int Div(int a, int b) {
    if (b <= 0) return INF;
    return (a + b - 1) / b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int hpy, ay, dy;
    cin >> hpy >> ay >> dy;
    int hpm, am, dm;
    cin >> hpm >> am >> dm;
    int h, a, d;
    cin >> h >> a >> d;
    int ans = INF;
    fore(y, 0, 200) fore(z, 0, 200) {
        if (ay + y <= dm) continue;
        int t = Div(hpm, ay + y - dm);
        int dmg = max(0, am - dy - z) * t;
        int x = max(0, dmg - hpy + 1);
        ans = min(ans, x * h + y * a + z * d);
    }
    cout << ans << '\n';
}