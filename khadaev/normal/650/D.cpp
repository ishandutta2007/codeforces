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
    vector<int> h(n);
    forn(i, 0, n) cin >> h[i];
    vector<int> a(m), b(m);
    vector<vector<pair<int, int>>> q(n);
    forn(i, 0, m) {
        cin >> a[i] >> b[i];
        --a[i];
        q[a[i]].eb(b[i], i);
    }
    vector<int> d(n + 1, INF);
    d[0] = -INF;
    vector<set<int>> posL(n), posR(n);
    vector<int> ans(m, 1);
    forn(i, 0, n) {
        for (auto p : q[i]) {
            int j = int(lower_bound(all(d), p.fs) - d.begin());
            ans[p.sn] += j - 1;
        }
        int j = int(lower_bound(all(d), h[i]) - d.begin());
        posL[j - 1].insert(i);
        if (d[j - 1] < h[i] && h[i] < d[j]) {
            d[j] = h[i];
        }
    }
    int k = int(lower_bound(all(d), INF) - d.begin() - 1);
    d.assign(n + 1, INF);
    d[0] = -INF;
    ford(i, 0, n) {
        for (auto p : q[i]) {
            int j = int(lower_bound(all(d), -p.fs) - d.begin());
            ans[p.sn] += j - 1;
        }
        int j = int(lower_bound(all(d), -h[i]) - d.begin());
        posR[k - j].insert(i);
        if (d[j - 1] < -h[i] && -h[i] < d[j]) {
            d[j] = -h[i];
        }
    }
    vector<char> only(n, 0);
    forn(i, 0, k) {
        int cnt = 0, last = -1;
        for (auto x : posL[i]) {
            if (posR[i].find(x) == posR[i].end()) continue;
            ++cnt;
            last = x;
        }
        assert(cnt != 0);
        if (cnt == 1) only[last] = 1;
    }
    forn(i, 0, m) {
        if (only[a[i]]) ans[i] = max(ans[i], k - 1);
        else ans[i] = max(ans[i], k);
    }
    forn(i, 0, m) cout << ans[i] << '\n';
}