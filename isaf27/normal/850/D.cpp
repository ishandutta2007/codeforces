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
const ll btc = 30;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const ll MOD = (int)(1e9 + 7); //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 19);
const int B = 500;

const int X = 35;
const int Y = 70;
const int S = X * Y;

int m, a[X];
bool dp[X][Y][S], pr[X][Y][S];

vector<int> d;

void gen(int i, int j, int s)
{
    if (j == 0)
        return;
    d.push_back(a[i]);
    if (pr[i][j][s])
        gen(i - 1, j - 1, s - a[i]);
    else
        gen(i, j - 1, s - a[i]);
}

int mt[Y][Y];

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    sort(a, a + m);
    dp[0][1][a[0]] = true;
    for (int i = 0; i < m; i++)
        for (int j = 1; j < Y; j++)
            for (int s = a[i]; s < S; s++)
            {
                if (s < (j * (j - 1)) / 2)
                    continue;
                if (dp[i][j - 1][s - a[i]])
                {
                    dp[i][j][s] = true;
                    pr[i][j][s] = false;
                }
                if (i > 0 && dp[i - 1][j - 1][s - a[i]])
                {
                    dp[i][j][s] = true;
                    pr[i][j][s] = true;
                }
            }
    int cn = -1;
    for (int n = 1; n < Y; n++)
    {
        if (((n * (n - 1)) / 2) >= S)
            continue;
        if (dp[m - 1][n][(n * (n - 1) / 2)])
        {
            cn = n;
            break;
        }
    }
    if (cn == -1)
    {
        cout << "=(";
        return 0;
    }
    int n = cn;
    gen(m - 1, n, (n * (n - 1)) / 2);
    reverse(d.begin(), d.end());
    vector<pair<int, int>> pr;
    for (int i = 0; i < n; i++)
        pr.push_back(make_pair(d[i], i));
    memset(mt, -1, sizeof(mt));
    for (int i = 0; i < n; i++)
        mt[i][i] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        sort(pr.begin(), pr.end());
        int p = pr.back().second;
        int d = i - pr.back().first;
        pr.pop_back();
        for (int i = (int)pr.size() - 1; i >= (int)pr.size() - d; i--)
        {
            mt[pr[i].second][p] = 1;
            mt[p][pr[i].second] = 0;
            pr[i].first--;
        }
        for (int i = (int)pr.size() - d - 1; i >= 0; i--)
        {
            mt[pr[i].second][p] = 0;
            mt[p][pr[i].second] = 1;
        }
    }
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << mt[i][j];
        cout << "\n";
    }
    /*for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mt[i][j])
                cout << i + 1 << " " << j + 1 << "\n";*/
    return 0;
}