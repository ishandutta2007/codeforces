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

const int N = 200 * 1000 + 13;

int n;
int x[N];

inline bool can (ld mid, bool write)
{
    vector <ld> ans;
    
    int st = 0;
    
    for1(i, n)
    {
        if (x[i] - x[st] > 2 * mid + EPS || i == n)
        {
            ans.pb(x[st] + (x[i - 1] - x[st]) / 2.0);
            
            st = i;
        }
        
        if (sz(ans) > 3)
            return false;
    }
    
    while (sz(ans) < 3)
        ans.pb(0);
        
    sort(all(ans));
        
    assert(sz(ans) == 3);
    
    if (write)
    {
        cout << setprecision(8) << fixed;
        
        cout << mid << endl;
    
        forn(i, 3)
            cout << ans[i] << ' ';
            
        cout << endl;           
    }
    
    return true;    
}

int main()
{
    
    cin >> n;
    
    forn(i, n)
        scanf("%d", &x[i]);
        
    sort(x, x + n);
    
    ld lf = 0.0, rg = 1e9;
    
    forn(i, 200)
    {
        ld mid = (lf + rg) / 2.0;
        
        if (can(mid, false))
            rg = mid;
        else
            lf = mid;
    }
    
    assert(can(rg, true));

    return 0;
}