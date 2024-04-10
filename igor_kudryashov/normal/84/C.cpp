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

const int N = 10 * 1000 + 13;

int n, m;
pt cir[N], xs[N];
int ans[N];

inline li dist2 (const pt& a, const pt& b)
{
    return sqr(li(a.ft - b.ft)) + sqr(li(a.sc - b.sc));
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    memset(ans, -1, sizeof(ans));
    
    cin >> n;
    
    forn(i, n)
    {
        scanf("%d%d", &cir[i].ft, &cir[i].sc);
        xs[i] = mp(cir[i].ft, i);
    }
    
    sort(xs, xs + n);
    
    cin >> m;
    
    forn(i, m)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        
        int k = int(lower_bound(xs, xs + n, mp(x, -1)) - xs);
        
        for (int dx = -3; dx <= 3; dx++)
        {
            if (k + dx < 0 || k + dx >= n)
                continue;
                
            int idx = xs[k + dx].sc;
            
            if (dist2(mp(cir[idx].ft, 0), mp(x, y)) <= sqr(li(cir[idx].sc)) && ans[idx] == -1)
                ans[idx] = i + 1;
        }
    }
    
    int cnt = 0;
    
    forn(i, n)
        cnt += ans[i] != -1;
        
    cout << cnt << endl;
    
    forn(i, n)
        printf("%d ", ans[i]);

    return 0;
}