//19:18

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
typedef pair <int, int> pti;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;

struct pt
{
    ld x, y;
    
    pt (ld x = 0.0, ld y = 0.0) : x(x), y(y) {}
};

inline bool operator == (const pt& a, const pt& b)
{
    return abs(a.x - b.x) < EPS && abs(a.y - b.y) < EPS;
}

inline pt operator + (const pt& a, const pt& b)
{
    return pt(a.x + b.x, a.y + b.y);
}

inline pt operator - (const pt& a, const pt& b)
{
    return pt(a.x - b.x, a.y - b.y);
}

inline pt operator * (const pt& a, const ld& c)
{
    return pt(a.x * c, a.y * c);
}

inline ld angle (const pt& a)
{
    ld res = atan2(a.y, a.x);
    
    if (res < -EPS)
        res += 2.0 * PI;
        
    return res;
}

inline bool between (const pt& c, const pt& a, const pt& b)
{
    if (c.x + EPS < min(a.x, b.x) || c.x > max(a.x, b.x) + EPS)
        return false;
        
    if (c.y + EPS < min(a.y, b.y) || c.y > max(a.y, b.y) + EPS)
        return false;
        
    return true;
}

inline bool onSegm (const pt& c, const pt& a, const pt& b)
{
    ld A = b.y - a.y, B = a.x - b.x, C = -(a.x * A + a.y * B);
    ld l = sqrt(sqr(A) + sqr(B));
    A /= l, B /= l, C /= l;
    
    if (abs(c.x * A + c.y * B + C) > EPS)
        return false;
        
    return between(c, a, b);
}

inline int sign (const pt& c, const pt& a, const pt& b)
{
    ld A = b.y - a.y, B = a.x - b.x, C = -(a.x * A + a.y * B);
    ld v = A * c.x + B * c.y + C;
    
    return v > EPS ? 1 : v < -EPS ? -1 : 0;
}

inline bool intersect (const pt& a, const pt& b, const pt& c, const pt& d)
{
    if (min(a.x, b.x) > max(c.x, d.x) + EPS || max(a.x, b.x) + EPS < min(c.x, d.x))
        return false;
        
    if (min(a.y, b.y) > max(c.y, d.y) + EPS || max(a.y, b.y) + EPS < min(c.y, d.y))
        return false;
        
    return sign(c, a, b) * sign(d, a, b) <= 0 && sign(a, c, d) * sign(b, c, d) <= 0;
}

const int N = 100 * 1000 + 13;

int n[3];
pt p[3][N];
pt pol[3 * N];
int szpol = 0;
pt cen;
pair <ld, int> angs[3 * N];

inline bool check (const pt& a)
{
    int k = int(lower_bound(angs, angs + szpol, mp(angle(a - cen), -1)) - angs);
    
    for (int dx = -2; dx <= 2; dx++)
    {
        int idx = (k + dx + szpol) % szpol;
        int i = angs[idx].sc, j = angs[(idx + 1) % szpol].sc;
        
        assert((i + 1) % szpol == j);
        
        if (onSegm(a, pol[i], pol[j]))
            return true;
            
        if (intersect(cen, a, pol[i], pol[j]))
            return false;
    }
    
    return true;
}

void build ()
{
    int idx[3] = {0, 0, 0};
    int cnt[3] = {0, 0, 0};
    forn(i, 3)
        forn(j, n[i])
            if (p[i][j].y + EPS < p[i][idx[i]].y || (abs(p[i][j].y - p[i][idx[i]].y) < EPS && p[i][j].x + EPS < p[i][idx[i]].x))
                idx[i] = j;
                
    pol[szpol++] = p[0][idx[0]] + p[1][idx[1]] + p[2][idx[2]];

    while (true)
    {
        vector <pair <ld, int> > ang;
    
        forn(i, 3)
        {
            if (cnt[i] == n[i])
                continue;
                
            int nextidx = (idx[i] + 1 == n[i] ? 0 : idx[i] + 1);
            ang.pb(mp(angle(p[i][nextidx] - p[i][idx[i]]), i));
        }
        
        if (ang.empty())
            break;
            
        sort(all(ang));
        
        int num = ang[0].sc;
        int nextidx = (idx[num] + 1 == n[num] ? 0 : idx[num] + 1);
        pt v = p[num][nextidx] - p[num][idx[num]];
        
        pol[szpol] = pol[szpol - 1] + v;
        szpol++;
        idx[num] = nextidx;
        cnt[num]++;
    }
    
    assert(szpol == n[0] + n[1] + n[2] + 1 && pol[0] == pol[szpol - 1]);
    szpol--;

    forn(i, szpol)
        cen = cen + pol[i];
    cen = cen * (1.0 / szpol);
    
    forn(i, szpol)
        angs[i] = mp(angle(pol[i] - cen), i);
        
    sort(angs, angs + szpol);
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    forn(i, 3)
    {
        scanf("%d", &n[i]);
        
        forn(j, n[i])
        {
            int ax, ay;
            scanf("%d%d", &ax, &ay);
            p[i][j] = pt(ax, ay);
        }
    }
    
    build();
    
    int m;
    scanf("%d", &m);
    
    forn(i, m)
    {
        int ax, ay;
        scanf("%d%d", &ax, &ay);
        
        if (check(pt(ax, ay) * 3.0))
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}