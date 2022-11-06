#undef NDEBUG
#ifdef SU2_PROJ
#define _GLIBCXX_DEBUG
#endif

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
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
template<typename X, typename Y> inline ostream& operator<< (ostream& out, const pair <X, Y>& p) { return out << '(' << p.x << ", " << p.y << ')'; }
template<typename X> inline ostream& operator<< (ostream& out, const vector<X>& p) { forn(i, sz(p)) { if (i != 0) out << ' '; out << p[i]; } return out; }
inline void clocks() {
    #ifdef SU2_PROJ
        cerr << "=== TIME: " << ld(clock()) / CLOCKS_PER_SEC << " sec ===" << endl;
    #endif
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
inline void makeVariablesUsed() { int a = INF; li b = INF64; ld c = EPS, d = PI; d = a * b + c; }

#define V first
#define L second

struct node
{
    int lf, rg, p, link;
    map <char, int> next;
    
    node (int lf = 0, int rg = 0, int p = -1, int link = -1) : lf(lf), rg(rg), p(p), link(link) {}
    
    int& operator [] (char c)
    {
        if (!next.count(c))
            next[c] = -1;
            
        return next[c];
    }
};

const int N = 1000 * 1000 + 13;
const int mod = 1000 * 1000 * 1000 + 7;

int n;
char s[N];
string ss[3];
node t[N];
int szt;

inline int leng (int v)
{
    return t[v].rg - t[v].lf;
}

int addVertex (int p, int lf, int rg)
{
    t[szt] = node(lf, rg, p, -1);
    t[p][s[lf]] = szt;
    return szt++;
}

int split (pt ptr)
{
    int v = ptr.V, up = ptr.L, down = leng(v) - up;
    
    if (up == 0)
        return v;
        
    if (down == 0)
        return t[v].p;
        
    int mid = addVertex(t[v].p, t[v].lf, t[v].lf + down);
    t[v].lf += down, t[v].p = mid;
    t[mid][s[t[v].lf]] = v;
    
    return mid;
}

pt down (int v, int lf, int rg)
{
    if (lf == rg)
        return mp(v, 0);
        
    while (true)
    {
        v = t[v][s[lf]];

        if (leng(v) >= rg - lf)
            return mp(v, leng(v) - (rg - lf));
            
        lf += leng(v);
    }
    
    throw;
}

int link (int v)
{
    if (t[v].link == -1)
        return t[v].link = split(down(link(t[v].p), t[v].lf + (t[v].p == 0), t[v].rg));
        
    return t[v].link;
}

pt go (pt ptr, char c)
{
    int v = ptr.V, up = ptr.L;
    
    if (up != 0)
        return s[t[v].rg - up] == c ? mp(v, up - 1) : mp(-1, -1);
        
    v = t[v][c];
    
    return v == -1 ? mp(-1, -1) : mp(v, leng(v) - 1);
}

pt addChar (pt ptr, int pos)
{
    while (true)
    {
        pt nptr = go(ptr, s[pos]);
        if (nptr.V != -1)
            return nptr;
            
        int v = split(ptr);
        addVertex(v, pos, n);
        
        if (v == 0)
            return mp(0, 0);
            
        ptr = mp(link(v), 0);
    }
    
    throw;
}

void makeTree ()
{
    szt = 0;
    t[szt++] = node(0, 0, -1, 0);
    
    pt ptr = mp(0, 0);
    
    forn(i, n)
        ptr = addChar(ptr, i);
}

char buf[N];
int numstr[N];

inline bool read()
{
    forn(i, 3)
    {
        assert(scanf("%s", buf) == 1);
        ss[i] = string(buf);
        forn(j, sz(ss[i]))
        {
            numstr[n] = i;
            s[n++] = ss[i][j];
        }
        numstr[n] = i;
        s[n++] = char('0' + i);
    }
    return true;
}

int ans[N];
int cnt[N][3];

inline int mult (int a, int b)
{
    li c = li(a) * b;
    if (c >= mod) c %= mod;
    return int(c);
}

inline int add (int a, int b)
{
    a += b;
    while (a < 0) a += mod;
    while (a >= mod) a -= mod;
    return a;
}

inline void upd (int lf, int rg, int val)
{
    ans[lf] = add(ans[lf], val);
    ans[rg + 1] = add(ans[rg + 1], -val);
}

void dfs (int v, int len)
{
    len += leng(v);
    if (t[v].next.empty())
    {
        cnt[v][numstr[n - len]]++;
        return;
    }

    for (map <char, int> :: iterator it = t[v].next.begin(); it != t[v].next.end(); it++)
    {
        dfs(it->sc, len);
        forn(i, 3) cnt[v][i] += cnt[it->sc][i];
    }

    int cur = 1;
    forn(i, 3) cur = mult(cur, cnt[v][i]);

    upd(len - leng(v) + 1, len, cur);
}

inline void solve()
{
    makeTree();
    dfs(0, 0);

    int minv = INF;
    forn(i, 3) minv = min(minv, sz(ss[i]));

    forl(i, minv)
    {
        ans[i] = add(ans[i], ans[i - 1]);
        printf("%d ", ans[i]);
    }
    puts("");
}

int main()
{
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

    assert(read());
    solve();
    clocks();

    return 0;
}