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
const ll INF = (ll)(4e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 31607; //1e9 + 7;
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
const int B = 510;
const int X = 25;

inline int sum(int a, int b) {
    return (a + b) % MOD;
}

inline int mul(int a, int b) {
    return 1LL * a * b % MOD;
}

inline int power(int a, int k) {
    if (k == 0) {
        return 1;
    }
    int t = power(a, k / 2);
    t = mul(t, t);
    if (k & 1) {
        t = mul(t, a);
    }
    return t;
}

int n, a[X][X], b[X][X], c[X][X];
int col[X], row[X], f[X];

int func() {
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cerr << b[i][j] << " ";
        }
        cerr << "\n";
    }*/
    int ans = 0;
    for (int i = 0; i < n; i++) {
        col[i] = MOD - 1;
        row[i] = MOD - 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = power(b[i][j], MOD - 2);
            col[j] = mul(col[j], b[i][j]);
            row[i] = mul(row[i], b[i][j]);
        }
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            f[i] = row[i];
        }
        int cur = 1;
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                cur = mul(cur, col[i]);
                for (int j = 0; j < n; j++) {
                    f[j] = mul(f[j], c[j][i]);
                }
            }
        }
        if (cur != 0) {
            for (int i = 0; i < n; i++) {
                cur = mul(cur, sum(f[i], 1));
            }
            ans = sum(ans, cur);
        }
    }
    return ans;
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int inv = power(10000, MOD - 2);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j] = mul(a[i][j], inv);
        }
    }
    int ans = 0;
    for (int d = 0; d < 4; d++) {
        int prod = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                b[i][j] = a[i][j];
            }
        }
        for (int t = 0; t < 2; t++) {
            if ((d >> t) & 1) {
                prod = (MOD - prod) % MOD;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (t == 0 && i == j) {
                            prod = mul(prod, b[i][j]);
                            b[i][j] = 1;
                        }
                        if (t == 1 && i + j == n - 1) {
                            prod = mul(prod, b[i][j]);
                            b[i][j] = 1;
                        }
                    }
                }
            }
        }
        ans = sum(ans, mul(prod, func()));
    }
    cout << (MOD + 1 - ans) % MOD << "\n";
    return 0;
}