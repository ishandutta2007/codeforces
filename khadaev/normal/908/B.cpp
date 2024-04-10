#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n) - 1; i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
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

template<typename T>
inline void setmax(T& a, T b) {
    if (a < b) a = b;
}

template<typename T>
inline void setmin(T& a, T b) {
    if (a > b) a = b;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, m;
    cin >> n >> m;
    vector<string> in(n);
    forn(i, 0, n) cin >> in[i];
    int sx = -1, sy = -1;
    forn(i, 0, n) forn(j, 0, m) if (in[i][j] == 'S') {
        sx = i, sy = j;
    }
    vector<int> perm(4);
    iota(all(perm), 0);
    vector<int> dx = {-1, 1, 0, 0},
        dy = {0, 0, -1, 1};
    int ans = 0;
    string path;
    cin >> path;
    do {
        bool ok = 1;
        int x = sx, y = sy;
        for (char c : path) {
            c -= '0';
            x += dx[perm[c]];
            y += dy[perm[c]];
            if (x < 0 || y < 0 || x == n || y == m || in[x][y] == '#') {
                ok = 0;
                break;
            }
            if (in[x][y] == 'E') break;
        }
        if (ok && in[x][y] == 'E') ++ans;
    } while (next_permutation(all(perm)));
    cout << ans << '\n';
}