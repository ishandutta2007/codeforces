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

const int N = 1000 + 13;

int n, k;
int next[N], prev[N];
vector <int> v;
int add;

inline bool read()
{
    if (scanf("%d%d", &n, &k) != 2)
        return false;
        
    --k;
        
    memset(prev, -1, sizeof(prev));
        
    forn(i, n)
    {
        assert(scanf("%d", &next[i]) == 1);
        next[i]--;
        if (next[i] != -1) prev[next[i]] = i;
    }
    
    return true;
}

bool d[N][N];

inline void solve()
{
    forn(i, n)
        if (prev[i] == -1)
        {
            vector <int> curv;
            int idx = -1;
            int cur = i;
            
            while (cur != -1)
            {
                if (cur == k) idx = sz(curv);
                curv.pb(cur);
                cur = next[cur];
            }
            
            if (idx == -1) v.pb(sz(curv));
            else add = sz(curv) - idx;
        }
        
    d[0][0] = true;
    
    forn(iter, sz(v))
        forn(i, N)
            if (d[iter][i])
            {
                d[iter + 1][i] = true;
                d[iter + 1][i + v[iter]] = true;
            }
            
    forn(i, N)
        if (d[sz(v)][i])
            printf("%d\n", i + add);
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