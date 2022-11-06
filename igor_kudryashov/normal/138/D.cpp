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

const int N = 40 + 3;

int n, m;
char f[N][N];
int SH;
int z[N][N][N][N];

void calc (int x, int y, int mins, int maxs, int mind, int maxd, vector <pair <pt, pt> >& v)
{
    int curs = x + y, curd = x - y + SH;
    
    if (f[x][y] == 'L')
    {
        v.pb(mp(mp(mins, curs - 2), mp(mind, maxd)));
        v.pb(mp(mp(curs + 2, maxs), mp(mind, maxd)));
        
    } else if (f[x][y] == 'R')
    {
        v.pb(mp(mp(mins, maxs), mp(mind, curd - 2)));
        v.pb(mp(mp(mins, maxs), mp(curd + 2, maxd)));
        
    } else if (f[x][y] == 'X')
    {
        {
            pt psum = mp(mins, curs - 2);
            pt pdif = mp(mind, curd - 2);
            v.pb(mp(psum, pdif));
        }
        {
            pt psum = mp(mins, curs - 2);
            pt pdif = mp(curd + 2, maxd);
            v.pb(mp(psum, pdif));
        }
        {
            pt psum = mp(curs + 2, maxs);
            pt pdif = mp(mind, curd - 2);
            v.pb(mp(psum, pdif));
        }
        {
            pt psum = mp(curs + 2, maxs);
            pt pdif = mp(curd + 2, maxd);
            v.pb(mp(psum, pdif));
        }       
    } else
        throw;
}

int grandy (int mins, int maxs, int mind, int maxd)
{
    if (mins > maxs || mind > maxd)
        return 0;

    int& ans = z[mins][maxs][mind][maxd];
    
    if (ans != -1)
        return ans;
        
    set <int> mex;
    
    forn(i, n)
        forn(j, m)
        {
            if (((i + j) & 1) != (mins & 1))
                continue;
                
            if (i + j < mins || i + j > maxs)
                continue;
                
            if (i - j + SH < mind || i - j + SH > maxd)
                continue;
                
            vector <pair <pt, pt> > v;
            calc(i, j, mins, maxs, mind, maxd, v);
            
            int curxor = 0;
            forn(k, sz(v))
                curxor ^= grandy(v[k].ft.ft, v[k].ft.sc, v[k].sc.ft, v[k].sc.sc);

            mex.insert(curxor);
        }
        
    forn(i, sz(mex) + 1)
        if (!mex.count(i))
            return ans = i;
            
    throw;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m;
    
    forn(i, n)
        cin >> f[i];
        
    int tmins[2] = {INF, INF}, tmaxs[2] = {-INF, -INF}, tmind[2] = {INF, INF}, tmaxd[2] = {-INF, -INF};
    
    forn(i, n)
        forn(j, m)
        {
            tmins[(i + j) & 1] = min(tmins[(i + j) & 1], i + j);
            tmaxs[(i + j) & 1] = max(tmaxs[(i + j) & 1], i + j);
            tmind[(i - j) & 1] = min(tmind[(i - j) & 1], i - j);
            tmaxd[(i - j) & 1] = max(tmaxd[(i - j) & 1], i - j);
        }
        
    SH = -min(tmind[0], tmind[1]);
    
    memset(z, -1, sizeof(z));
    
    int ans = grandy(tmins[0], tmaxs[0], tmind[0] + SH, tmaxd[0] + SH);
    int ans2 = grandy(tmins[1], tmaxs[1], tmind[1] + SH, tmaxd[1] + SH);
    ans ^= ans2;
    
    if (ans == 0)
        puts("LOSE");
    else
        puts("WIN");
        
    return 0;
}