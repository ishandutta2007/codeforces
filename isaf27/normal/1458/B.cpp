//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
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
const int two = 2;
const ld eps = 1e-10;
const ll INF = (ll)(2e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353;
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
const int L = 20;
const int T = (1 << 18) + 239;
const int B = 510;
const int X = 110;
const int S = X * X;

int dp[2][X][S];
int n, b[X], a[X];

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int t = 0; t < 2; t++) {
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < S; j++) {
                dp[t][i][j] = -BIG;
            }
        }
    }
    dp[0][0][0] = 0;
    for (int t = 0; t < n; t++) {
        int from = t & 1;
        int to = (t + 1) & 1;
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < S; j++) {
                dp[to][i][j] = -BIG;
            }
        }
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < S; j++) {
                if (dp[from][i][j] != -BIG) {
                    dp[to][i][j] = max(dp[to][i][j], dp[from][i][j] + b[t]);
                    dp[to][i + 1][j + a[t]] = max(dp[to][i + 1][j + a[t]], dp[from][i][j] + 2 * b[t]);
                }
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        int ans = 0;
        for (int s = 0; s < S; s++) {
            if (dp[n & 1][k][s] != -BIG) {
                ans = max(ans, min(2 * s, dp[n & 1][k][s]));
            }
        }
        if (ans % 2 == 0) {
            cout << (ans / 2) << " ";
        } else {
            cout << (ans / 2) << ".5 ";
        }
    }
    cout << "\n";
    return 0;
}