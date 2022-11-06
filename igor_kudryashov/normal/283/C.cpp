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

const int N = 300 + 13;

int n, m, t;
int a[N], next[N], has[N];
bool last[N];

inline bool read()
{
    if (scanf("%d%d%d", &n, &m, &t) != 3)
        return false;
        
    forn(i, n) assert(scanf("%d", &a[i]) == 1);
    
    memset(next, -1, sizeof(next));
    
    forn(i, m)
    {
        int a, b;
        assert(scanf("%d%d", &a, &b) == 2);
        --a, --b;
        next[a] = b;
        has[b] = true;
    }
    
    return true;
}

const int T = 100 * 1000 + 13;

int used[N], u;
int d[N][2][T];

inline bool check ()
{
    forn(i, n)
    {
        u++;
        int v = i;
        while (true)
        {
            if (used[v] == u) return true;
            used[v] = u;
            v = next[v];
            if (v == -1) break;
        }
    }
    
    return false;
}

const int mod = 1000 * 1000 * 1000 + 7;

inline void upd (int& next, int val)
{
    next += val;
    if (next >= mod) next -= mod;
}

inline void solve()
{
    if (check())
    {
        puts("0");
        return;
    }
    
    vector <int> idxs;
    
    forn(i, n)
        if (!has[i])
        {
            int v = i;
            idxs.clear();
            while (true)
            {
                idxs.pb(v);
                v = next[v];
                if (v == -1) break;
            }
            
            ford(j, sz(idxs))
                forn(k, j)
                    a[idxs[j]] += a[idxs[k]];
                    
            last[idxs.back()] = true;
        }
        
    d[0][0][0] = 1;
    
    forn(i, n)
        forn(j, 2)
            forn(k, t + 1)
            {
                const int& dv = d[i][j][k];
                
                if (last[i] || j == 1) upd(d[i + 1][0][k], dv);
                if (k + a[i] <= t) upd(d[i][1][k + a[i]], dv);
            }
            
    cout << d[n][0][t] << endl;
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