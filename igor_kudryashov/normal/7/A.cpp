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

const int N = 10;

char f[N][N];

bool allB()
{
    forn(i, 8)
        forn(j, 8)
            if (f[i][j] == 'W')
                return false;
                
    return true;
}

int main()
{
    
    forn(i, 8)
        scanf("%s", f[i]);
        
    if (allB())
    {
        puts("8");
        return 0;
    }
    
    int n = 8;
    
    int res = 0;
    
    forn(i, n)
    {
        int full = true;
        
        forn(j, n)
            if (f[i][j] == 'W')
                full = false;
                
        res += full;
        
        full = true;
        
        forn(j, n)
            if (f[j][i] == 'W')
                full = false;
                
        res += full;
    }
    
    cout << res << endl;

    return 0;
}