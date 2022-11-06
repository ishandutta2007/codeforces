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

const int N = 2e5 + 10;

int p[N];

int get(int i) {
    if (i == p[i]) return i;
    return p[i] = get(p[i]);
}

void unite(int u, int v) {
    u = get(u);
    v = get(v);
    p[u] = v;
}

int color[N], u[N], v[N];
vector<int> e[N];

int path[N], rooted[N];

void dfs(int i, int p) {
    int mx1 = 0, mx2 = 0;
    for (int j : e[i]) {
        if (j != p)
            dfs(j, i);
        path[i] = max(path[i], path[j]);
        if (rooted[j] > mx1) {
            mx2 = mx1;
            mx1 = rooted[j];
        } else if (rooted[j] > mx2) mx2 = rooted[j];
    }
    rooted[i] = 1 + mx1;
    path[i] = max(path[i], 1 + mx1 + mx2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    forn(i, 0, n) cin >> color[i];
    forn(i, 0, n) p[i] = i;
    forn(i, 0, n - 1) {
        cin >> u[i] >> v[i];
        --u[i], --v[i];
        if (color[u[i]] == color[v[i]])
            unite(u[i], v[i]);
    }
    forn(i, 0, n - 1) {
        int a = get(u[i]);
        int b = get(v[i]);
        if (a == b) continue;
        e[a].eb(b);
        e[b].eb(a);
    }
    dfs(get(0), -1);
    cout << path[get(0)] / 2 << '\n';
}