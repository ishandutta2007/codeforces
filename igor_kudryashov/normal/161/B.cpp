#pragma comment(linker, "/stack:64000000")

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <list>
#include <utility>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 1000 + 3;

int n, busk;
vector <int> g[N];
vector <pt> t;
vector <pt> p;

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> busk;
    
    li sum = 0;
    ld disc = 0.0;
    
    forn(i, n)
    {
        int c, type;
        scanf("%d%d", &c, &type);
        
        if (type == 1)
            t.pb(mp(c, i));
        else
            p.pb(mp(c, i));
            
        sum += c;
    }
    
    sort(all(t));
    sort(all(p));
    
    if (sz(t) >= busk)
    {
        reverse(all(t));
        forn(i, busk)
        {
            g[i].pb(t[i].sc);
            if (i < busk - 1)
                disc += t[i].ft / 2.0;
        }
        
        ld minv = t.back().ft;
        if (!p.empty())
            minv = min(minv, ld(p[0].ft));
            
        disc += minv / 2.0;
        
        for (int i = busk; i < sz(t); i++)
            g[busk - 1].pb(t[i].sc);
            
        forn(i, sz(p))
            g[busk - 1].pb(p[i].sc);
    
    } else
    {
        forn(i, sz(t))
        {
            g[i].pb(t[i].sc);
            disc += t[i].ft / 2.0;
        }
            
        int idx = sz(t);
        forn(i, sz(p))
        {
            g[idx].pb(p[i].sc);
            idx++;
            if (idx == busk) idx--;
        }
    }
    
    cout << setprecision(1) << fixed;
    cout << ld(sum - disc) << endl;
    
    forn(i, busk)
    {
        printf("%d ", sz(g[i]));
        
        forn(j, sz(g[i]))
            printf("%d ", g[i][j] + 1);
            
        puts("");
    }

    return 0;
}