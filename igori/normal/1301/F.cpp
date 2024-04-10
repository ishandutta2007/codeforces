#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <random>
#include <functional>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::map;
using std::set;
using std::bitset;
using std::vector;
using std::string;
using std::multimap;
using std::multiset;
using std::deque;
using std::queue;
using std::stack;
using std::pair;
using std::iterator;

using std::sort;
using std::stable_sort;
using std::reverse;
using std::max_element;
using std::min_element;
using std::unique;
using std::ios_base;
using std::swap;
using std::fill;

using std::setprecision;
using std::fixed;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

ll min(ll a, ll b) {return a < b ? a : b;}
ll min(int a, ll b) {return a < b ? a : b;}
ll min(ll a, int b) {return a < b ? a : b;}
ll min(int a, int b) {return a < b ? a : b;}

ll max(ll a, ll b) {return a > b ? a : b;}
ll max(int a, ll b) {return a > b ? a : b;}
ll max(ll a, int b) {return a > b ? a : b;}
ll max(int a, int b) {return a > b ? a : b;}

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()
#define y1 y1337

const long long MOD = 998244353;

long long inq(long long x, long long y)
{
    if (y == 0) return 1;
    long long l = inq(x, y / 2);
    if (y % 2) return l * l % MOD * x % MOD;
    return l * l % MOD;
}

const long long INF = 1e14;

long long n, m, k;
int d[41][1001][1001];
int a[1001][1001];

int cx[4] = {-1, 0, 1, 0};
int cy[4] = {0, -1, 0, 1};

int ok(int p, int r)
{
    return 0 <= p && p < r;
}

int dist[41][41];
int qq, x1, y1, x2, y2;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    vector<pii> q;
    for (int i = 1; i <= k; i++)
        F(x, n) F(y, m) d[i][x][y] = -1;
    for (int c = 1; c <= k; c++)
    {
        q.clear();
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j] == c) d[c][i][j] = 0, q.push_back({i, j});
        for (int i = 0; i < q.size(); i++)
        {
            pii pos = q[i];
            for (int a = 0; a < 4; a++)
            {
                int nx = cx[a] + pos.first;
                int ny = cy[a] + pos.second;
                if (ok(nx, n) && ok(ny, m) && d[c][nx][ny] == -1)
                    d[c][nx][ny] = d[c][pos.first][pos.second] + 1, q.push_back({nx, ny});
            }
        }
    }
    for (int i = 1; i <= k; i++) for (int j = 1; j <= k; j++) dist[i][j] = 1e9;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int col = 1; col <= k; col++) dist[a[i][j]][col] = min(dist[a[i][j]][col], d[col][i][j] + 1);
        }
    }
    for (int z = 1; z <= k; z++)
        for (int i = 1; i <= k; i++)
            for (int j = 1; j <= k; j++)
                dist[i][j] = min(dist[i][z] + dist[z][j], dist[i][j]);
    cin >> qq;
    while (qq--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, y2--, x2--;
        int ans = abs(x1 - x2) + abs(y1 - y2);
        for (int f = 1; f <= k; f++)
        {
            for (int s = 1; s <= k; s++)
            {
                ans = min(ans, d[f][x1][y1] + d[s][x2][y2] + dist[s][f] + 1);
            }
            ans = min(ans, d[f][x1][y1] + d[f][x2][y2] + 1);
        }
        cout << ans << '\n';
    }
}