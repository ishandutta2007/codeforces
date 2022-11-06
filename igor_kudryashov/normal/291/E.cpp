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

const int M = 4;
const int mods[M] = {1000 * 1000 * 1000 + 7, 1000 * 1000 * 1000 + 9, 1000 * 1000 * 1000 + 11, 1000 * 1000 * 1000 + 13};
const int base[M] = {563, 1009, 31, 10007};

struct hash
{
    int h[M];
    hash () { memset(h, 0, sizeof(h)); }
};

inline hash operator - (const hash& a, const hash& b)
{
    hash c;
    forn(i, M) c.h[i] = (a.h[i] - b.h[i] + mods[i]) % mods[i];
    return c;
}

inline hash operator + (const hash& a, const hash& b)
{
    hash c;
    forn(i, M) c.h[i] = (a.h[i] + b.h[i]) % mods[i];
    return c;
}

inline hash operator * (int a, const hash& b)
{
    hash c;
    forn(i, M) c.h[i] = (b.h[i] * 1LL * a) % mods[i];
    return c;
}

inline hash operator * (const hash& a, const hash& b)
{
    hash c;
    forn(i, M) c.h[i] = (a.h[i] * 1LL * b.h[i]) % mods[i];
    return c;
}

inline bool operator == (const hash& a, const hash& b)
{
    forn(i, M) if (a.h[i] != b.h[i]) return false;
    return true;
}

const int N = 400 * 1000 + 13;
const int LOGN = 20;

int n, pr[N];
string s[N];
string t;
char buf[N];
vector <int> g[N];
int pch[N];
int p[N][LOGN];
hash h[N];
int dep[N];
int ans;
hash origin;
hash deg[N];

inline hash getDeg (int k) { return deg[k]; }

inline int getP (int v, int len)
{
    ford(i, LOGN)
        if (len - (1 << i) >= 0)
        {
            len -= (1 << i);
            v = p[v][i];
        }       
    return v;
}

inline void print (const hash& a)
{
    cerr << "(";
    forn(i, M) cerr << a.h[i] << ",";
    cerr << ") ";
}

void dfs (int v)
{
    //cerr << v << ' ' << pr[v] << ' ' << char(pch[v]) << endl;
    
    p[v][0] = pr[v];
    forl(i, LOGN - 1) p[v][i] = p[p[v][i - 1]][i - 1];
    
    if (v != 0)
    {
        dep[v] = dep[pr[v]] + 1;
        h[v] = h[pr[v]] + pch[v] * getDeg(dep[v]);
    }
    
    if (dep[v] >= sz(t))
    {
        int from = getP(v, sz(t));
        hash curh = h[v] - h[from];
        /*cerr << from << ' ' << v << ' ';
        print(curh);
        print(origin);
        cerr << endl;*/
        if (origin * getDeg(dep[from]) == curh) ans++;
    }
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        if (to != pr[v]) dfs(to);
    }
}

inline bool read()
{
    if (scanf("%d", &n) != 1)
        return false;
        
    forl(i, n - 1)
    {
        assert(scanf("%d", &pr[i]) == 1);
        pr[i]--;
        assert(scanf("%s", buf) == 1);
        s[i] = string(buf);
    }
    
    assert(scanf("%s", buf) == 1);
    t = string(buf);
    
    return true;
}

inline void solve()
{
    int on = n;
    forl(i, on - 1)
    {
        int last = pr[i];
        forn(j, sz(s[i]) - 1)
        {
            pch[n] = s[i][j];
            pr[n] = last;
            g[last].pb(n);
            last = n++;
        }
        pch[i] = s[i][sz(s[i]) - 1];
        pr[i] = last;
        g[last].pb(i);
    }
    
    //forn(i, n) cerr << i << ' ' << pr[i] << ' ' << char(pch[i]) << endl;
    
    forn(i, M) deg[0].h[i] = 1;
    forl(i, N - 1)
        forn(j, M)
            deg[i].h[j] = (deg[i - 1].h[j] * 1LL * base[j]) % mods[j];
    
    forn(i, sz(t)) origin = origin + t[i] * getDeg(i + 1);
    dfs(0);
    
    printf("%d\n", ans);
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