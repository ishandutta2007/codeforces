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
//const int MOD = 998244353; //1e9 + 7;
//const ll MOD2 = (ll)MOD * (ll)MOD;

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
const int X = 4e6 + 10;

int MOD;

inline int sum(int a, int b) {
    a += b - MOD;
    a += (a >> 31) & MOD;
    return a;
}

inline int sub(int a, int b) {
    a -= b;
    a += (a >> 31) & MOD;
    return a;
}

int n, dp[X], mnp[X];
//vector<int> d[X];

int lst[B], k;

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> MOD;
    for (int i = 1; i <= n; i++) {
        mnp[i] = -1;
    }
    for (int i = 2; i <= n; i++) {
        if (mnp[i] == -1) {
            for (int j = i; j <= n; j += i) {
                if (mnp[j] == -1) {
                    mnp[j] = i;
                }
            }
        }
    }
    /*for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            d[j].emplace_back(i);
        }
    }*/
    dp[1] = 1;
    int tot = 1;
    int val = 0;
    for (int x = 2; x <= n; x++) {
        int k = 1;
        lst[0] = 1;
        int xx = x;
        while (xx > 1) {
            int p = mnp[xx];
            int ik = k;
            while (xx % p == 0) {
                xx /= p;
                for (int i = k; i < k + ik; i++) {
                    lst[i] = lst[i - ik] * p;
                }
                k += ik;
            }
        }
        for (int i = 0; i < k; i++) {
            int z = lst[i];
            if (z == 1) {
                continue;
            }
            if (z != x) {
                val = sub(val, dp[(x - 1) / z]);
            }
            val = sum(val, dp[x / z]);
        }
        dp[x] = sum(val, tot);
        tot = sum(tot, dp[x]);
    }
    cout << dp[n] << "\n";
    return 0;
}