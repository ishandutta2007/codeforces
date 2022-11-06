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

const int N = 3000 + 3;
const int M = 300 + 3;

int n, m;
ld p[N][M];
ld d[M][N][2];
ld curSum[M];

void recalc (int idx)
{
    forn(i, n + 1)
        d[idx][i][0] = d[idx][i][1], d[idx][i][1] = 0.0;
        
    forn(i, n)
    {
        ld dv = d[idx][i][0];
        
        d[idx][i + 1][1] += p[i][idx] * dv;
        d[idx][i + 1][0] += (1.0 - p[i][idx]) * dv;
    }
    
    curSum[idx] += d[idx][n][0];
    
    /*forn(iter, 2)
    {
        forn(i, n + 1)
            cerr << d[idx][i][iter] << ' ';
        cerr << endl;
    }
    cerr << endl;*/
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m;
    
    forn(i, n)
        forn(j, m)
        {
            int cur;
            scanf("%d", &cur);
            p[i][j] = ld(cur) / ld(1000);
        }
    
    forn(i, m)
    {
        d[i][0][1] = 1.0;
        curSum[i] = 0.0;
    }
    
    forn(i, m)
    {
        recalc(i);
        /*forn(j, n + 1)
            cerr << d[i][j][0] << ' ';
        cerr << curSum[i] << endl;*/
    }
        
    ld ans = 0.0;
        
    forn(iter, n)
    {
        ld minv = 1e18;
        int idx = -1;
        
        forn(i, m)
            if (curSum[i] + EPS < minv)
                minv = curSum[i], idx = i;
                
        assert(idx != -1 && minv < 1.0 + EPS);
        ans += 1.0 - curSum[idx];
        recalc(idx);
    }
    
    cout << setprecision(10) << fixed;
    cout << ans << endl;    

    return 0;
}