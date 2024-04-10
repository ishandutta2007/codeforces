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

int n, m;
vector <int> g[N];
int c[N];
vector <int> f1, f2;

void dfs (int v, int col)
{
    c[v] = col;
    if (col == 0)
        f1.pb(v);
    else
        f2.pb(v);
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        
        if (c[to] == -1)
            dfs(to, col ^ 1);
        else
            assert(c[to] == col ^ 1);
    }
}

int ans[N];

bool check2 ()
{
    if (sz(f2) % 3 == 1)
        swap(f1, f2);
        
    vector <int> v1, v2;
    
    forn(i, sz(f2))
    {
        int v = f2[i];
        if (sz(g[v]) > sz(f1) - 2) continue;
        
        set <int> neib;
        forn(j, sz(g[v]))
            neib.insert(g[v][j]);
            
        v1.pb(v);
        
        forn(j, sz(f1))
            if (!neib.count(f1[j]))
            {
                v1.pb(f1[j]);
                if (sz(v1) == 3)
                    break;
            }
            
        swap(v1, v2);
    }
    
    if (v1.empty())
        return false;
        
    forn(i, sz(v1))
        ans[v1[i]] = 0;
    forn(i, sz(v2)) 
        ans[v2[i]] = 1;
        
    f1.erase(find(all(f1), v1[1]));
    f1.erase(find(all(f1), v1[2]));
    f1.erase(find(all(f1), v2[1]));
    f1.erase(find(all(f1), v2[2]));
    f2.erase(find(all(f2), v1[0]));
    f2.erase(find(all(f2), v2[0]));
    
    int cur = 1;
    
    forn(i, sz(f1))
    {
        if (i % 3 == 0) cur++;
        ans[f1[i]] = cur;
    }
    forn(i, sz(f2))
    {
        if (i % 3 == 0) cur++;
        ans[f2[i]] = cur;
    }
    
    return true;
}

bool check1 ()
{
    if (sz(f1) % 3 == 2)
        swap(f1, f2);
        
    /*forn(i, sz(f1))
        cerr << f1[i] << ' ';
    cerr << endl;
    forn(i, sz(f2))
        cerr << f2[i] << ' ';
    cerr << endl;*/
        
    forn(i, sz(f1))
    {
        int v = f1[i];
        if (sz(g[v]) > sz(f2) - 2) continue;
        
        set <int> neib;
        forn(j, sz(g[v]))
            neib.insert(g[v][j]);
            
        vector <int> vs;
        
        forn(j, sz(f2))
        {
            int to = f2[j];
            if (!neib.count(to))
                vs.pb(f2[j]);
                
            if (sz(vs) == 2)
                break;
        }
        
        assert(sz(vs) == 2);
        
        ans[f1[i]] = 0;
        ans[vs[0]] = 0;
        ans[vs[1]] = 0;
        
        f2.erase(find(all(f2), vs[0]));
        f2.erase(find(all(f2), vs[1]));
        f1.erase(f1.begin() + i);
        
        assert(sz(f1) % 3 == 0 && sz(f2) % 3 == 0);
        
        int cur = 0;
        
        forn(j, sz(f1))
        {
            if (j % 3 == 0) cur++;
            ans[f1[j]] = cur;
        }
        
        forn(j, sz(f2))
        {
            if (j % 3 == 0) cur++;
            ans[f2[j]] = cur;
        }
        
        return true;    
    }
    
    return false;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m;
    
    forn(i, m)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    memset(c, -1, sizeof(c));
    
    forn(i, n)
        if (c[i] == -1)
            dfs(i, 0);
            
    if (sz(f1) % 3 == 0)
    {
        int cur = -1;
        forn(i, sz(f1))
        {
            if (i % 3 == 0) cur++;
            ans[f1[i]] = cur;
        }
        
        forn(i, sz(f2))
        {
            if (i % 3 == 0) cur++;
            ans[f2[i]] = cur;
        }
        
        puts("YES");
        
        forn(i, n)
            printf("%d ", ans[i] + 1);
            
        puts("");
        
    } else
    {
        if (check1() || check2())
        {
            puts("YES");
            forn(i, n)
                printf("%d ", ans[i] + 1);
            puts("");
        } else
            puts("NO");
    }

    return 0;
}