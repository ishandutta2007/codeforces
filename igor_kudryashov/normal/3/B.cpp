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

int n, v;
vector <pt> p[2];

int main()
{
    
    cin >> n >> v;
    
    forn(i, n)
    {
        int type, c;
        scanf("%d%d", &type, &c);
        --type;
        
        p[type].pb(mp(c, i));
    }
    
    forn(i, 2)
        sort(all(p[i]));
        
    int ans = 0;
    vector <int> res;
    
    if (v % 2 == 1 && !p[0].empty())
    {
        ans += p[0].back().ft;
        res.pb(p[0].back().sc);
        p[0].pop_back();
        v--;        
    }
    
    while (v > 1)
    {
        if (p[0].empty() && p[1].empty())
            break;
    
        if (p[0].empty())
        {
            ans += p[1].back().ft;
            res.pb(p[1].back().sc);
            p[1].pop_back();
            v -= 2;
        
        } else if (p[1].empty())
        {
            forn(i, 2)
            {
                if (p[0].empty())
                    break;
            
                ans += p[0].back().ft;
                res.pb(p[0].back().sc);
                p[0].pop_back();
                v -= 1;
            }
        } else
        {
            int t1 = p[1].back().ft;
            int t2 = (sz(p[0]) > 1 ? p[0][sz(p[0]) - 2].ft : 0) + p[0].back().ft;
            
            if (t1 > t2)
            {
                ans += p[1].back().ft;
                res.pb(p[1].back().sc);
                p[1].pop_back();
                v -= 2;
            } else
            {
                forn(i, 2)
                {
                    if (p[0].empty())
                        break;
                
                    ans += p[0].back().ft;
                    res.pb(p[0].back().sc);
                    p[0].pop_back();
                    v -= 1;
                }
            }           
        }
    }
    
    sort(all(res));
    
    cout << ans << endl;
    
    forn(i, sz(res))
        printf("%d ", res[i] + 1);

    return 0;
}