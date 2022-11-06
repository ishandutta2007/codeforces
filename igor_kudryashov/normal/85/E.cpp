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
const int mod = 1000 * 1000 * 1000 + 7;

int n;
int x[N], y[N];
int c[N];
int len;

bool dfs (int v, int col)
{
    c[v] = col;
    
    forn(i, n)
    {
        int d = abs(x[v] - x[i]) + abs(y[v] - y[i]);
        
        if (d <= len)
            continue;
            
        if (c[i] != -1 && c[i] != c[v] ^ 1)
            return true;
            
        if (c[i] == -1 && dfs(i, col ^ 1))
            return true;
    }
    
    return false;
}

bool bipartite (int mid)
{
    len = mid;

    memset(c, -1, sizeof(c));
    
    forn(i, n)
        if (c[i] == -1 && dfs(i, 0))
            return false;
            
    return true;
}

int cntComp (int mid)
{
    len = mid;
    memset(c, -1, sizeof(c));
    
    int res = 0;

    forn(i, n)
        if (c[i] == -1)
        {
            assert(!dfs(i, 0));
            res++;
        }
        
    return res;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    forn(i, n)
        scanf("%d%d", &x[i], &y[i]);
        
    int lf = 0, rg = 10000;
    
    while (lf != rg)
    {
        int mid = (lf + rg) / 2;
        
        if (bipartite(mid))
            rg = mid;
        else
            lf = mid + 1;
    }
    
    int comp = cntComp(lf);
    int ans = 1;

    forn(i, comp)
        ans = (ans * 2) % mod;
        
    cout << lf << endl << ans << endl;

    return 0;
}