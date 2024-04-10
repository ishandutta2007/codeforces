#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 y00

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll bt = 30;
const ld eps = 1e-7;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(2e9 + 239);
const int MOD = 998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(1e5 + 239);
const int N = (int)(1e3 + 239);
const int L = 20;
const int T = (1 << 20);
const int B = (int)sqrt(M);
const int X = 1e4 + 239;

int n, k, a[N], pos[N], dp[N][N];

int getfunc(int r)
{
    for (int i = 0; i < n; i++)
        pos[i] = upper_bound(a, a + n, a[i] - r) - a;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        dp[i + 1][0] = 1;
        for (int j = 1; j <= min(k, i + 1); j++)
        {
            dp[i + 1][j] = dp[i][j];
            dp[i + 1][j] += dp[pos[i]][j - 1];
            if (dp[i + 1][j] >= MOD) dp[i + 1][j] -= MOD;
        }
    }
    return dp[n][k];
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    for (int r = 1; r * (k - 1) <= a[n - 1] && r <= a[n - 1]; r++)
    {
        ans += getfunc(r);
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans;
    return 0;
}