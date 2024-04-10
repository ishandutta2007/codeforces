#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define X first
#define Y second
#define ft first
#define sc second

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long double ld;
typedef pair<ld, ld> ptd;
typedef pair <int, int> pt;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

const int N = 50 + 13;

int n, m;
char f[N][N];
int d[N][N];

int calcDist (int stx, int sty)
{
    queue <pt> q;    
    q.push(mp(stx, sty));

    memset(d, 63, sizeof(d));
    d[stx][sty] = 0;

    while (!q.empty())
    {
        int x = q.front().ft, y = q.front().sc;
        q.pop();

        forn(i, 4)
        {
            int tx = x + dx[i], ty = y + dy[i];

            if (!correct(tx, ty, n, m) || d[tx][ty] <= d[x][y] + (f[x][y] != f[tx][ty]))
                continue;

            d[tx][ty] = d[x][y] + (f[x][y] != f[tx][ty]);

            q.push(mp(tx, ty));
        }
    }

    int res = -1;

    forn(i, n)
        forn(j, m)
            if (f[i][j] == 'B')
                res = max(res, d[i][j]);

    return res;
}

int main()
{
 
    cin >> n >> m;

    forn(i, n)
        scanf("%s", f[i]);

    int ans = INF;

    forn(i, n)
        forn(j, m)
            ans = min(ans, calcDist(i, j) + 1);

    assert(ans < (INF >> 2));               

    cout << ans << endl;

    return 0;
}