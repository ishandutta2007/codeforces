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
#define for1(i, n) for (int i = 1; i <= int(n); i++)
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

const int N = 50 * 1000 + 3;
const int K = 500 + 3;

int n, k;
vector <int> g[N];
int d[N][K];
li ans1, ans2;

void dfs (int v, int p)
{
    d[v][0] = 1;

    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        if (to == p) continue;
        
        dfs(to, v);
        
        for1(j, k)
            d[v][j] += d[to][j - 1];
    }
    
    ans2 += d[v][k];
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        if (to == p) continue;
        
        forn(j, k - 1)
        {
            int c1 = d[to][j];
            int c2 = d[v][k - 1 - j] - d[to][k - 2 - j];
            
            ans1 += c1 * 1LL * c2;
        }
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> k;
    
    forn(i, n - 1)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    dfs(0, 0);
    
    assert(ans1 % 2 == 0);
    ans1 /= 2;
    
    cout << ans1 + ans2 << endl;

    return 0;
}