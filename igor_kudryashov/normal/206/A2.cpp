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

int n;
vector <int> c[2];
vector <pt> ans;

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    forn(i, n)
    {
        int cnt, a0, x, y, m;
        scanf("%d%d%d%d%d", &cnt, &a0, &x, &y, &m);
        
        c[i].pb(a0);
        
        forn(j, cnt - 1)
            c[i].pb((c[i].back() * 1LL * x + y) % m);
    }
    
    int it1 = 0, it2 = 0;
    
    if (c[0][0] < c[1][0])
        ans.pb(mp(c[0][0], 0)), it1++;
    else
        ans.pb(mp(c[1][0], 1)), it2++;
    
    while (it1 < sz(c[0]) && it2 < sz(c[1]))
    {
        if (c[0][it1] < ans.back().ft && c[1][it2] >= ans.back().ft)
            ans.pb(mp(c[1][it2++], 1));
        else if (c[1][it2] < ans.back().ft && c[0][it1] >= ans.back().ft)
            ans.pb(mp(c[0][it1++], 0));
        else
        {
            if (c[0][it1] < c[1][it2])
                ans.pb(mp(c[0][it1++], 0));
            else
                ans.pb(mp(c[1][it2++], 1));             
        }
    }
    
    while (it1 < sz(c[0]))
        ans.pb(mp(c[0][it1++], 0));
        
    while (it2 < sz(c[1]))
        ans.pb(mp(c[1][it2++], 1));
        
    int res = 0;
    
    forn(i, sz(ans) - 1)
        if (ans[i + 1].ft < ans[i].ft)
            res++;
            
    cout << res << endl;
    
    if (sz(ans) <= 200 * 1000)
    {
        forn(i, sz(ans))
            printf("%d %d\n", ans[i].ft, ans[i].sc + 1);
    }
        
    return 0;
}