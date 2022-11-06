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

const int N = 5000 + 13;

int f[N][N];

int main()
{
   
    int n, m, x;
    
    cin >> n >> m >> x;
    
    for (int dx = 0; ; dx++)
    {
        int stx = dx, finx = n - 1 - dx;
        int sty = dx, finy = m - 1 - dx;
        
        if (stx > finx)
            break;
            
        if (sty > finy)
            break;
            
        for (int x = stx; x <= finx; x += 2)
            f[x][sty] = dx + 1;
            
        for (int y = sty; y <= finy; y += 2)
            f[stx][y] = dx + 1;
            
        if ((finx - stx) % 2 == 1)
        {
            for (int y = sty + 1; y <= finy; y += 2)
                f[finx][y] = dx + 1;
        } else
        {
            for (int y = sty; y <= finy; y += 2)
                f[finx][y] = dx + 1;        
        }
    
        if ((finy - sty) % 2 == 1)
        {
            for (int x = stx + 1; x <= finx; x += 2)
                f[x][finy] = dx + 1;
        } else 
        {
            for (int x = stx; x <= finx; x += 2)
                f[x][finy] = dx + 1;
        }
    }
    
    /*
    forn(i, n)
    {
        forn(j, m)
            printf("%d ", f[i][j]);
        puts("");
    }       
    */
    
    int ans = 0;
    
    forn(i, n)
        forn(j, m)
            if (f[i][j] == x)
                ans++;

    cout << ans << endl;    

    return 0;
}