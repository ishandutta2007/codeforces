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

const int N = 200 + 13;

int n;
int c[N];
vector <int> g[N];
int din[N];
int old[N];

int solve (int start)
{
    forn(i, n)
        old[i] = din[i];
    
    set <pt> s;
    
    forn(i, n)
        if (din[i] == 0)
            s.insert(mp(c[i], i));
            
    int res = n;
    int col = start;
            
    while (!s.empty())
    {
        set <pt> :: iterator it = s.lower_bound(mp(col, -1));
        if (it == s.end()) it = s.begin();
        
        int nextcol = it->ft, v = it->sc;
        s.erase(it);
        
        if (nextcol < col)
            res += nextcol + 3 - col;
        else
            res += nextcol - col;
            
        col = nextcol;
            
        forn(i, sz(g[v]))
        {
            int to = g[v][i];
            assert(din[to] > 0);
            din[to]--;
            if (din[to] == 0)
                s.insert(mp(c[to], to));
        }
    }
        
    forn(i, n)
        din[i] = old[i];
        
    return res;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    forn(i, n)
        scanf("%d", &c[i]), c[i]--;
        
    forn(i, n)
    {
        int cnt;
        scanf("%d", &cnt);
        
        forn(j, cnt)
        {
            int from;
            scanf("%d", &from);
            --from;
            g[from].pb(i);
        }
        
        din[i] = cnt;
    }
    
    int ans = INF;
    
    forn(i, 3)
        ans = min(ans, solve(i));
        
    cout << ans << endl;    
    
    return 0;
}