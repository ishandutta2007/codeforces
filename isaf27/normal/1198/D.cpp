//#pragma GCC optimize("O3")
#ifdef ONPC
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
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
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(5e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 19);
const int B = (int)sqrt(M);
const int X = 55;

int n, pref[X][X], dp[X][X][X][X];
string a[X];

bool check(int x1, int y1, int x2, int y2)
{
    return pref[x1][y1] + pref[x2 + 1][y2 + 1] == pref[x1][y2 + 1] + pref[x2 + 1][y1];
}

int func(int x1, int y1, int x2, int y2)
{
    if (check(x1, y1, x2, y2))
        return 0;
    if (dp[x1][y1][x2][y2] != -1)
        return dp[x1][y1][x2][y2];
    dp[x1][y1][x2][y2] = max(x2 - x1, y2 - y1) + 1;
    if (x2 - x1 >= y2 - y1)
    {
        for (int i = x1; i < x2; i++)
            dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], func(x1, y1, i, y2) + func(i + 1, y1, x2, y2));
        return dp[x1][y1][x2][y2];
    }
    else
    {
        for (int i = y1; i < y2; i++)
            dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], func(x1, y1, x2, i) + func(x1, i + 1, x2, y2));
        return dp[x1][y1][x2][y2];
    }
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + (a[i][j] == '#');
    memset(dp, -1, sizeof(dp));
    cout << func(0, 0, n - 1, n - 1);
    return 0;
}