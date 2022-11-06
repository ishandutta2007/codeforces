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

typedef vector <string> matrix;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;

const int N = 20 + 13;

int n, m;
char f[N][N];

void rotate (matrix& cur)
{
    matrix nw;

    for (int j = sz(cur[0]) - 1; j >= 0; j--)
    {
        string s = "";

        for (int i = 0; i < sz(cur); i++)
            s.pb(cur[i][j]);

        nw.pb(s);
    }
    
    cur = nw;
}

inline bool good (int szx, int szy)
{
    set <matrix> used;
    
    for (int i = 0; i < n; i += szx)
        for (int j = 0; j < m; j += szy)
        {
            matrix cur;
            forn(ii, szx)
                cur.pb(string(szy, 0));
            
            for (int it = i; it < i + szx; it++)
                for (int jt = j; jt < j + szy; jt++)
                    cur[it - i][jt - j] = f[it][jt];
                    
            forn(k, 4)
            {
                rotate(cur);
                
                if (used.count(cur))
                    return false;
            }
            
            forn(k, 4)
            {
                rotate(cur);
                
                used.insert(cur);
            }
        }
        
    return true;
}

int main()
{
    
    cin >> n >> m;
    forn(i, n)
        scanf("%s", f[i]);
        
    int ans = 0;
    int minx = 100, miny = 100;
        
    for1(i, n)
        for1(j, m)
            if (n % i == 0 && m % j == 0 && good(i, j))
            {
                ans++;
                
                if (minx * miny > i * j || (minx * miny == i * j && minx > i))
                    minx = i, miny = j;
            }
        
    cout << ans << endl;
    
    cout << minx << ' ' << miny << endl;

    return 0;
}