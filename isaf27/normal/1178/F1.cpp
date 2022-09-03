//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

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
const int M = (int)(1e6 + 239);
const int N = (int)(1e3 + 239);
const int L = 18;
const int T = (1 << 20);
const int B = (int)sqrt(M);
const int X = 510;

int n, p[M], dp[X][X], m;

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> p[i];
        p[i]--;
    }
    for (int l = 1; l <= n; l++)
        for (int i = 0; i <= n - l; i++)
        {
            int j = i + l - 1;
            int x = i;
            for (int h = i + 1; h <= j; h++)
                if (p[h] < p[x])
                    x = h;
            int sl = 1;
            int sr = 1;
            if (x > i)
            {
                sl = 2 * dp[i][x - 1];
                if (sl >= MOD)
                    sl -= MOD;
                for (int h = i + 1; h < x; h++)
                {
                    sl += 1LL * dp[i][h - 1] * dp[h][x - 1] % MOD;
                    if (sl >= MOD)
                        sl -= MOD;
                }
            }
            if (x < j)
            {
                sr = 2 * dp[x + 1][j];
                if (sr >= MOD)
                    sr -= MOD;
                for (int h = x + 2; h <= j; h++)
                {
                    sr += 1LL * dp[x + 1][h - 1] * dp[h][j] % MOD;
                    if (sr >= MOD)
                        sr -= MOD;
                }
            }
            //cerr << i + 1 << " " << j + 1 << " " << sl << " " << sr << "\n";
            dp[i][j] = 1LL * sl * sr % MOD;
        }
    cout << dp[0][m - 1];
    return 0;
}