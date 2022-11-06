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

const int N = 500 + 3;

int n, m;
int a[N][N];
int srow[N][N], scol[N][N];
int ans = -INF;
int d[2][N][N];

int sumR (int i, int lf, int rg)
{
    //assert(lf <= rg);
    
    return srow[i][rg] - (lf == 0 ? 0 : srow[i][lf - 1]);
}

int sumC (int j, int lf, int rg)
{
    //assert(lf <= rg);
    
    return scol[rg][j] - (lf == 0 ? 0 : scol[lf - 1][j]);
}

void calc2 ()
{
    memset(d, 0, sizeof(d));

    forn(i, n)
        forn(j, m)
            if (i + 4 < n && j + 4 < m)
            {
                d[0][i][j] = sumR(i, j, j + 4) + sumR(i + 4, j, j + 4) + sumC(j + 4, i + 1, i + 3) + sumR(i + 2, j, j + 2) + a[i + 3][j];
                ans = max(ans, d[0][i][j]);
            }
            
    int cur = 1;
            
    for (int len = 9; len <= min(n, m); len += 4)
    {
        forn(i, n)
            forn(j, m)
                if (i + len - 1 < n && j + len - 1 < m)
                {
                    int sum = sumR(i, j, j + len - 1);
                    sum += sumR(i + len - 1, j, j + len - 1);
                    sum += sumC(j, i + 2, i + len - 2);
                    sum += sumC(j + len - 1, i + 1, i + len - 2);
                    sum += sumR(i + 2, j + 1, j + 1);
                    sum += d[cur ^ 1][i + 2][j + 2];
                    
                    d[cur][i][j] = sum;
                    ans = max(ans, sum);
                }
                
        cur ^= 1;
    }
}

void calc1 ()
{
    forn(i, n)
        forn(j, m)
            if (i + 2 < n && j + 2 < m)
            {
                d[0][i][j] = sumR(i, j, j + 2) + sumR(i + 2, j, j + 2) + a[i + 1][j + 2];
                ans = max(ans, d[0][i][j]);
            }
            
    int cur = 1;
            
    for (int len = 7; len <= min(n, m); len += 4)
    {
        forn(i, n)
            forn(j, m)
                if (i + len - 1 < n && j + len - 1 < m)
                {
                    int sum = sumR(i, j, j + len - 1);
                    sum += sumR(i + len - 1, j, j + len - 1);
                    sum += sumC(j, i + 2, i + len - 2);
                    sum += sumC(j + len - 1, i + 1, i + len - 2);
                    sum += sumR(i + 2, j + 1, j + 1);
                    sum += d[cur ^ 1][i + 2][j + 2];
                    
                    d[cur][i][j] = sum;
                    ans = max(ans, sum);
                }
                
        cur ^= 1;
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m;
    
    forn(i, n)
        forn(j, m)
            scanf("%d", &a[i][j]);
            
    forn(i, n)
        forn(j, m)
            srow[i][j] = a[i][j] + (j == 0 ? 0 : srow[i][j - 1]);
            
    forn(j, m)
        forn(i, n)
            scol[i][j] = a[i][j] + (i == 0 ? 0 : scol[i - 1][j]);
            
    calc1();
    calc2();
    
    cout << ans << endl;

    return 0;
}