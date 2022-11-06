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

void fail() {
    cout << "-1\n";
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> e(n);
    forn(i, 1, n) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[u].eb(v);
        e[v].eb(u);
    }
    vector<int> deg(n);
    forn(i, 0, n) deg[i] = e[i].size();
    stack<int> q;
    vector<vector<int>> vals(n);
    forn(i, 0, n) if (deg[i] == 1) vals[i].eb(0);
    forn(i, 0, n) if (deg[i] == 1) q.push(i);
    int root = -1;
    while (1) {
        int u = q.top();
        //cerr << u << '\n';
        q.pop();
        int val = vals[u][0];
        bool ex = 0;
        for (int x : vals[u]) if (x != val) {
            if (root == -1) {
                root = u;
                ex = 1;
                break;
            } else fail();
        }
        if (ex) continue;
        --deg[u];
        int v;
        for (int x : e[u]) if (deg[x]) v = x;
        --deg[v];
        vals[v].eb(val + 1);
        if (deg[v] == 0) {
            if (root != -1 && v != root) fail();
            set<int> diff;
            for (int x : vals[v]) diff.insert(x);
            if (diff.size() > 2) {
                fail();
            }
            int ans = 0;
            for (int x : diff) ans += x;
            while (ans % 2 == 0) ans /= 2;
            cout << ans << '\n';
            return 0;
        }
        if (deg[v] == 1) q.push(v);
    }
}