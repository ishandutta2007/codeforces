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
#define x first
#define y second
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

const int N = 100 + 3;
const int M = 20 * 1000 + 13;

int n, m;
char f[N][M];
int lf[N][M], rg[N][M];

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m;
    
    forn(i, n)
    {
        scanf("%s", f[i]);
        forn(j, m) f[i][j + m] = f[i][j];
    }
        
    forn(i, n)
    {
        forn(j, 2 * m)
            if (f[i][j] == '1')
                lf[i][j] = j;
            else lf[i][j] = (j == 0 ? -1 : lf[i][j - 1]);
            
        for (int j = 2 * m - 1; j >= 0; j--)
            if (f[i][j] == '1')
                rg[i][j] = j;
            else rg[i][j] = (j == 2 * m - 1 ? -1 : rg[i][j + 1]);
    }
    
    li ans = li(1e18);
    
    forn(j, 2 * m)
    {
        li cur = 0;
        
        forn(i, n)
        {
            if (lf[i][j] == -1 && rg[i][j] == -1)
            {
                puts("-1");
                return 0;
            }
            
            if (lf[i][j] == -1)
                cur += rg[i][j] - j;
            else if (rg[i][j] == -1)
                cur += j - lf[i][j];
            else
                cur += min(rg[i][j] - j, j - lf[i][j]);
        }
        
        ans = min(ans, cur);
    }
    
    cout << ans << endl;
    
    return 0;
}