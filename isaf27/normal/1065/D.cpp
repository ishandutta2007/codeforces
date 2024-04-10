/*
    Author: isaf27 (Ivan Safonov)
*/

//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0)
#define nul point(0, 0)
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
#define solve_system_scanf int number; scanf("%d", &number); for (int i = 0; i < number; i++) solve()

//permanent constants
const ld pi = acos(-1.0);
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
const ll MOD = 998244353;
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;

//easy functions
template< typename T >
inline T gcd(T a, T b)
{
    while (a)
    {
        b %= a;
        swap(a, b);
    }
    return b;
}
template< typename T >
inline T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }

//random
mt19937 rnd(239);

//constants
const int M = 2 * 1e5 + 239;
const int N = 2 * 1e3 + 239;
const int L = 20;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
const int X = 150;
const int Y = 11;

int n;
pair<int, int> dp[th][X];
pair<int, int> pos[X];
int vx[th][X], vy[th][X], k[X];
pair<int, int> dist[th][Y][Y][th][Y][Y];

bool check(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < n);
}

/*int way(int c, int xs, int ys, int xf, int yf)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = BIG;
    dist[xs][ys] = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(xs, ys));
    while (!q.empty())
    {
        pair<int, int> nw = q.front();
        q.pop();
        int x = nw.first;
        int y = nw.second;
        for (int d = 0; d < k[c]; d++)
        {
            int gx = x + vx[c][d];
            int gy = y + vy[c][d];
            if ()
        }
    }
}*/

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            a--;
            pos[a] = make_pair(i, j);
        }
    k[0] = (4 * n);
    for (int i = 0; i < n; i++)
    {
        vx[0][i] = 0;
        vy[0][i] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        vx[0][i + n] = i + 1;
        vy[0][i + n] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        vx[0][i + 2 * n] = 0;
        vy[0][i + 2 * n] = -(i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        vx[0][i + 3 * n] = -(i + 1);
        vy[0][i + 3 * n] = 0;
    }
    k[1] = (4 * n);
    for (int i = 0; i < n; i++)
    {
        vx[1][i] = i + 1;
        vy[1][i] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        vx[1][i + n] = i + 1;
        vy[1][i + n] = -(i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        vx[1][i + 2 * n] = -(i + 1);
        vy[1][i + 2 * n] = (i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        vx[1][i + 3 * n] = -(i + 1);
        vy[1][i + 3 * n] = -(i + 1);
    }
    k[2] = 8;
    vx[2][0] = 1;
    vx[2][1] = 2;
    vx[2][2] = 2;
    vx[2][3] = 1;
    vx[2][4] = -1;
    vx[2][5] = -2;
    vx[2][6] = -2;
    vx[2][7] = -1;
    vy[2][0] = -2;
    vy[2][1] = -1;
    vy[2][2] = 1;
    vy[2][3] = 2;
    vy[2][4] = 2;
    vy[2][5] = 1;
    vy[2][6] = -1;
    vy[2][7] = -2;
    for (int i = 0; i < 3; i++)
        for (int x1 = 0; x1 < n; x1++)
            for (int y1 = 0; y1 < n; y1++)
    for (int j = 0; j < 3; j++)
        for (int x2 = 0; x2 < n; x2++)
            for (int y2 = 0; y2 < n; y2++)
                dist[i][x1][y1][j][x2][y2] = make_pair(BIG, BIG);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int h = 0; h < 3; h++)
                dist[h][i][j][h][i][j] = make_pair(0, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int h1 = 0; h1 < 3; h1++)
                for (int h2 = 0; h2 < 3; h2++)
                    if (h1 != h2)
                        dist[h1][i][j][h2][i][j] = make_pair(1, 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int h = 0; h < 3; h++)
                for (int d = 0; d < k[h]; d++)
                {
                    int gx = i + vx[h][d];
                    int gy = j + vy[h][d];
                    if (!check(gx, gy)) continue;
                    dist[h][i][j][h][gx][gy] = make_pair(1, 0);
                }
    for (int i = 0; i < 3; i++)
        for (int x1 = 0; x1 < n; x1++)
            for (int y1 = 0; y1 < n; y1++)
    for (int j = 0; j < 3; j++)
        for (int x2 = 0; x2 < n; x2++)
            for (int y2 = 0; y2 < n; y2++)
    for (int h = 0; h < 3; h++)
        for (int x3 = 0; x3 < n; x3++)
            for (int y3 = 0; y3 < n; y3++)
            {
                pair<int, int> now = dist[j][x2][y2][i][x1][y1];
                now.first += dist[i][x1][y1][h][x3][y3].first;
                now.second += dist[i][x1][y1][h][x3][y3].second;
                dist[j][x2][y2][h][x3][y3] = min(now, dist[j][x2][y2][h][x3][y3]);
            }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < n * n; j++)
            dp[i][j] = make_pair(BIG, BIG);
    for (int i = 0; i < 3; i++)
        dp[i][0] = make_pair(0, 0);
    for (int i = 0; i < n * n - 1; i++)
    {
        int xs = pos[i].first;
        int ys = pos[i].second;
        int xf = pos[i + 1].first;
        int yf = pos[i + 1].second;
        for (int t1 = 0; t1 < 3; t1++)
            for (int t2 = 0; t2 < 3; t2++)
            {
                pair<int, int> now = dp[t1][i];
                pair<int, int> ch = dist[t1][xs][ys][t2][xf][yf];
                now.first += ch.first;
                now.second += ch.second;
                dp[t2][i + 1] = min(dp[t2][i + 1], now);
            }
    }
    pair<int, int> ans = make_pair(BIG, BIG);
    for (int i = 0; i < 3; i++)
        ans = min(ans, dp[i][n * n - 1]);
    cout << ans.first << " " << ans.second;
    return 0;
}