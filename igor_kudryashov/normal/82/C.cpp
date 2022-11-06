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

const int N = 5000 + 13;

int n;
int numed[N][N];
int cap[N];
int p[N];
int prior[N];
pt divs[N];
vector <int> g[N];
int wher[N];
int ans[N];
int cur[N];

void dfs (int v, int pr)
{
    p[v] = pr;
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        
        if (to == pr)
            continue;
            
        dfs(to, v);
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    forn(i, n)
    {
        scanf("%d", &prior[i]);
        divs[i] = mp(prior[i], i);
    }
    
    sort(divs, divs + n);
    
    memset(numed, -1, sizeof(numed));
    forn(i, n - 1)
    {
        int a, b;
        scanf("%d%d%d", &a, &b, &cap[i]);
        --a, --b;
        g[a].pb(b);
        g[b].pb(a);
        numed[a][b] = numed[b][a] = i;
    }
    
    dfs(0, 0);
    
    forn(i, n)
        wher[i] = i;
        
    /*
    forn(i, n)
        cerr << divs[i].sc << ' ';
    cerr << endl;
    */
    
    int step = 0;
    while (true)
    {
        step++;
        memset(cur, 0, sizeof(cur));
        
        bool was = false;
        
        forn(idx, n)
        {
            int i = divs[idx].sc;
            
            if (wher[i] == 0)
                continue;
                
            int num = numed[wher[i]][p[wher[i]]];
            assert(num != -1);
            
            if (cur[num] + 1 > cap[num])
                continue;
                
            wher[i] = p[wher[i]];
            if (wher[i] == 0)
                ans[i] = step;
                
            cur[num]++;
            was = true;
        }
        
        if (!was)
            break;
    }
    
    forn(i, n)
        printf("%d ", ans[i]);
        
    puts("");

    return 0;
}