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
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define x first
#define y second
#define ft first
#define sc second

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long double ld;
typedef pair<ld, ld> ptd;
typedef long long li;
typedef pair <li, li> pt;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;

struct segm
{
    int val, lf, rg, idx;
    
    segm (int val, int lf, int rg, int idx) : val(val), lf(lf), rg(rg), idx(idx) {}
};

const li RG = 100 * 1000;
const li H = 100;

const int N = 100 + 13;

int hL, hR, n;
vector <segm> s[2];
int cnt[N];

inline int sign (const pt& c, const pt& a, const pt& b)
{
    li A = b.y - a.y, B = a.x - b.x, C = -(A * a.x + B * a.y);
    li s = A * c.x + B * c.y + C;
    return s > 0 ? 1 : s < 0 ? -1 : 0;
}

inline bool intersect (const pt& a, const pt& b, const pt& c, const pt& d)
{
    if (min(a.x, b.x) > max(c.x, d.x) || min(c.x, d.x) > max(a.x, b.x)) return false;
    if (min(a.y, b.y) > max(c.y, d.y) || min(c.y, d.y) > max(a.y, b.y)) return false;
    
    return sign(a, c, d) * sign(b, c, d) <= 0 && sign(c, a, b) * sign(d, a, b) <= 0;
}

inline bool check (int k, const pt& p1, const pt& p2, const segm& s, int iter)
{
    pt q1 = mp(s.lf, H * k), q2 = mp(s.rg, H * k);
    
    if (iter == 0 && k % 2 != 0) q1.y += H, q2.y += H;
    if (iter == 1 && k % 2 == 0) q1.y += H, q2.y += H;
    
    //cerr << q1.x << ' ' << q1.y << ' ' << q2.x << ' ' << q2.y << endl;
    
    return intersect(p1, p2, q1, q2);
}

li calc (int k)
{
    pt p1 = mp(0, hL);
    pt p2 = mp(RG, H * k + (k % 2 == 0 ? hR : H - hR));
    
    //cerr << p1.x << ' ' << p1.y << ' ' << p2.x << ' ' << p2.y << endl;
    
    li A = p2.y - p1.y, B = p1.x - p2.x, C = -(A * p1.x + B * p1.y);
    
    li res = 0;
    forn(i, n) cnt[i] = 0;
    int total = 0;
    
    forn(iter, 2)
        forn(j, sz(s[iter]))
        {
            segm& cur = s[iter][j];
            
            //cerr << cur.val << ' ' << cur.lf << ' ' << cur.rg << ' ' << cur.idx << ' ' << iter << endl;
            
            li nowy = (-C - A * cur.lf) / B;
            int num = nowy / 100;
            
            //cerr << nowy << ' ' << num << endl;
            
            //cerr << check(0, p1, p2, cur, iter) << endl;
            //return 1;
            
            for (int dx = -5; dx <= 5; dx++)
            {
                if (iter != abs((num + dx) % 2)) continue;
            
                if (check(num + dx, p1, p2, cur, iter))
                {
                    //cerr << dx << endl;
                    if (++cnt[cur.idx] == 2) return -1;
                    total++;
                    res += cur.val;
                }
            }
        }
        
    if (total != abs(k)) return -1;
    
    return res;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> hL >> hR >> n;
    
    forn(i, n)
    {
        int val, lf, rg;
        char type;
        scanf("%d %c %d %d", &val, &type, &lf, &rg);
        
        if (type == 'F') type = 0; else type = 1;
        
        s[type].pb(segm(val, lf, rg, i));
    }
    
    //cerr << calc(-1) << endl;
    
    //return 0;
    
    li ans = -1;
    
    for (int k = -103; k <= 103; k++)
        ans = max(ans, calc(k));
        
    assert(ans != -1);
    
    cout << ans << endl;
    
    return 0;
}