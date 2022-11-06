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

int div_up(int a, int b) {
    return (a + b - 1) / b;
}

int solve(int a, int b, vector<int> &x) {
    vector<pair<int, int>> pos = {{a, b}};
    forn(i, 0, x.size()) {
        vector<pair<int, int>> npos;
        forn(j, 0, pos.size()) {
            if (j && pos[j] == pos[j - 1]) continue;
            if (pos[j] == pair<int,int>{1, 1}) return i;
            npos.eb(div_up(pos[j].fs, x[i]), pos[j].sn);
            npos.eb(pos[j].fs, div_up(pos[j].sn, x[i]));
        }
        sort(all(npos));
        pos = npos;
    }
    for (auto p : pos)
        if (p == pair<int,int>{1, 1}) return x.size();
    return INF;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, h, w, n;
    cin >> a >> b >> h >> w >> n;
    vector<int> x(n);
    forn(i, 0, n) cin >> x[i];
    sort(all(x));
    reverse(all(x));
    int ans = min(solve(div_up(a, h), div_up(b, w), x), solve(div_up(b, h), div_up(a, w), x));
    if (ans == INF) ans = -1;
    cout << ans << '\n';
}