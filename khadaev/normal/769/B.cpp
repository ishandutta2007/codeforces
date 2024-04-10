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
    vector<int> a(n);
    forn(i, 0, n) cin >> a[i];
    int s = 0;
    forn(i, 0, n) s += a[i];
    if (s < n - 1 || a[0] == 0) {
        cout << "-1\n";
        return 0;
    }
    int prev = 0;
    vector<int> ok(n);
    vector<pair<int, int>> ans;
    ok[0] = 1;
    forn(i, 1, n)
        if (a[i]) {
            ans.eb(prev, i);
            --a[prev];
            prev = i;
            ok[i] = 1;
        }
    int from = 0;
    forn(i, 0, n)
        if (!ok[i]) {
            while (a[from] == 0) ++from;
            ans.eb(from, i);
            --a[from];
        }
    cout << ans.size() << '\n';
    for (auto p : ans) cout << 1 + p.fs << ' ' << 1 + p.sn << '\n';
}