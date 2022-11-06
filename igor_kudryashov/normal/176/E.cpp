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

const int N = 100 * 1000 + 3;
const int LOGN = 20;

int n, m;
vector <pt> g[N];
li ans;
int p[N][LOGN];
li len[N][LOGN];
int num[N], curn;
set <pt> s;
int tin[N], tout[N], t;

inline bool parent (int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

li Len (int a, int b) // b is parent of a
{
    li res = 0LL;
    
    ford(i, LOGN)
        if (parent(b, p[a][i]))
        {
            res += len[a][i];
            a = p[a][i];
        }
        
    return res;
}

int lca (int a, int b)
{
    if (parent(a, b)) return a;
    if (parent(b, a)) return b;
    
    ford(i, LOGN)
        if (!parent(p[a][i], b))
            a = p[a][i];
            
    assert(!parent(a, b) && parent(p[a][0], b));
    return p[a][0]; 
}

li getLen (int a, int b)
{
    if (a == b) return 0LL;
    int c = lca(a, b);
    return Len(a, c) + Len(b, c);
}

void add (int v)
{
    s.insert(mp(num[v], v));
    
    if (sz(s) == 1)
        return;
    
    set <pt> :: iterator it = s.lower_bound(mp(num[v], v));
    
    int leftV = -1, rightV = -1;
    
    if (it == s.begin())
        leftV = (--s.end())->sc;
    else
    {
        it--;
        leftV = it->sc;
        it++;
    }
    
    it++;
    if (it == s.end())
        rightV = s.begin()->sc;
    else
        rightV = it->sc;
        
    ans -= getLen(leftV, rightV);
    ans += getLen(leftV, v);
    ans += getLen(v, rightV);
}

void remove (int v)
{
    if (sz(s) == 1)
    {
        s.clear();
        return;
    }
    
    set <pt> :: iterator it = s.lower_bound(mp(num[v], v));
    
    int leftV = -1, rightV = -1;
    
    if (it == s.begin())
        leftV = (--s.end())->sc;
    else
    {
        it--;
        leftV = it->sc;
        it++;
    }
    
    it++;
    if (it == s.end())
        rightV = s.begin()->sc;
    else
        rightV = it->sc;
    it--;
    
    s.erase(it);
        
    ans -= getLen(leftV, v);
    ans -= getLen(v, rightV);
    ans += getLen(leftV, rightV);   
}

void dfs (int v, int pr, int plen)
{
    tin[v] = t++;
    num[v] = curn++;
    p[v][0] = pr;
    len[v][0] = plen;
    
    for1(i, LOGN - 1)
    {
        p[v][i] = p[p[v][i - 1]][i - 1];
        len[v][i] = len[v][i - 1] + len[p[v][i - 1]][i - 1];
    }
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i].ft, w = g[v][i].sc;
        if (to != pr)
            dfs(to, v, w);
    }
    tout[v] = t++;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    scanf("%d\n", &n);
    
    forn(i, n - 1)
    {
        int a, b, c;
        scanf("%d %d %d\n", &a, &b, &c);
        --a, --b;
        g[a].pb(mp(b, c));
        g[b].pb(mp(a, c));
    }
    
    dfs(0, 0, 0);
    
    scanf("%d\n", &m);
    
    forn(i, m)
    {
        char type;
        scanf("%c", &type);
        if (type == '?')
        {
            scanf("\n");
            printf("%I64d\n", (ans >> 1));
            
        } else
        {
            int v;
            scanf("%d\n", &v);
            --v;
            if (type == '+')
                add(v);
            else
                remove(v);
        } 
    }   

    return 0;
}