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
const int MAXN = 210;
 
int n, c[MAXN][MAXN], f[MAXN][MAXN], s, t, d[MAXN], ptr[MAXN], q[MAXN];

bool bfs() {
    int qh = 0, qt = 0;
    q[qt++] = s;
    memset(d, -1, n * sizeof d[0]);
    d[s] = 0;
    while (qh < qt) {
        int v = q[qh++];
        for (int to = 0; to < n; ++to)
            if (d[to] == -1 && f[v][to] < c[v][to]) {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
    }
    return d[t] != -1;
}

int dfs (int v, int flow) {
    if (!flow) return 0;
    if (v == t) return flow;
    for (int &to = ptr[v]; to < n; ++to) {
        if (d[to] != d[v] + 1) continue;
        int pushed = dfs (to, min (flow, c[v][to] - f[v][to]));
        if (pushed) {
            f[v][to] += pushed;
            f[to][v] -= pushed;
            return pushed;
        }
    }
    return 0;
}

int dinic() {
    int flow = 0;
    for (;;) {
        if (!bfs())  break;
        memset (ptr, 0, n * sizeof ptr[0]);
        while (int pushed = dfs (s, INF))
            flow += pushed;
    }
    return flow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k, m;
    cin >> k >> m;
    vector<int> a(k), b(k);
    forn(i, 0, k) cin >> a[i];
    forn(i, 0, k) cin >> b[i];
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        c[u][v + k] = c[v][u + k] = 100;
    }
    forn(i, 0, k) c[i][i + k] = 100;
    s = 2 * k;
    t = s + 1;
    n = t + 1;
    forn(i, 0, k) c[s][i] = a[i];
    forn(i, 0, k) c[i + k][t] = b[i];
    int fl = dinic();
    int suma = 0, sumb = 0;
    forn(i, 0, k) suma += a[i];
    forn(i, 0, k) sumb += b[i];
    if (fl != suma || fl != sumb) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    forn(i, 0, k) {
        forn(j, 0, k) cout << f[i][j + k] << ' ';
        cout << '\n';
    }
}