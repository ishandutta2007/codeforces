/*
    Author: isaf27 (Ivan Safonov)
*/

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll bt = 30;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const int BIG = 1e9 + 239;
const int MOD = 1e9 + 7; //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //rnd(chrono::high_resolution_clock::now().time_since_epoch().count())

//constants
const int M = 1e6 + 239;
const int N = 2e3 + 239;
const int L = 20;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e4 + 239;

int n, m, kol[M], dp[two][th][th][th];

int32_t main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        kol[x + 2]++;
    }
    m += 3;
    memset(dp, -1, sizeof(dp));
    dp[0][0][0][0] = 0;
    for (int i = 3; i < m; i++)
        for (int t1 = 0; t1 <= 2; t1++)
            for (int t2 = 0; t2 <= 2; t2++)
                for (int t3 = 0; t3 <= 2; t3++)
                {
                    dp[i & 1][t1][t2][t3] = -1;
                    if (t1 + t2 + t3 > kol[i]) continue;
                    if (t3 + t2 > kol[i - 1]) continue;
                    if (t3 > kol[i - 2]) continue;
                    for (int pr = 0; pr <= 2; pr++)
                        if (dp[(i + 1) & 1][t2][t3][pr] != -1)
                            dp[i & 1][t1][t2][t3] = max(dp[i & 1][t1][t2][t3], dp[(i + 1) & 1][t2][t3][pr] + ((kol[i] - t1 - t2 - t3) / 3) + t1);
                }
    int ans = 0;
    for (int t3 = 0; t3 <= 2; t3++)
        ans = max(ans, dp[(m - 1) & 1][0][0][t3]);
    cout << ans;
    return 0;
}