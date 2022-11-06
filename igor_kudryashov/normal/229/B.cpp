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
#define x first
#define y second
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
const int INF = 2000 * 1000 * 1000;

const int N = 100 * 1000 + 13;

int n, m;
vector <pt> g[N];
vector <int> t[N], next[N];
int d[N];
int used[N];
priority_queue <pt> q;

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m;
    
    forn(i, m)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        --a, --b;
        
        g[a].pb(mp(b, c));
        g[b].pb(mp(a, c));
    }
    
    forn(i, n)
    {   
        int cnt;
        scanf("%d", &cnt);
        
        if (i == n - 1) cnt = 0;
        
        forn(j, cnt)
        {
            int tmp;
            scanf("%d", &tmp);
            t[i].pb(tmp);
        }
        
        sort(all(t[i]));
        t[i].erase(unique(all(t[i])), t[i].end());
        
        next[i].resize(sz(t[i]));
        
        ford(j, sz(t[i]))
        {
            if (j == sz(t[i]) - 1 || t[i][j] + 1 != t[i][j + 1])
                next[i][j] = t[i][j] + 1;
            else
                next[i][j] = next[i][j + 1];
        }
    }
    
    forn(i, n) d[i] = INF;
    d[0] = 0;
    if (!t[0].empty() && t[0][0] == 0) d[0] = next[0][0];
    
    q.push(mp(-d[0], 0));
    
    while (!q.empty())
    {
        int v = q.top().sc;
        q.pop();
        
        if (used[v]) continue;
        used[v] = true;
        
        forn(i, sz(g[v]))
        {
            int to = g[v][i].ft, w = g[v][i].sc;
            
            int nd = d[v] + w;
            int idx = int(lower_bound(all(t[to]), nd) - t[to].begin());
            
            if (idx < sz(t[to]) && t[to][idx] == nd)
                nd = next[to][idx];
                
            if (d[to] > nd)
            {
                d[to] = nd;
                q.push(mp(-d[to], to));
            }
        }
    }
    
    if (d[n - 1] == INF)
    {
        puts("-1");
        return 0;
    }
    
    cout << d[n - 1] << endl;   
    
    return 0;
}