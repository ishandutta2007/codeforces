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
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 100 * 1000 + 13;

li h;
int n, m, k;
vector <li> add;
li pos[N];
int val[N];
set <pt> s;
int has[N];
int can[N];

li minv[N];

inline bool Can (const li& pos)
{
    return minv[pos % k] <= pos;
}

void build ()
{
    forn(i, k) minv[i] = h + 1;
    minv[0] = 0;
    
    queue <int> q;
    q.push(0);
    
    while (!q.empty())
    {
        int rem = q.front();
        q.pop();
        
        forn(i, sz(add))
        {
            li nval = minv[rem] + add[i];
            int nrem = nval % k;
            
            if (minv[nrem] > nval)
            {
                minv[nrem] = nval;
                q.push(nrem);
            }
        }
    }
    
    //forn(i, k) cerr << minv[i] << ' '; cerr << endl;
    //cerr << "add = "; forn(i, sz(add)) cerr << add[i] << ' '; cerr << endl;
    
    s.clear();
    
    forn(i, n)
    {
        //cerr << pos[i] << ' ' << minv[pos[i] % k] << endl;
        if (!has[i]) continue;
        if (can[i]) assert(Can(pos[i]));
        if (Can(pos[i])) can[i] = true;     
        if (can[i]) s.insert(mp(val[i], -i));
    }
}

inline bool read()
{
    if (!(cin >> h >> n >> m >> k)) return false;
    
    forn(i, n) assert(scanf("%I64d%d", &pos[i], &val[i]) == 2), --pos[i];
    
    return true;
}

inline void solve()
{
    forn(i, n) has[i] = true;
    
    add.pb(k);
    build();
    
    //forn(i, n) cerr << can[i] << ' '; cerr << endl;
    
    forn(iter, m)
    {
        int type;
        assert(scanf("%d", &type) == 1);
        
        if (type == 1)
        {
            li x;
            assert(scanf("%I64d", &x) == 1);
            add.pb(x);
            build();
            
        } else if (type == 2)
        {
            int idx, dval;
            assert(scanf("%d%d", &idx, &dval) == 2);
            --idx;
            
            assert(has[idx]);
            s.erase(mp(val[idx], -idx));
            val[idx] -= dval;
            if (can[idx]) s.insert(mp(val[idx], -idx));
            
        } else if (type == 3)
        {
            if (s.empty())
            {
                puts("0");
                continue;
            }
            
            int val = (--s.end())->ft;
            int idx = abs((--s.end())->sc);
            s.erase(--s.end());
            
            printf("%d\n", val);
            has[idx] = false;
            
        } else throw;
    }
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