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
const int INF = 1e8;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 1010;
char c[N][N];
int dist[3][N][N];

void bfs(int col) {
    auto d = dist[col];
    forn(i, 0, N) forn(j, 0, N) d[i][j] = INF;
    vector<pair<int, int>> q;
    forn(i, 0, N) forn(j, 0, N) if (c[i][j] == '1' + col) q.eb(i, j);
    for (int step = 0; !q.empty(); ++step) {
        vector<pair<int, int>> nq;
        for (auto p : q) {
            int i = p.fs, j = p.sn;
            if (c[i][j] == '#') continue;
            if (d[i][j] != INF) continue;
            d[i][j] = step;
            nq.eb(i, j - 1);
            nq.eb(i, j + 1);
            nq.eb(i - 1, j);
            nq.eb(i + 1, j);
        }
        q = nq;
    }
}

int fnd(int c1, int c2) {
    int ans = INF;
    forn(i, 0, N) forn(j, 0, N) if (c[i][j] == '1' + c1) ans = min(ans, dist[c2][i][j]);
    return ans - 1;
}

int fnd3() {
    int ans = INF;
    forn(i, 0, N) forn(j, 0, N) if (c[i][j] != '#') {
        int sum = 0;
        forn(q, 0, 3) sum += dist[q][i][j];
        ans = min(ans, sum);
    }
    return ans - 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    forn(i, 0, N) forn(j, 0, N) c[i][j] = '#';
    int n, m;
    cin >> n >> m;
    forn(i, 0, n) cin >> (1 + c[1 + i]);
    forn(i, 0, n) c[1 + i][1 + m] = '#';
    forn(i, 0, 3) bfs(i);
    int dab = fnd(0, 1), dbc = fnd(1, 2), dca = fnd(2, 0);
    int ans = INF;
    ans = min(ans, dab + dbc);
    ans = min(ans, dbc + dca);
    ans = min(ans, dca + dab);
    ans = min(ans, fnd3());
    if (ans > 5e7) ans = -1;
    cout << ans << '\n';
}