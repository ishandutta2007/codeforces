#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<li, li> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 100 * 1000 + 13;
const li INF64 = li(1e15);

int n, p, cntpositions;
int positions[N];
li a[N], s[N];
li d[N];

inline bool read()
{
    if (scanf("%d%d%d", &cntpositions, &n, &p) != 3)
        return false;
        
    forl(i, cntpositions - 1)
    {
        int dx;
        assert(scanf("%d", &dx) == 1);
        positions[i] = positions[i - 1] + dx;
    }
    
    forn(i, n)
    {
        int idx, t;
        assert(scanf("%d%d", &idx, &t) == 2);
        --idx;
        a[i] = t - positions[idx];
    }
    
    return true;
}

inline ld intersect (const pt& L1, const pt& L2)
{
    assert(L1.x != L2.x);
    return ld(L2.y - L1.y) / ld(L1.x - L2.x);
}

vector <pt> lines;
vector <ld> xs;

inline void prepare ()
{
    lines.clear();
    xs.clear();
    
    forn(i, n + 1)
    {
        pt cur = mp(-i, d[i] + (i == 0 ? 0 : s[i - 1]));
        
        while (sz(lines) > 1 && intersect(lines[sz(lines) - 2], lines[sz(lines) - 1]) + EPS > intersect(lines[sz(lines) - 1], cur))
            lines.pop_back();
            
        lines.pb(cur);
    }
    
    forn(i, sz(lines) - 1) xs.pb(intersect(lines[i], lines[i + 1]));
}

inline void solve()
{
    sort(a, a + n);
    
    //forn(i, n) cerr << a[i] << ' '; cerr << endl;
    
    forn(i, n) s[i] = (i == 0 ? 0 : s[i - 1]) + a[i];
    
    forn(i, N) d[i] = INF64;
    d[0] = 0;
    
    forn(iter, p)
    {
        prepare();
        
        //forn(i, sz(lines)) cerr << "(" << lines[i].x << "," << lines[i].y << ") "; cerr << endl;
        //forn(i, sz(xs)) cerr << xs[i] << ' '; cerr << endl;
        
        d[0] = 0;
        
        int ptr = 0;
        
        forl(cnt, n + 1)
        {
            li cur = a[cnt - 1] * cnt - s[cnt - 1];
            while (ptr < sz(xs) && xs[ptr] + EPS < a[cnt - 1]) ptr++;
            cur += a[cnt - 1] * lines[ptr].x + lines[ptr].y;
            d[cnt] = cur;
        }
        
        //forn(i, n + 1) cerr << d[i] << ' '; cerr << endl; cerr << endl;
    }
    
    cout << d[n] << endl;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    assert(read());
    solve();
    
    return 0;
}