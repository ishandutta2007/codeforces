#pragma GCC optimize("Ofast")
/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const ld eps = 1e-10;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 18) + 239;
const int B = 2000;
const int X = 410;

int n, m;
string s[X];
int pref[X][X];
int f1[X], f2[X], preff2[X], a[X], b[X];

int getcnt(int x1, int y1, int x2, int y2) {
    return pref[x2 + 1][y2 + 1] + pref[x1][y1] - pref[x1][y2 + 1] - pref[x2 + 1][y1];
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + (s[i][j] - '0');
        }
    }
    int ans = BIG;
    for (int lx = 0; lx < n; lx++) {
        for (int ly = lx + 4; ly < n; ly++) {
            for (int i = 0; i < m; i++) {
                f1[i] = ly - lx - 1 - getcnt(lx + 1, i, ly - 1, i);
                f2[i] = (int)(s[lx][i] == '0') + (int)(s[ly][i] == '0') + getcnt(lx + 1, i, ly - 1, i);
            }
            preff2[0] = f2[0];
            for (int i = 1; i < m; i++) {
                preff2[i] = preff2[i - 1] + f2[i];
            }
            for (int i = 0; i < m; i++) {
                a[i] = f1[i] - preff2[i];
                if (i > 0) {
                    b[i] = f1[i] + preff2[i - 1];
                }
            }
            int mn = BIG;
            for (int i = 0; i < m; i++) {
                ans = min(ans, b[i] + mn);
                if (i >= 2) {
                    mn = min(mn, a[i - 2]);
                }
            }
        }
    }
    cout << ans << "\n";
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}