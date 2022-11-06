#pragma comment(linker, "/stack:64000000")
#define _SECURE_SCL 0
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
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

int n, w, h;
vector <pair <pt, int> > v;
int d[N];
int p[N];

int main()
{
    
    cin >> n >> w >> h;
    
    forn(i, n)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        
        v.pb(mp(mp(a, b), i));
    }
    
    sort(all(v));
    
    int ans = 0;
    int ansid = -1;
    
    forn(i, n)
    {
        int maxv = 0, idx = -1;
    
        forn(j, i)
            if (d[j] > 0 && v[i].ft.ft > v[j].ft.ft && v[i].ft.sc > v[j].ft.sc && d[j] > maxv)
            {
                maxv = d[j];
                idx = j;
            }
            
        if (maxv > 0)
        {
            d[i] = maxv + 1;
            p[i] = idx;
        } else if (v[i].ft.ft > w && v[i].ft.sc > h)
        {
            d[i] = 1;
            p[i] = i;
        }
        
        if (d[i] > ans)
            ans = d[i], ansid = i;
    }
    
    if (ans == 0)
        puts("0");
    else 
    {
        vector <int> res;
        
        int u;
        for (u = ansid; u != p[u]; u = p[u])
            res.pb(v[u].sc);
        res.pb(v[u].sc);
        
        reverse(all(res));
        
        cout << sz(res) << endl;
        
        forn(i, sz(res))
            printf("%d ", res[i] + 1);
            
        puts("");
    }

    return 0;
}