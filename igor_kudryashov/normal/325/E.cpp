#undef NDEBUG
#ifdef SU2_PROJ
#define _GLIBCXX_DEBUG
#endif

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

int n;
vector <int> perm;
int pos[N][2];
vector <int> s;
vector <int> g[N];

void dfs (int v)
{
    while (!g[v].empty())
    {
        int to = g[v].back();
        g[v].pop_back();
        dfs(to);
    }
    perm.pb(v);
}

inline bool read()
{
    return cin >> n;
}

inline void solve()
{
    if (n % 2 == 1)
    {
        puts("-1");
        return;
    }
    
    if (n == 2)
    {
        puts("0 1 0");
        return;
    }
    
    forn(i, n / 2)
    {
        g[i].pb((2 * i) % (n / 2));
        g[i].pb((2 * i + 1) % (n / 2));     
    }
    
    dfs(0);
    reverse(all(perm));
    
    //forn(i, sz(perm)) cerr << perm[i] << ' '; cerr << endl;
    
    s = vector <int> (sz(perm), -1);
    s.back() = 0;
    memset(pos, -1, sizeof(pos));
    
    forn(i, sz(perm) - 1)
        if (pos[perm[i]][0] == -1)
            pos[perm[i]][0] = i;
        else
            pos[perm[i]][1] = i;
            
    forn(i, sz(perm) - 1)
        if ((perm[i] * 2 + 1) % (n / 2) == perm[i + 1])
        {
            int npos = pos[perm[i]][0];
            if (pos[perm[i]][0] == i) npos = pos[perm[i]][1];
            assert(s[i] == -1 && s[npos] == -1);
            s[i] = 1, s[npos] = 0;
        }
        
    //forn(i, sz(s)) cerr << s[i] << ' '; cerr << endl;
    
    perm.pop_back();
    s.pop_back();
    perm.insert(perm.begin(), 0);
    s.insert(s.begin(), 0);
    
    vector <int> used(n, 0);
    
    forn(i, sz(perm) - 1)
    {
        int cur = perm[i] * 2 + s[i];
        int next = perm[i + 1] * 2 + s[i + 1];
        assert(next == (cur * 2) % n || next == (cur * 2 + 1) % n);
        used[cur] = true;
    }
    
    forn(i, n) assert(used[i]);
        
    forn(i, sz(perm)) printf("%d ", perm[i] * 2 + s[i]);
    puts("");
}

int main()
{
#ifdef SU2_PROJ
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    assert(read());
    solve();
    
    return 0;
}