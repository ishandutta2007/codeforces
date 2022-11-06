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

const int N = 13;

int n;
int lf[N][N], rg[N][N];
int a[N][N];
int minin[N], maxin[N];
int minout[N], maxout[N];
int canMax[N][N];
int minFlow = INF, maxCost = -1;
int suffMax[N][N];

int curin[N], curout[N];

int curFlow = 0, curCost = 0;

void go (int i, int j)
{
    if (j == n)
    {
        if (i != 0 && curin[i] != curout[i])
            return;
    
        i++, j = i + 1;
    }

    if (i == n - 1)
    {
        assert(minFlow >= curFlow); //|| (minFlow == curFlow && maxCost <= curCost));

        minFlow = curFlow;
        if (curCost > maxCost)
            maxCost = curCost;
        
        return;
    }

    if (curCost + suffMax[i][j] <= maxCost)
        return;

    if (curin[i] < minin[i] || curin[i] > maxin[i])
        return;
        
    if (curin[i] > curout[i] + canMax[i][j])
        return;
        
    if (i != 0 && curin[i] < curout[i])
        return;
    
    for (int fl = lf[i][j]; fl <= rg[i][j]; fl++)
    {
        if (curin[j] + fl > maxin[j])
            break;
            
        if (i != 0 && curout[i] + fl > curin[i])
            break;
            
        if (i == 0 && curFlow + fl > minFlow)
            break;
            
        curout[i] += fl;
        curin[j] += fl;

        if (i == 0)
            curFlow += fl;
            
        if (fl > 0)
            curCost += a[i][j] + fl * fl;
            
        go(i, j + 1);
        
        curout[i] -= fl;
        curin[j] -= fl;
        
        if (i == 0)
            curFlow -= fl;
            
        if (fl > 0)
            curCost -= a[i][j] + fl * fl;
    }
}

int main()
{
    
    cin >> n;
    
    int m = n * (n - 1) / 2;
    
    forn(i, m)
    {
        int fr, to;
        cin >> fr >> to;
        --fr, --to;
        
        if (fr > to)
            swap(fr, to);
            
        cin >> lf[fr][to] >> rg[fr][to] >> a[fr][to];
        
        minin[to] += lf[fr][to];
        maxin[to] += rg[fr][to];
        
        minout[fr] += lf[fr][to];
        maxout[fr] += rg[fr][to];
    }
    
    forn(i, n)
        for (int j = n - 1; j > i; j--)
            canMax[i][j] = rg[i][j] + (j == n - 1 ? 0 : canMax[i][j + 1]);

    for (int i = n - 1; i >= 0; i--)
    {
        suffMax[i][n - 1] = suffMax[i + 1][n - 1] + a[i][n - 1] + rg[i][n - 1] * rg[i][n - 1];

        for (int j = n - 2; j > i; j--)
            suffMax[i][j] = suffMax[i][j + 1] + a[i][j] + rg[i][j] * rg[i][j];
    }
    
    go(0, 1);
    
    if (maxCost == -1)
        minFlow = -1;
        
    cout << minFlow << ' ' << maxCost << endl;

    return 0;
}