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
const ll INF = (ll)(2e18 + 239);
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
const int M = (int)(1e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 13) + 239;
const int B = 510;
const int X = 60;

int r, n, t[M], x[M], y[M], dp[M], pref[M];

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> x[i] >> y[i];
        x[i]--, y[i]--;
    }
    pref[0] = -BIG;
    for (int i = 0; i < n; i++) {
        dp[i] = -BIG;
        if (abs(x[i]) + abs(y[i]) <= t[i]) {
            dp[i] = 1;
        }
        for (int j = i - 1; j >= 0; j--) {
            if (t[j] <= t[i] - 2 * r) {
                dp[i] = max(dp[i], pref[j + 1] + 1);
                break;
            }
            if (abs(x[i] - x[j]) + abs(y[i] - y[j]) + t[j] <= t[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        pref[i + 1] = max(pref[i], dp[i]);
    }
    if (pref[n] == -BIG) {
        pref[n] = 0;
    }
    cout << pref[n] << "\n";
    return 0;
}