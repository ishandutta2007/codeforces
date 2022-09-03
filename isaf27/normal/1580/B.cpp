#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const int X = 110;

int n, m, k, p;

inline int sum(int a, int b) {
    a += b - p;
    a += (a >> 31) & p;
    return a;
}

inline int mul(int a, int b) {
    return 1LL * a * b % p;
}

int c[X][X];
int dp[X][X][X];
int fact[X];

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >> k >> p;
    if (m + k > n + 1) {
        cout << "0\n";
        return 0;
    }
    for (int i = 0; i <= n; i++) {
        c[i][0] = 1;
    }
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
    for (int j = 1; j <= n; j++) {
        for (int i = j; i <= n; i++) {
            c[i][j] = sum(c[i - 1][j], c[i - 1][j - 1]);
        }
    }
    memset(dp, 0, sizeof(dp));
    for (int mm = 0; mm <= n; mm++) {
        dp[mm][0][0] = 1;
    }
    ll p2 = (ll)p * p;
    for (int mm = 1; mm <= m; mm++) {
        for (int nn = 1; nn <= n; nn++) {
            for (int kk = 0; kk <= min(nn, k); kk++) {
                if (mm + kk > nn + 1 && kk != 0) {
                    dp[mm][nn][kk] = 0;
                    continue;
                }
                if (mm == 1) {
                    if (kk == 1) {
                        dp[mm][nn][kk] = fact[nn];
                    } else {
                        dp[mm][nn][kk] = 0;
                    }
                    continue;
                }
                for (int i = 0; i < nn; i++) {
                    int cur = c[nn - 1][i];
                    ll s = 0;
                    for (int x = 0; x <= kk; x++) {
                        s += 1LL * dp[mm - 1][i][x] * dp[mm - 1][nn - 1 - i][kk - x] - p2;
                        s += (s >> 63LL) & p2;
                    }
                    cur = mul(cur, s % p);
                    dp[mm][nn][kk] = sum(dp[mm][nn][kk], cur);
                }
            }
        }
    }
    cout << dp[m][n][k] << "\n";
    cerr << TIME << "\n";
    return 0;
}