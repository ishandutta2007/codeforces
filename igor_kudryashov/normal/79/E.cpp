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

const int N = 4 * 100 * 1000 + 13;

int n, a, b, c;
li T;
li t[4];
int x = 1, y = 1;
char ans[N];
int szans = 0;
pt p[4];

inline int dist (const pt& a, const pt& b)
{
    return abs(a.ft - b.ft) + abs(a.sc - b.sc);
}

void no ()
{
    puts("Impossible");
    exit(0);
}

inline li sum (li n)
{
    if (n <= 0)
        return 0;

    return (n * (n + 1)) >> 1;
}

inline li sum (int lf, int rg)
{
    if (lf > rg)
        return 0;
        
    return sum(rg) - sum(lf - 1);
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> T >> a >> b >> c;
    
    p[0] = mp(a, b + c - 1);
    p[1] = mp(a + c - 1, b + c - 1);
    p[2] = mp(a + c - 1, b);
    p[3] = mp(a, b);
    
    forn(i, 4)
        t[i] = T;
    
    while (x < a)
    {
        ans[szans++] = 'R';
        x++;
        forn(i, 4)
            t[i] -= dist(p[i], mp(x, y));
    }
    
    forn(i, 4)
        if (t[i] < 0)
            no();
    
    while (y < b + c - 1)
    {
        pt npos = mp(x + 1, y);
        pt auxpos0 = mp(npos.ft, p[0].sc);
        pt auxpos3 = mp(npos.ft, p[3].sc);
        
        li needt0 = sum(dist(p[0], auxpos0), dist(p[0], npos)) + sum(dist(p[0], auxpos0) + 1, dist(p[0], mp(n, n)));
        li needt3 = sum(dist(p[3], auxpos3), dist(p[3], npos)) + sum(dist(p[3], auxpos3) + 1, dist(p[3], mp(n, n)));
        
        
        if (x == n || t[0] < needt0 || (y < p[3].sc && t[3] < needt3))
        {
            ans[szans++] = 'U';
            y++;
        } else
        {
            ans[szans++] = 'R';
            x++;
        }
            
        forn(j, 4)
        {
            t[j] -= dist(p[j], mp(x, y));
            if (t[j] < 0)
                no();
        }
    }
    
    while (x < n)
    {
        ans[szans++] = 'R';
        x++;
        
        forn(i, 4)
            t[i] -= dist(p[i], mp(x, y));
    }
    
    forn(i, 4)
        if (t[i] < 0)
            no();
    
    while (y < n)
    {
        ans[szans++] = 'U';
        y++;
        
        forn(i, 4)
            t[i] -= dist(p[i], mp(x, y));
    }
    
    forn(i, 4)
        if (t[i] < 0)
            no();
            
    assert(x == n && y == n);
        
    puts(ans);

    return 0;
}