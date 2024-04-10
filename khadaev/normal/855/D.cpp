#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
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

const int N = 1e5 + 10;
const int LOG = 17;

int p1[LOG][N], p2[LOG][N];
int h[N];

int go(int x, int up, int p[][N]) {
    forn(i, 0, LOG)
        if (up & (1 << i))
            x = p[i][x];
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    forn(i, 0, n) {
        int p, t;
        cin >> p >> t;
        --p;
        if (t == -1) {
            p1[0][i] = i;
            p2[0][i] = i;
        } else if (t == 0) {
            p1[0][i] = p;
            p2[0][i] = i;
        } else {
            p1[0][i] = i;
            p2[0][i] = p;
        }
        if (t == -1) h[i] = 0;
        else h[i] = 1 + h[p];
    }
    forn(i, 1, LOG) forn(j, 0, n) {
        p1[i][j] = p1[i - 1][p1[i - 1][j]];
        p2[i][j] = p2[i - 1][p2[i - 1][j]];
    }
    int q;
    cin >> q;
    while (q--) {
        int tp, u, v;
        cin >> tp >> u >> v;
        --u, --v;
        if (tp == 1) {
            if (h[v] <= h[u]) {
                cout << "NO\n";
                continue;
            }
            if (go(v, h[v] - h[u], p1) == u)
                cout << "YES\n";
            else
                cout << "NO\n";
        } else {
            if (u == v || p2[0][v] == v) {
                cout << "NO\n";
                continue;
            }
            v = p2[0][v];
            if (h[u] > h[v])
                u = go(u, h[u] - h[v], p1);
            if (h[v] > h[u])
                v = go(v, h[v] - h[u], p2);
            if (u == v) {
                cout << "YES\n";
                continue;
            }
            if (h[u] != h[v]) {
                cout << "NO\n";
                continue;
            }
            ford(i, 0, LOG) {
                int pu = p1[i][u], pv = p2[i][v];
                if (pu != pv) {
                    if (h[u] - h[pu] != (1 << i)) continue;
                    if (h[v] - h[pv] != (1 << i)) continue;
                    u = pu;
                    v = pv;
                }
            }
            if (p1[0][u] == p2[0][v])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}