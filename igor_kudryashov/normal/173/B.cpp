#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
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

const int N = 1000 + 3;

int n, m;
char f[N][N];
int d[N][N][4];

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    scanf("%d%d", &n, &m);
    
    forn(i, n)
        scanf("%s", f[i]);
        
    memset(d, 63, sizeof(d));
    
    d[n - 1][m - 1][0] = 0;
    queue <pair <pt, int> > q;
    q.push(mp(mp(n - 1, m - 1), 0));
    
    while (!q.empty())
    {
        pt cur = q.front().ft;
        int dir = q.front().sc;
        q.pop();
        
        int x = cur.ft, y = cur.sc;
        int dv = d[x][y][dir];
        
        {
            int tx = x + dx[dir], ty = y + dy[dir];
            if (correct(tx, ty, n, m) && d[tx][ty][dir] > dv)
            {
                d[tx][ty][dir] = dv;
                q.push(mp(mp(tx, ty), dir));
            }
        }
        
        if (f[x][y] == '#')
        {
            forn(i, 4)
                if (d[x][y][i] > dv + 1)
                {
                    d[x][y][i] = dv + 1;
                    q.push(mp(mp(x, y), i));
                }
        }
    }
    
    if (d[0][0][0] > INF / 2)
        puts("-1");
    else
        cout << d[0][0][0] << endl; 

    return 0;
}