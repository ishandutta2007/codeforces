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

const int N = 2017;
char a[N][N];

bool good(int x, int y) {
    if (x == 0 || y == 0) return false;
    if (a[x][y] == '.') return false;
    for (int dx = -1; dx < 2; dx += 2)
        for (int dy = -1; dy < 2; dy += 2)
            if (a[x + dx][y + dy] == '.' && a[x][y + dy] == '.' && a[x + dx][y] == '.')
                return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    forn(i, 0, n) cin >> (1 + a[i + 1]);
    cout << '\n';
    fore(i, 0, n + 1) a[i][0] = a[i][m + 1] = '*';
    fore(i, 0, m + 1) a[0][i] = a[n + 1][i] = '*';
    queue<pair<int, int>> q;
    forn(i, 0, n) forn(j, 0, m) if (good(1 + i, 1 + j)) q.emplace(1 + i, 1 + j);
    while (!q.empty()) {
        int x = q.front().fs, y = q.front().sn;
        q.pop();
        if (a[x][y] == '.') continue;
        a[x][y] = '.';
        forn(dx, -1, 2)
            forn(dy, -1, 2)
                if (good(x + dx, y + dy)) q.emplace(x + dx, y + dy);
    }
    fore(i, 1, n) {
        a[i][m + 1] = '\0';
        cout << 1 + a[i] << '\n';
    }
}