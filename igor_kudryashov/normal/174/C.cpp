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

const int N = 100 * 1000 + 13;

int n;
int a[N];
vector <int> pos[N];
vector <pt> ans;
int lfLess[N], rgLess[N];

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    a[0] = a[n + 1] = 0;
    for1(i, n)
    {
        scanf("%d", &a[i]);
        pos[a[i]].pb(i);
    }
    
    vector <pt> v;
    v.pb(mp(a[0], 0));
    
    for1(i, n)
    {
        while (sz(v) > 1 && v.back().ft >= a[i])
            v.pop_back();
        
        lfLess[i] = v.back().sc;
        v.pb(mp(a[i], i));
    }
    
    v.clear();
    v.pb(mp(a[n + 1], n + 1));
    
    for (int i = n; i >= 1; i--)
    {
        while (sz(v) > 1 && v.back().ft >= a[i])
            v.pop_back();
            
        rgLess[i] = v.back().sc;
        v.pb(mp(a[i], i));
    }
    
    for1(i, N - 1)
    {
        int maxRg = -1;
        
        forn(j, sz(pos[i]))
        {
            int curLf = lfLess[pos[i][j]], curRg = rgLess[pos[i][j]];
            
            if (curRg == maxRg)
                continue;
            else if (curLf >= maxRg)
            {
                int maxv = max(a[curLf], a[curRg]);
            
                forn(iter, i - maxv)
                    ans.pb(mp(curLf + 1, curRg - 1));
                    
                maxRg = curRg;
                
            } else
                throw;
        }
    }
    
    cout << sz(ans) << endl;
    
    forn(i, sz(ans))
        printf("%d %d\n", ans[i].ft, ans[i].sc);

    return 0;
}