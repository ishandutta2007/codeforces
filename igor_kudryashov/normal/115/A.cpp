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

const int N = 2000 + 13;

int n;
vector <int> g[N];
int deg[N];
int used[N];

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    forn(i, n)
    {
        int par;
        scanf("%d", &par);
        
        if (par == -1)
            continue;
        else
            par--;
            
        deg[i]++;
        g[par].pb(i);
    }
    
    int cnt = 0;
    
    while (true)
    {
        vector <int> cur;
    
        forn(i, n)
        {
            if (deg[i] != 0 || used[i])
                continue;
                
            cur.pb(i);
        }
        
        if (cur.empty())
            break;
            
        cnt++;
        forn(i, sz(cur))
        {
            used[cur[i]] = true;
            forn(j, sz(g[cur[i]]))
            {
                int to = g[cur[i]][j];
                
                deg[to]--;
            }
        }
    }
    
    cout << cnt << endl;

    return 0;
}