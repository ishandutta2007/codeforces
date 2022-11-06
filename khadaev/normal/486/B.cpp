#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
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

const int N = 111;
int a[N][N], b[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, m;
    cin >> n >> m;
    forn(i, 0, n) forn(j, 0, m) cin >> b[i][j];
    forn(i, 0, n) forn(j, 0, m) a[i][j] = 1;
    forn(i, 0, n) forn(j, 0, m) if (b[i][j] == 0) {
        forn(k, 0, n) a[k][j] = 0;
        forn(k, 0, m) a[i][k] = 0;
    }
    forn(i, 0, n) forn(j, 0, m) {
        int OR = 0;
        forn(k, 0, n) OR |= a[k][j];
        forn(k, 0, m) OR |= a[i][k];
        if (OR != b[i][j]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    forn(i, 0, n) {
        forn(j, 0, m) cout << a[i][j] << ' ';
        cout << '\n';
    }
}