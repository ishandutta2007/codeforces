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

const int N = 100 * 1000 + 3;

int n, k, h;
int m[N], v[N];
pair <int, pt> a[N];
li maxh[N];
int ans[N];

bool can (ld t)
{
    forn(i, n)
        maxh[i] = li(t * ld(a[i].sc.ft) / ld(h) + EPS);
        
    /*forn(i, n)
        cerr << maxh[i] << ' ';
    cerr << endl;*/
        
    int curH = k;
    
    ford(i, n)
        if (maxh[i] >= curH && curH > 0)
        {
            ans[curH - 1] = a[i].sc.sc;
            curH--;
        }
        
    return (curH == 0);
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> k >> h;
    
    forn(i, n)
        scanf("%d", &m[i]);
        
    forn(i, n)
        scanf("%d", &v[i]);
        
    forn(i, n)
        a[i] = mp(m[i], mp(v[i], i));
        
    sort(a, a + n);
    
    ld lf = 0.0, rg = 1e9 + 3;
    
    forn(iter, 100)
    {
        ld mid = (lf + rg) / 2.0;
        
        if (can(mid))
            rg = mid;
        else
            lf = mid;
    }
    
    //assert(can(rg));
    can(rg);
    
    forn(i, k)
        printf("%d ", ans[i] + 1);
        
    puts("");

    return 0;
}