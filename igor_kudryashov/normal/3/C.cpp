#pragma comment(linker, "/stack:64000000")
#define _SECURE_SCL 0
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

char f[3][3];

char sameInRow (int i)
{
    char c = f[i][0];

    forn(j, 3)
        if (f[i][j] != c)
            return 0;
            
    return c;
}

char sameInCol (int j)
{
    char c = f[0][j];
    
    forn(i, 3)
        if (f[i][j] != c)
            return 0;
            
    return c;
}

char sameMain ()
{
    char c = f[0][0];
    
    forn(i, 3)
        if (f[i][i] != c)
            return 0;
            
    return c;
}

char sameRev ()
{
    char c = f[0][2];
    
    forn(i, 3)
        if (f[i][2 - i] != c)
            return 0;
            
    return c;
}

bool firWin ()
{
    forn(i, 3)
    {
        if (sameInRow(i) == 'X')
            return true;
            
        if (sameInCol(i) == 'X')
            return true;
    }
    
    if (sameMain() == 'X')
        return true;
        
    if (sameRev() == 'X')
        return true;
        
    return false;
}

bool secWin ()
{
    forn(i, 3)
    {
        if (sameInRow(i) == '0')
            return true;
            
        if (sameInCol(i) == '0')
            return true;
    }
    
    if (sameMain() == '0')
        return true;
        
    if (sameRev() == '0')
        return true;
        
    return false;
}

int main()
{
    
    forn(i, 3)
        scanf("%s", f[i]);
        
    int x = 0, o = 0;
    
    forn(i, 3)
        forn(j ,3)
            x += f[i][j] == 'X', o += f[i][j] == '0';
            
    bool fWin = firWin();
    bool sWin = secWin();
            
    if (abs(x - o) > 1 || (o > x) || (fWin && sWin) || (fWin && x - o != 1) || (sWin && x != o))
        puts("illegal");
    else if (fWin)
        puts("the first player won");
    else if (sWin)
        puts("the second player won");
    else if (x + o == 9)
        puts("draw");
    else if (x == o)
        puts("first");
    else if (x - o == 1)
        puts("second");
    else
        throw;

    return 0;
}