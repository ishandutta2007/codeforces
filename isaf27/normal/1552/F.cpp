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
const int MOD = 998244353; //1e9 + 7;
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
const int X = 1e4 + 239;

int n;
int x[M], y[M], s[M];

int sum(int a, int b) {
    return (a + b) % MOD;
}

int sub(int a, int b) {
    return sum(a, MOD - b);
}

int mul(int a, int b) {
    return 1LL * a * b % MOD;
}

int dp[M], f[M], pref[M];

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> s[i];
    }
    pref[0] = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (s[i] == 0) {
                dp[i] = sum(x[0] % MOD, 1);
            } else {
                dp[i] = sum(x[0] % MOD, sub((x[0] + 1) % MOD, y[0] % MOD));
            }
            f[i] = sub(x[0] % MOD, y[0] % MOD);
            pref[i + 1] = sum(pref[i], f[i]);
            continue;
        }
        int l = lower_bound(x, x + n, y[i]) - x;
        f[i] = sum(sub(x[i] % MOD, y[i] % MOD), sub(pref[i], pref[l]));
        pref[i + 1] = sum(pref[i], f[i]);
        dp[i] = sum(dp[i - 1], sub(x[i] % MOD, x[i - 1] % MOD));
        if (s[i] == 0) {
            continue;
        }
        dp[i] = sum(dp[i], f[i]);
    }
    cout << dp[n - 1] << "\n";
    return 0;
}