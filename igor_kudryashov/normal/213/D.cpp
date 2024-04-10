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
typedef pair <int, int> pti;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;

struct pt
{
    ld x, y;
    pt (ld x, ld y) : x(x), y(y) {}
    pt () {}
};

inline pt operator * (const pt& a, const ld& b) { return pt(a.x * b, a.y * b); }
inline pt operator + (const pt& a, const pt& b) { return pt(a.x + b.x, a.y + b.y); }
inline pt operator - (const pt& a, const pt& b) { return pt(a.x - b.x, a.y - b.y); }
inline bool operator < (const pt& a, const pt& b)
{
    if (abs(a.x - b.x) > EPS) return a.x < b.x;
    return a.y + EPS < b.y;
}

inline pt ort (const pt& v) { return pt(-v.y, v.x); }
inline pt normal (const pt& v)
{
    ld l = sqrt(sqr(v.x) + sqr(v.y));
    if (abs(l) < EPS) return v;
    return pt(v.x / l, v.y / l);
}

inline pt rotate (const pt& v, const ld& ang)
{
    return pt(v.x * cos(ang) - v.y * sin(ang), v.x * sin(ang) + v.y * cos(ang));
}

const int N = 1000 + 13;

int cnt;
vector <pt> vs;
int g[N][N];
vector <int> way;
vector <int> ans[N];

void build (int num)
{
    pt p1 = vs.back(), p2 = vs[sz(vs) - 2];
    pt mid = (p1 + p2) * 0.5;
    
    ld len = 5.0 / tan(PI / 5.0);
    
    pt v = normal(ort(p2 - p1)) * len;
    
    if (mid + v < mid - v)
        v = v * (-1.0);
        
    pt cen = mid + v;
    
    pt vv = vs.back() - cen;
    
    ld ang = 2.0 * PI / 5.0;
    if (num % 2 == 0) ang *= -1.0;
    
    forn(iter, 3)
    {
        vv = rotate(vv, ang);
        vs.pb(cen + vv);
    }
}

void fleury (int v)
{
    forn(i, sz(vs))
        if (g[v][i])
        {
            g[v][i]--;
            g[i][v]--;
            fleury(i);
        }
        
    way.pb(v);
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> cnt;
    
    vs.pb(pt(0, 0));
    vs.pb(pt(0, 10));
    
    forn(iter, cnt)
        build(iter);
        
    cout << sz(vs) << endl;
    
    forn(i, sz(vs))
        printf("%.20lf %.20lf\n", double(vs[i].x), double(vs[i].y));
        
    forn(i, cnt)
    {
        if (i != 0)
        {
            ans[i].pb(ans[i - 1][3]);
            ans[i].pb(ans[i - 1][4]);
        } else
        {
            ans[i].pb(0);
            ans[i].pb(1);
        }
        
        forn(j, 3)
            ans[i].pb(ans[i].back() + 1);
            
        forn(j, 5)
        {
            int a = ans[i][j], b = ans[i][(j + 2) % 5], c = ans[i][(j + 3) % 5];
            g[a][b] = g[b][a] = 1;
            g[a][c] = g[c][a] = 1;
        }
        
        forn(j, 5)
            printf("%d ", ans[i][j] + 1);
        puts("");
    }
    
    fleury(0);
    
    forn(i, sz(way))
        printf("%d ", way[i] + 1);
        
    puts("");
    
    return 0;
}