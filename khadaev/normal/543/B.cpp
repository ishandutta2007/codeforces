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

vector<vector<int>> e;
vector<vector<ll>> d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    e.resize(n);
    forn(i, 0, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        e[a].eb(b), e[b].eb(a);
    }
    int s1, t1, l1;
    cin >> s1 >> t1 >> l1;
    --s1, --t1;
    int s2, t2, l2;
    cin >> s2 >> t2 >> l2;
    --s2, --t2;
    d.resize(n);
    forn(i, 0, n) {
        d[i].resize(n);
        fill(all(d[i]), INF);
        d[i][i] = 0;
        vector<int> q = {i};
        int dist = 1;
        while (!q.empty()) {
            vector<int> nq;
            for (int u : q)
                for (int v : e[u])
                    if (d[i][v] == INF) {
                        d[i][v] = dist;
                        nq.eb(v);
                    }
            q = nq;
            ++dist;
        }
    }
    ll ans = INF;
    forn(i, 0, n) forn(j, 0, n) {
        ll d1 = d[s1][i] + d[i][j] + d[j][t1];
        if (d1 > l1) continue;
        ll d2 = d[s2][i] + d[i][j] + d[j][t2];
        if (d2 > l2) continue;
        ll rest = d[s1][i] + d[s2][i] + d[i][j] + d[j][t1] + d[j][t2];
        ans = min(ans, rest);
    }
    swap(s2, t2);
    forn(i, 0, n) forn(j, 0, n) {
        ll d1 = d[s1][i] + d[i][j] + d[j][t1];
        if (d1 > l1) continue;
        ll d2 = d[s2][i] + d[i][j] + d[j][t2];
        if (d2 > l2) continue;
        ll rest = d[s1][i] + d[s2][i] + d[i][j] + d[j][t1] + d[j][t2];
        ans = min(ans, rest);
    }
    if (d[s1][t1] <= l1 && d[s2][t2] <= l2) ans = min(ans, d[s1][t1] + d[s2][t2]);
    if (ans == INF) cout << "-1\n";
    else cout << m - ans << '\n';
}