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

const int N = 1500 + 13;

struct point
{
    int x, y, idx;
    point (int x, int y, int idx) : x(x), y(y), idx(idx) {}
    point () { x = 0, y = 0, idx = -1; }
};

int n;
vector <int> g[N];
int p[N];
int cnt[N];
int ans[N];

void dfs (int v, int pr)
{
    p[v] = pr;
    cnt[v] = 1;
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        if (to == pr) continue;
        dfs(to, v);
        cnt[v] += cnt[to];
    }
}

pt pole;

inline li cross (const pt& a, const pt& b)
{
    return a.ft * 1LL * b.sc - a.sc * 1LL * b.ft;
}

inline bool cmpPole (const point& a, const point& b)
{
    pt p1 = mp(a.x - pole.ft, a.y - pole.sc);
    pt p2 = mp(b.x - pole.ft, b.y - pole.sc);
    
    return cross(p1, p2) > 0;
}

void solve (vector <point> ps, int v)
{
    ans[ps.back().idx] = v;
    pole = mp(ps.back().x, ps.back().y);
    ps.pop_back();
    
    if (ps.empty())
    {
        assert(sz(g[v]) == 1);
        return;
    }
    
    sort(all(ps), cmpPole);
    
    int last = 0;
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        if (to == p[v]) continue;
        
        vector <point> cur;
        
        forn(j, cnt[to])
        {
            assert(last < sz(ps));
            cur.pb(ps[last++]);
        }
        
        solve(cur, to);
    }
    
    assert(last == sz(ps));
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    if (n == 1)
    {
        puts("1");
        return 0;
    }
    
    forn(i, n - 1)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    vector <point> v;
    
    forn(i, n)
    {
        int ax, ay;
        scanf("%d%d", &ax, &ay);
        v.pb(point(ax, ay, i));
    }
    
    dfs(0, 0);
    
    int minidx = 0;
    point minv = v[0];
    
    forn(i, sz(v))
        if (mp(v[i].x, v[i].y) < mp(minv.x, minv.y))
            minv = v[i], minidx = i;
            
    swap(v[minidx], v[sz(v) - 1]);
    
    memset(ans, -1, sizeof(ans));
    
    solve(v, 0);
    
    forn(i, n)
    {
        assert(ans[i] != -1);
        printf("%d ", ans[i] + 1);
    }
    
    puts("");

    return 0;
}