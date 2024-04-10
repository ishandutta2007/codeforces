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
const int X = 1010;
 
int n, p[M], dp[X][X], m;
int has[X], cur, al[X], s[X];
 
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
    vector<int> st;
    for (int i = 0; i < m; i++)
        if (i == 0 || p[i] != p[i - 1])
            st.push_back(p[i]);
    m = st.size();
    if (m > 2 * n)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < m; i++)
        p[i] = st[i];
    for (int l = 1; l <= m; l++)
        for (int i = 0; i <= m - l; i++)
        {
            cur++;
            int j = i + l - 1;
            int x = i;
            for (int h = i + 1; h <= j; h++)
                if (p[h] < p[x])
                    x = h;
            dp[i][j] = 1;
            int y = x;
            for (int h = x + 1; h <= j; h++)
                if (p[h] == p[x])
                {
                    if (y + 1 <= h - 1)
                        dp[i][j] = 1LL * dp[i][j] * dp[y + 1][h - 1] % MOD;
                    y = h;
                }
            for (int h = x; h <= y; h++)
                has[p[h]] = cur;
            bool bad = false;
            for (int h = i; h < x && !bad; h++)
                if (has[p[h]] == cur)
                    bad = true;
            for (int h = y + 1; h <= j && !bad; h++)
                if (has[p[h]] == cur)
                    bad = true;
            if (bad)
            {
                dp[i][j] = 0;
                continue;
            }
            cur++;
            for (int h = i; h < x; h++)
                has[p[h]] = cur;
            for (int h = y + 1; h <= j && !bad; h++)
                if (has[p[h]] == cur)
                    bad = true;
            if (bad)
            {
                dp[i][j] = 0;
                continue;
            }
            int sl = 1;
            int sr = 1;
            if (x > i)
            {
                sl = 2 * dp[i][x - 1];
                if (sl >= MOD)
                    sl -= MOD;
                for (int h = i; h < x; h++)
                {
                    s[p[h]] = 0;
                    al[p[h]] = 0;
                }
                for (int h = i; h < x; h++)
                    al[p[h]]++;
                int wrong = 0;
                for (int h = i + 1; h < x; h++)
                {
                    if (0 < s[p[h - 1]] && s[p[h - 1]] < al[p[h - 1]])
                        wrong--;
                    s[p[h - 1]]++;
                    if (0 < s[p[h - 1]] && s[p[h - 1]] < al[p[h - 1]])
                        wrong++;
                    if (wrong == 0)
                    {
                        sl += 1LL * dp[i][h - 1] * dp[h][x - 1] % MOD;
                        if (sl >= MOD)
                            sl -= MOD;
                    }
                }
            }
            if (y < j)
            {
                sr = 2 * dp[y + 1][j];
                if (sr >= MOD)
                    sr -= MOD;
                for (int h = y + 1; h <= j; h++)
                {
                    s[p[h]] = 0;
                    al[p[h]] = 0;
                }
                for (int h = y + 1; h <= j; h++)
                    al[p[h]]++;
                int wrong = 0;
                for (int h = y + 2; h <= j; h++)
                {
                    if (0 < s[p[h - 1]] && s[p[h - 1]] < al[p[h - 1]])
                        wrong--;
                    s[p[h - 1]]++;
                    if (0 < s[p[h - 1]] && s[p[h - 1]] < al[p[h - 1]])
                        wrong++;
                    if (wrong == 0)
                    {
                        sr += 1LL * dp[y + 1][h - 1] * dp[h][j] % MOD;
                        if (sr >= MOD)
                            sr -= MOD;
                    }
                }
            }
            dp[i][j] = 1LL * dp[i][j] * sl % MOD;
            dp[i][j] = 1LL * dp[i][j] * sr % MOD;
        }
    cout << dp[0][m - 1];
    return 0;
}