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
const ll bt = 31;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const int BIG = 2e9 + 239;
const int MOD = 1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = 1e5 + 239;
const int N = 2e3 + 239;
const int L = 19;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e4 + 239;
const int D = 10;

int kol[D][M], dp[D][M], n, from[M];
string to[M];
string s;

int32_t main()
{
    #ifdef ONPC
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s >> n;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        from[i] = t[0] - '0';
        to[i] = "";
        for (int x = 3; x < (int)t.size(); x++)
            to[i] += t[x];
    }
    for (int i = 0; i < D; i++)
    {
        dp[i][n] = i;
        kol[i][n] = 10;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int d = 0; d < D; d++)
        {
            kol[d][i] = kol[d][i + 1];
            dp[d][i] = dp[d][i + 1];
        }
        int d = from[i];
        dp[d][i] = 0;
        kol[d][i] = 1;
        for (int x = (int)to[i].size() - 1; x >= 0; x--)
        {
            dp[d][i] += 1LL * dp[to[i][x] - '0'][i + 1] * kol[d][i] % MOD;
            if (dp[d][i] >= MOD) dp[d][i] -= MOD;
            kol[d][i] = 1LL * kol[d][i] * kol[to[i][x] - '0'][i + 1] % MOD;
        }
    }
    int ans = 0;
    int len = 1;
    for (int x = (int)s.size() - 1; x >= 0; x--)
    {
        ans += 1LL * dp[s[x] - '0'][0] * len % MOD;
        if (ans >= MOD) ans -= MOD;
        len = 1LL * len * kol[s[x] - '0'][0] % MOD;
    }
    cout << ans;
    return 0;
}