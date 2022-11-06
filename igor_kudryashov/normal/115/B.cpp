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

const int N = 200 + 13;

int n, m;
char f[N][N];
int lf[N], rg[N];

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m;
    
    forn(i, n)
    {
        scanf("%s", f[i]);
        lf[i] = INF, rg[i] = -1;
        
        forn(j, m)
            if (f[i][j] == 'W')
            {
                lf[i] = min(lf[i], j);
                rg[i] = max(rg[i], j);
            }
    }
        
    int ans = 0;
    int curx = 0, cury = 0;
    
    if (rg[0] != -1)
        ans += rg[0], cury = rg[0];
    
    while (true)
    {
        int idx = -1;
        
        for (int i = curx + 1; i < n; i++)
            if (rg[i] != -1)
            {
                idx = i;
                break;
            }
            
        if (idx == -1)
            break;
            
        ans += idx - curx;
            
        if (idx & 1)
        {
            if (rg[idx] > cury)
                ans += rg[idx] - cury, cury = rg[idx];
                
            ans += cury - lf[idx];
            cury = lf[idx];
        
        } else
        {
            if (lf[idx] < cury)
                ans += cury - lf[idx], cury = lf[idx];
                
            ans += rg[idx] - cury;
            cury = rg[idx];
        }
        
        curx = idx;
    }
    
    cout << ans << endl;

    return 0;
}