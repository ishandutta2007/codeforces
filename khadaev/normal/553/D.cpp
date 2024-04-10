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

struct Ratio {
    ll p, q;

    Ratio () {};
    Ratio (int _p, long unsigned _q) : p(_p), q(_q) {};

    bool operator< (const Ratio x) const {
        return p * x.q > x.p * q;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<char> bad(n, 0);
    forn(i, 0, k) {
        int x;
        cin >> x;
        bad[--x] = 1;
    }
    vector<vector<int>> e(n);
    forn(i, 0, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[u].eb(v);
        e[v].eb(u);
    }
    priority_queue<pair<Ratio, int>> q;
    vector<int> deg(n);
    forn(i, 0, n) if (!bad[i]) for (int j : e[i]) ++deg[j];
    forn(i, 0, n) if (!bad[i]) q.emplace(Ratio(deg[i], e[i].size()), i);
    vector<char> used(n, 0);
    vector<int> order;
    Ratio ans(-1, 1);
    int pos = -1;
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        if (used[p.sn]) continue;
        used[p.sn] = 1;
        if (p.fs < ans) {
            ans = p.fs;
            pos = (int)order.size();
        }
        order.eb(p.sn);
        for (int u : e[p.sn]) {
            if (used[u] || bad[u]) continue;
            --deg[u];
            q.emplace(Ratio(deg[u], e[u].size()), u);
        }
    }
    cout << int(order.size()) - pos << '\n';
    forn(i, pos, int(order.size()))
        cout << 1 + order[i] << ' ';
    //cerr << '\n' << ans.p << ' ' << ans.q << '\n';
}