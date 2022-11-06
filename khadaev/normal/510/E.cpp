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

bool is_prime(int k) {
    for (int i = 2; i * i <= k; ++i)
        if (k % i == 0)
            return false;
    return true;
}

void fail() {
    cout << "Impossible\n";
    exit(0);
}

vector<int> e[MAXN];
char used[MAXN];
vector<int> found;

void dfs(int i) {
    if (used[i]) return;
    used[i] = 1;
    found.eb(i);
    for (int j : e[i]) dfs(j);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int sz;
    cin >> sz;
    vector<pair<int, int>> even, odd;
    forn(i, 0, sz) {
        int a;
        cin >> a;
        (a % 2 ? odd : even).eb(a, i);
    }
    if (odd.size() != even.size()) fail();

    forn(i, 0, sz / 2)
        forn(j, 0, sz / 2) {
            if (is_prime(even[i].fs + odd[j].fs))
                c[i][sz / 2 + j] = 1;
        }
    s = sz;
    t = s + 1;
    n = t + 1;
    forn(i, 0, sz / 2) c[s][i] = 2;
    forn(i, 0, sz / 2) c[i + sz / 2][t] = 2;
    int fl = dinic();
    if (fl != sz) fail();
    forn(i, 0, sz / 2) forn(j, 0, sz / 2)
        if (f[i][j + sz / 2]) {
            e[even[i].sn].eb(odd[j].sn);
            e[odd[j].sn].eb(even[i].sn);
        }
    vector<vector<int>> ans;
    forn(i, 0, sz) {
        dfs(i);
        if (!found.empty()) ans.eb(found);
        found.clear();
    }
    cout << ans.size() << '\n';
    for (auto v : ans) {
        cout << v.size() << ' ';
        for (int i : v) cout << 1 + i << ' ';
        cout << '\n';
    }
}