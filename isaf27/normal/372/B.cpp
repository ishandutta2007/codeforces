#pragma GCC optimize("O3")
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
const ld eps = 1e-9;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(2e9 + 239);
const int MOD = 998244353; //1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(5e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 18);
const int B = (int)sqrt(M);
const int X = 42;

int n, m, q;
string s[X];
int dp[X][X][X][X], pref[X][X][X][X];

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int x = 0; x < n; x++)
        for (int y = 0; y < m; y++)
        {
            for (int i = x; i < n; i++)
                for (int j = y; j < m; j++)
                {
                    dp[x][y][i][j] = 1 - (s[i][j] - '0');
                    if (x < i && dp[x][y][i - 1][j] == 0)
                        dp[x][y][i][j] = 0;
                    if (y < j && dp[x][y][i][j - 1] == 0)
                        dp[x][y][i][j] = 0;
                }
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    pref[x][y][i + 1][j + 1] = dp[x][y][i][j] + pref[x][y][i + 1][j] + pref[x][y][i][j + 1] - pref[x][y][i][j];
        }
    for (int i = 0; i < q; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        int ans = 0;
        for (int x = a; x <= c; x++)
            for (int y = b; y <= d; y++)
                ans += pref[x][y][c + 1][d + 1];
        cout << ans << "\n";
    }
    return 0;
}