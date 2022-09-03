//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 _y0

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
const int MOD = (int)(1e9 + 7); //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(3e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 19;
const int T = (1 << 19);
const int B = 500;
const int X = 2e4 + 239;
const int fr = 4;

int n, a[M], dp[2][L][M], how[M], ans[M];

int getmax(int l, int r)
{
    int len = r - l + 1;
    int u = how[len];
    int mx = max(dp[1][u][l], dp[1][u][r - (1 << u) + 1]);
    return mx;
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
    int mn = (int)(1e9);
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    if (2 * mn >= mx)
    {
        for (int i = 0; i < n; i++)
            cout << "-1 ";
        return 0;
    }
    for (int i = 0; i < 2 * n; i++)
        a[i + n] = a[i];
    how[1] = 0;
    for (int i = 2; i <= 3 * n; i++)
    {
        how[i] = how[i - 1] + 1;
        if ((1 << how[i]) > i)
            how[i]--;
    }
    for (int i = 0; i < 3 * n; i++)
    {
        dp[0][0][i] = a[i];
        dp[1][0][i] = a[i];
    }
    for (int c = 0; c < 2; c++)
        for (int k = 1; k < L; k++)
            for (int i = 0; i < 3 * n; i++)
            {
                int t = (i + (1 << (k - 1)));
                if (t >= 2 * n)
                {
                    dp[0][k][i] = dp[0][k - 1][i];
                    dp[1][k][i] = dp[1][k - 1][i];
                    continue;
                }
                dp[0][k][i] = min(dp[0][k - 1][i], dp[0][k - 1][t]);
                dp[1][k][i] = max(dp[1][k - 1][i], dp[1][k - 1][t]);
            }
    for (int i = 0; i < 3 * n; i++)
        ans[i] = 3 * n;
    for (int i = 0; i < 3 * n; i++)
    {
        if (getmax(0, i) <= 2 * a[i])
            continue;
        int l = 0;
        int r = i;
        while (r - l > 1)
        {
            int h = (l + r) >> 1;
            if (getmax(h, i) <= 2 * a[i])
                r = h;
            else
                l = h;
        }
        ans[l] = min(ans[l], i);
    }
    for (int i = 3 * n - 2; i >= 0; i--)
        ans[i] = min(ans[i], ans[i + 1]);
    for (int i = 0; i < n; i++)
        cout << ans[i] - i << " ";
    return 0;
}