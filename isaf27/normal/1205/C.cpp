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
#define y1 y11
#define int ll

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dxk[8] = {-1, -2, -1, 2, -2, 1, 1, 2};
const int dyk[8] = {-2, -1, 2, -1, 1, -2, 2, 1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll bt = 30;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (1e9 + 239);
const int MOD = 998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(1e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 19);
const int B = (int)sqrt(M);
const int X = 55;

int n;
int dp[two][X][X][X][X];
int b[two][X][X];

int comp(int c, int x1, int y1, int x2, int y2)
{
    if (dp[c][x1][y1][x2][y2] != -1)
        return dp[c][x1][y1][x2][y2];
    if (x1 == y1 && x2 == y2)
    {
        dp[c][x1][y1][x2][y2] = 1;
        return 1;
    }
    if (x2 - x1 + y2 - y1 == 1)
    {
        dp[c][x1][y1][x2][y2] = (b[c][x1][y1] == b[c][x2][y2]);
        return dp[c][x1][y1][x2][y2];
    }
    if (b[c][x1][y1] != b[c][x2][y2])
    {
        dp[c][x1][y1][x2][y2] = 0;
        return 0;
    }
    vector<pair<int, int>> t1;
    if (x1 + 1 <= x2)
        t1.push_back(make_pair(x1 + 1, y1));
    if (y1 + 1 <= y2)
        t1.push_back(make_pair(x1, y1 + 1));
    vector<pair<int, int>> t2;
    if (x1 <= x2 - 1)
        t2.push_back(make_pair(x2 - 1, y2));
    if (y1 <= y2 - 1)
        t2.push_back(make_pair(x2, y2 - 1));
    for (pair<int, int> a : t1)
        for (pair<int, int> b : t2)
            if (a.first <= b.first && a.second <= b.second)
                if (comp(c, a.first, a.second, b.first, b.second))
                {
                    dp[c][x1][y1][x2][y2] = 1;
                    return 1;
                }
    dp[c][x1][y1][x2][y2] = 0;
    return 0;
}

int ans[X][X];

bool ask(int x1, int y1, int x2, int y2)
{
    cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << endl;
    string ans;
    cin >> ans;
    if (ans == "-1") exit(0);
    return (ans == "1");
}

void finish(int c)
{
    cout << "!" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << b[c][i][j];
        cout << endl;
    }
    exit(0);
}

int32_t main() {
#ifdef ONPC
    //freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    memset(ans, -1, sizeof(ans));
    ans[0][0] = 1;
    ans[n - 1][n - 1] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((i + j) % 2 == 0 && ans[i][j] == -1)
            {
                bool now;
                if (i >= 1 && j >= 1)
                {
                    now = ask(i - 1, j - 1, i, j);
                    ans[i][j] = ans[i - 1][j - 1];
                }
                else if (j > 0)
                {
                    now = ask(i, j - 2, i, j);
                    ans[i][j] = ans[i][j - 2];
                }
                else
                {
                    now = ask(i - 2, j, i, j);
                    ans[i][j] = ans[i - 2][j];
                }
                if (!now)
                    ans[i][j] = 1 - ans[i][j];
            }
    ans[1][0] = 0;
    bool now = ask(1, 0, 1, 2);
    ans[1][2] = ans[1][0];
    if (!now)
        ans[1][2] = 1 - ans[1][2];
    now = ask(0, 1, 1, 2);
    ans[0][1] = ans[1][2];
    if (!now)
        ans[0][1] = 1 - ans[0][1];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((i + j) % 2 == 1 && ans[i][j] == -1)
            {
                bool now;
                if (i >= 1 && j >= 1)
                {
                    now = ask(i - 1, j - 1, i, j);
                    ans[i][j] = ans[i - 1][j - 1];
                }
                else if (j > 0)
                {
                    now = ask(i, j - 2, i, j);
                    ans[i][j] = ans[i][j - 2];
                }
                else
                {
                    now = ask(i - 2, j, i, j);
                    ans[i][j] = ans[i - 2][j];
                }
                if (!now)
                    ans[i][j] = 1 - ans[i][j];
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            b[0][i][j] = ans[i][j];
            b[1][i][j] = ans[i][j];
            if ((i + j) % 2 == 1)
                b[1][i][j] = 1 - b[1][i][j];
        }
    memset(dp, -1, sizeof(dp));
    for (int x1 = 0; x1 < n; x1++)
        for (int x2 = x1; x2 < n; x2++)
            for (int y1 = 0; y1 < n; y1++)
                for (int y2 = y1; y2 < n; y2++)
                    if (x2 - x1 + y2 - y1 > 1 && comp(0, x1, y1, x2, y2) != comp(1, x1, y1, x2, y2))
                    {
                        int now = ask(x1, y1, x2, y2);
                        if (now == dp[0][x1][y1][x2][y2])
                            finish(0);
                        else
                            finish(1);
                    }
    return 0;
}