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

const int N = 1005;
char s[N][N];
int dist[N][N];

void fail() {
    cout << "IMPOSSIBLE\n";
    exit(0);
}

bool ok(int x, int y, int d) {
    return (s[x][y] == '.' && dist[x][y] <= d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    forn(i, 0, n) cin >> (1 + s[1 + i]);
    forn(i, 0, m) s[0][1 + i] = '*';
    forn(i, 0, m) s[1 + n][1 + i] = '*';
    forn(i, 0, n) s[1 + i][0] = '*';
    forn(i, 0, n) s[1 + i][1 + m] = '*';

    int x = -1, y = -1;
    fore(i, 1, n) fore(j, 1, m) if (s[i][j] == 'X') {
        x = i;
        y = j;
        s[i][j] = '.';
    }

    forn(i, 0, N) forn(j, 0, N) dist[i][j] = INF;
    int d = 0;
    vector<pair<int, int>> q = {{x, y}};
    while (!q.empty()) {
        vector<pair<int, int>> nq;
        for (auto p : q) {
            if (s[p.fs][p.sn] == '*') continue;
            if (dist[p.fs][p.sn] != INF) continue;
            dist[p.fs][p.sn] = d;
            nq.eb(p.fs + 1, p.sn);
            nq.eb(p.fs, p.sn + 1);
            nq.eb(p.fs - 1, p.sn);
            nq.eb(p.fs, p.sn - 1);
        }
        q = nq;
        ++d;
    }
    string ans;
    forn(i, 0, k) {
        int rest = k - 1 - i;
        if (ok(x + 1, y, rest)) {
            ++x;
            ans += "D";
            continue;
        }
        if (ok(x, y - 1, rest)) {
            --y;
            ans += "L";
            continue;
        }
        if (ok(x, y + 1, rest)) {
            ++y;
            ans += "R";
            continue;
        }
        if (ok(x - 1, y, rest)) {
            --x;
            ans += "U";
            continue;
        }
        fail();
    }
    if (dist[x][y]) fail();
    cout << ans << '\n';
}