//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 _y0

//#define int ll

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
const int MOD = 998244353; //(int)(1e9 + 7);
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(1e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 19);
const int B = 500;
const int X = 3610;
const int fr = 4;

int dp[X][X];

vector<int> func(vector<bool> s)
{
    int n = s.size();
    for (int i = 0; i <= n; i++)
        dp[0][i] = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= (n / 2); j++)
            dp[i][j] = dp[i - 1][j];
        if (i > 1 && !s[i - 1] && !s[i - 2])
        {
            for (int j = 1; j <= (n / 2); j++)
            {
                dp[i][j] += dp[i - 2][j - 1];
                if (dp[i][j] >= MOD)
                    dp[i][j] -= MOD;
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i <= (n / 2); i++)
        ans.push_back(dp[n][i]);
    return ans;
}

int n, m, k, c[X][X], xs, ys, fact[X];
vector<bool> z1, z2;

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < X; i++)
        c[i][0] = 1;
    for (int i = 1; i < X; i++)
        for (int j = 1; j < X; j++)
        {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            if (c[i][j] >= MOD)
                c[i][j] -= MOD;
        }
    fact[0] = 1;
    for (int i = 1; i < X; i++)
        fact[i] = 1LL * fact[i - 1] * i % MOD;
    cin >> n >> m >> k;
    z1.assign(n, false);
    z2.assign(m, false);
    for (int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        z1[x1] = true;
        z1[x2] = true;
        z2[y1] = true;
        z2[y2] = true;
    }
    vector<int> s1 = func(z1);
    vector<int> s2 = func(z2);
    xs = 0;
    for (int i = 0; i < z2.size(); i++)
        xs += (int)z2[i];
    ys = 0;
    for (int i = 0; i < z1.size(); i++)
        ys += (int)z1[i];
    int ans = 0;
    for (int x = 0; x <= s1.size(); x++)
        for (int y = 0; y <= s2.size(); y++)
            if (s1[x] != 0 && s2[y] != 0)
            {
                int c1 = 0;
                if (m - xs - 2 * y >= 0)
                    c1 = c[m - xs - 2 * y][x];
                int c2 = 0;
                if (n - ys - 2 * x >= 0)
                    c2 = c[n - ys - 2 * x][y];
                c1 = 1LL * c1 * s1[x] % MOD;
                c1 = 1LL * c1 * fact[x] % MOD;
                c2 = 1LL * c2 * s2[y] % MOD;
                c2 = 1LL * c2 * fact[y] % MOD;
                ans += 1LL * c1 * c2 % MOD;
                if (ans >= MOD)
                    ans -= MOD;
            }
    cout << ans;
    return 0;
}