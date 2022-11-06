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
vector <pt> g[N];
int D = -1;
int num[N];
int used[N];

void dfs (int v, int curNum)
{
    used[v] = true;
    num[v] = curNum;
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i].ft, w = g[v][i].sc;
        
        if (num[to] != -1)
        {
            int delta = abs(num[to] - (curNum + w));
            if (delta != 0)
                D = delta;
        }
        
        if (!used[to])
            dfs(to, curNum + w);
    }
}

int K;

bool go (int v, int curNum)
{
    used[v] = true;
    num[v] = curNum;
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i].ft, w = g[v][i].sc;
        
        if (num[to] != -1 && num[to] != (curNum + w + K) % K)
            return true;
            
        if (!used[to] && go(to, (curNum + w + K) % K))
            return true;
    }
    
    return false;
}

bool check (int k)
{
    memset(num, -1, sizeof(num));
    memset(used, 0, sizeof(used));
    K = k;
    
    forn(i, n)
        if (!used[i] && go(i, 0))
            return false;
            
    return true;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    memset(num, -1, sizeof(num));
    
    cin >> n >> m;
    
    forn(i, m)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        
        g[a].pb(mp(b, 1));
        g[b].pb(mp(a, -1));
    }
    
    forn(i, n)
        if (!used[i])
            dfs(i, 0);
            
    if (D == -1)
    {
        cout << n << endl;
        return 0;
    }
    
    for (int i = D; i >= 1; i--)
        if (D % i == 0 && check(i))
        {
            cout << i << endl;
            return 0;
        }
        
    throw;

    return 0;
}