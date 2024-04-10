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

bool check(int n, int m, vector<vector<int>>& a, bool swapped) {
    int xn = swapped ? m : n;
    int xm = swapped ? n : m;
    auto ok = [&](int i, int j) {
        if (i < j) swap(i, j);
        if (i - j == 1) return j % xm == 0;
        if (i - j == xm) return false;
        return true;
    };
    forn(i, 0, n) {
        forn(j, 1, m) {
            if (!ok(a[i][j], a[i][j - 1]))
                return false;
        }
    }
    forn(i, 1, n) {
        forn(j, 0, m) {
            if (!ok(a[i][j], a[i - 1][j]))
                return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << "YES\n";
        cout << 1 << '\n';
        return 0;
    }
    if (n > 2 && m > 2) {
        vector<vector<int>> ans(n, vector<int>(m));
        forn(i, 0, n) forn(j, 0, m) {
            ans[i][j] = i * m + j + 1;
        }
        forn(i, 0, n) {
            vector<int> sh(m);
            forn(j, 0, m) sh[j] = ans[i][(j + i) % m];
            ans[i] = sh;
        }
        forn(j, 0, m) {
            vector<int> sh(n);
            forn(i, 0, n) sh[i] = ans[(i + j) % n][j];
            forn(i, 0, n) ans[i][j] = sh[i];
        }
        cout << "YES\n";
        assert(check(n, m, ans, false));
        forn(i, 0, n) {
            forn(j, 0, m) cout << ans[i][j] << ' ';
            cout << '\n';
        }
        return 0;
    }
    bool swapped = false;
    if (n > m) {
        swap(n, m);
        swapped = true;
    }
    vector<vector<int>> ans(n, vector<int>(m));
    if (n == 1) {
        if (m < 4) {
            cout << "NO\n";
            return 0;
        }
        int it = 0;
        for (int i = 1; i < m; i += 2)
            ans[0][it++] = 1 + i;
        for (int i = 0; i < m; i += 2)
            ans[0][it++] = 1 + i;
    } else {
        if (m < 4) {
            cout << "NO\n";
            return 0;
        }
        forn(i, 0, m)
            ans[i % 2][i] = swapped ? 2 * i + 1 : i + 1;
        forn(i, 0, m) {
            int x = (i + 2) % m;
            ans[(x + 1) % 2][x] = swapped ? 2 * i + 2 : m + i + 1;
        }
    }
    assert(check(n, m, ans, swapped));
    cout << "YES\n";
    if (swapped) {
        forn(j, 0, m) {
            forn(i, 0, n) cout << ans[i][j] << ' ';
            cout << '\n';
        }
    } else {
        forn(i, 0, n) {
            forn(j, 0, m) cout << ans[i][j] << ' ';
            cout << '\n';
        }
    }
}