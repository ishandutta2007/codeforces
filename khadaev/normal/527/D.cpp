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
    int n;
    cin >> n;
    vector<tuple<int, int, int>> ps;
    forn(i, 0, n) {
        int x, w;
        cin >> x >> w;
        ps.eb(x - w, 1, i);
        ps.eb(x + w, -1, i);
    }
    sort(all(ps));
    vector<int> opts(n);
    int opt = 0;
    for (auto p : ps) {
        int x, t, i;
        tie(x, t, i) = p;
        if (t == -1) {
            opt = max(opt, opts[i] + 1);
        } else {
            opts[i] = opt;
        }
    }
    cout << opt << '\n';
}