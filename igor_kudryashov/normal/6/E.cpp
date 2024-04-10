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

const int N = 100 * 1000 + 13;

int n, dif;
int a[N];
vector <int> hel, tel;
vector <int> hmax, tmax;
vector <int> hmin, tmin;

void push (int v)
{
    tel.pb(v);
    
    if (tmax.empty() || (!tmax.empty() && tmax.back() < v))
        tmax.pb(v);
    else
        tmax.pb(tmax.back());
        
    if (tmin.empty() || (!tmin.empty() && tmin.back() > v))
        tmin.pb(v);
    else
        tmin.pb(tmin.back());
}

int getMax ()
{
    int res = -1;
    
    if (!tmax.empty())
        res = max(res, tmax.back());
        
    if (!hmax.empty())
        res = max(res, hmax.back());
        
    assert(res != -1);
        
    return res;
}

int getMin ()
{
    int res = INF;
    
    if (!tmin.empty())
        res = min(res, tmin.back());
        
    if (!hmin.empty())
        res = min(res, hmin.back());
        
    assert(res != INF);
        
    return res; 
}

void pop ()
{
    if (hel.empty())
    {
        tmin.clear();
        tmax.clear();
    
        while (!tel.empty())
        {
            int cur = tel.back();
        
            hel.pb(tel.back());
            tel.pop_back();
            
            if (hmax.empty() || hmax.back() < cur)
                hmax.pb(cur);
            else
                hmax.pb(hmax.back());
                
            if (hmin.empty() || hmin.back() > cur)
                hmin.pb(cur);
            else
                hmin.pb(hmin.back());
        }
    }

    hel.pop_back();
    hmax.pop_back();
    hmin.pop_back();
}

int getSize ()
{
    return sz(hel) + sz(tel);
}

void clear ()
{
    hel.clear();
    hmax.clear();
    hmin.clear();
    
    tel.clear();
    tmax.clear();
    tmin.clear();
}

int main()
{
    
    cin >> n >> dif;
    
    forn(i, n)
        scanf("%d", &a[i]);
        
    int ans = 0;
    
    forn(i, n)
    {
        push(a[i]);
        
        while (getMax() - getMin() > dif)
            pop();
            
        ans = max(ans, getSize());
    }
    
    clear();
    
    vector <pt> res;
    
    forn(i, n)
    {
        push(a[i]);
        
        while (getMax() - getMin() > dif)
            pop();
        
        if (getSize() == ans)
            res.pb(mp(i - ans + 1, i));
    }
    
    cout << ans << ' ' << sz(res) << endl;
    
    forn(i, sz(res))
        printf("%d %d\n", res[i].ft + 1, res[i].sc + 1);

    return 0;
}