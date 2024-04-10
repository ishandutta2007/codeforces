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
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
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
typedef long long li;
typedef pair <li, li> pt;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;

vector <pt> v;

inline bool check (li x1, li r1, li x2, li r2)
{
    return sqr(x1 - x2) + sqr(r1 - r2) >= sqr(r1 + r2);
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    v.pb(mp(0, 1000 * 1000));
    
    for (li x = 0; ; x++)
        if (sqr(x) + sqr(v[0].sc - 300) >= sqr(v[0].sc + 300))
        {
            v.pb(mp(x, 300));
            break;
        }
        
    assert(check(v[0].ft, v[0].sc, v[1].ft, v[1].sc));
        
    for (int r = 299; r > 0; r--)
        v.pb(mp(v.back().ft + v.back().sc + r, r));
        
    for (li x = v.back().ft + 1; ; x++)
    {
        bool ok = true;
        
        forn(i, 300)
            if (!check(x, 1000 * 1000, v[sz(v) - 1 - i].ft, v[sz(v) - 1 - i].sc))
            {
                ok = false;
                break;
            }
            
        if (ok)
        {
            v.pb(mp(x, 1000 * 1000));
            break;
        }
    }
        
    assert(!check(v[0].ft, v[0].sc, v.back().ft, v.back().sc));
    
    cout << sz(v) << endl;
    
    forn(i, sz(v))
        cout << v[i].ft << ' ' << v[i].sc << endl;
        
    return 0;
}