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

void dfs(int v, vector<int> &c, vector<vector<int>> &e, int color) {
    if (c[v] != -1) return;
    c[v] = color;
    for (int u : e[v]) dfs(u, c, e, color);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n), rev(n);
    forn(i, 0, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        to[u].eb(v);
        rev[u].eb(v);
        rev[v].eb(u);
    }
    vector<int> comp(n, -1);
    forn(i, 0, n) dfs(i, comp, rev, i);
    vector<char> used(n);
    vector<int> in(n);
    forn(i, 0, n) for (int j : to[i]) ++in[j];
    queue<int> q;
    forn(i, 0, n) if (in[i] == 0) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        used[u] = 1;
        for (int v : to[u]) {
            --in[v];
            if (in[v] == 0) q.push(v);
        }
    }
    set<int> comps;
    forn(i, 0, n) comps.insert(comp[i]);
    set<int> bad;
    forn(i, 0, n) if (!used[i]) bad.insert(comp[i]);
    cout << n - comps.size() + bad.size() << '\n';
}