#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev

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
const ll bt = 31;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353; //1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(1e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 18);
const int B = (int)(trunc(sqrt(M)) + 1);
const int X = 255;
const int A = 26;

int dp[X][X][X], n, q;
string s, t[th];
int go[A][M];

void upd(int id)
{
    int p = t[id].size();
    int cur = t[id][p - 1] - 'a';
    if (id == 0)
    {
        for (int i = 0; i <= t[1].size(); i++)
            for (int j = 0; j <= t[2].size(); j++)
            {
                dp[p][i][j] = go[cur][dp[p - 1][i][j]];
                if (i > 0)
                    dp[p][i][j] = min(dp[p][i][j], go[t[1][i - 1] - 'a'][dp[p][i - 1][j]]);
                if (j > 0)
                    dp[p][i][j] = min(dp[p][i][j], go[t[2][j - 1] - 'a'][dp[p][i][j - 1]]);
            }
    }
    else if (id == 1)
    {
        for (int i = 0; i <= t[0].size(); i++)
            for (int j = 0; j <= t[2].size(); j++)
            {
                dp[i][p][j] = go[cur][dp[i][p - 1][j]];
                if (i > 0)
                    dp[i][p][j] = min(dp[i][p][j], go[t[0][i - 1] - 'a'][dp[i - 1][p][j]]);
                if (j > 0)
                    dp[i][p][j] = min(dp[i][p][j], go[t[2][j - 1] - 'a'][dp[i][p][j - 1]]);
            }
    }
    else
    {
        for (int i = 0; i <= t[0].size(); i++)
            for (int j = 0; j <= t[1].size(); j++)
            {
                dp[i][j][p] = go[cur][dp[i][j][p - 1]];
                if (i > 0)
                    dp[i][j][p] = min(dp[i][j][p], go[t[0][i - 1] - 'a'][dp[i - 1][j][p]]);
                if (j > 0)
                    dp[i][j][p] = min(dp[i][j][p], go[t[1][j - 1] - 'a'][dp[i][j - 1][p]]);
            }
    }
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q >> s;
    for (int i = 0; i < A; i++)
    {
        go[i][n] = n + 1;
        go[i][n + 1] = n + 1;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int x = 0; x < A; x++)
            go[x][i] = go[x][i + 1];
        go[s[i] - 'a'][i] = i + 1;
    }
    dp[0][0][0] = 0;
    t[0] = t[1] = t[2] = "";
    for (int it = 0; it < q; it++)
    {
        char type;
        cin >> type;
        if (type == '-')
        {
            int x;
            cin >> x;
            x--;
            t[x] = t[x].substr(0, (int)t[x].size() - 1);
        }
        else if (type == '+')
        {
            char p;
            int x;
            cin >> x >> p;
            x--;
            t[x] += p;
            upd(x);
        }
        cout << (dp[t[0].size()][t[1].size()][t[2].size()] <= n ? "YES\n" : "NO\n");
    }
    return 0;
}