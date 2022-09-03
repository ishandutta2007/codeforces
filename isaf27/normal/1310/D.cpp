//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
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
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll btc = 30;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 1e9 + 7; //

//random
//mt19937 rnd(239);
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)((1 << 17) + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 88;
const int TM = 11;

int a[X][X], dp[TM][X], n, k, color[X];
vector<int> in[two];

int solve()
{
    in[0].clear();
    in[1].clear();
    for (int i = 0; i < n; i++)
        in[color[i]].push_back(i);
    for (int i = 0; i < n; i++)
        dp[0][i] = BIG;
    dp[0][0] = 0;
    for (int t = 1; t <= k; t++)
        for (int i = 0; i < n; i++)
        {
            dp[t][i] = BIG;
            for (int j : in[1 - color[i]])
                dp[t][i] = min(dp[t][i], dp[t - 1][j] + a[j][i]);
        }
    return dp[k][0];
}

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    int ans = BIG;
    while (TIME < 2.7)
    {
        for (int i = 0; i < n; i++)
            color[i] = rnd() % 2;
        ans = min(ans, solve());
    }
    cout << ans << "\n";
    return 0;
}