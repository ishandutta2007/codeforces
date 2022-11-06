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

struct man
{
    string name;
    int cntTaxi, cntPizza, cntGirls;
    
    man () {}
};

inline bool isTaxi (string s)
{
    vector <char> c;
    forn(i, sz(s))
        if (s[i] != '-')
            c.pb(s[i]);
            
    forn(i, sz(c))
        if (c[i] != c[0])
            return false;
                
    return true;
}

inline bool isPizza (string s)
{
    vector <char> c;
    forn(i, sz(s))
        if (s[i] != '-')
            c.pb(s[i]);
            
    forn(i, sz(c))
        forn(j, i)
            if (c[j] <= c[i])
                return false;
                
    return true;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    int cntMen;
    cin >> cntMen;
    
    vector <man> v;
    
    int maxTaxi = -1, maxPizza = -1, maxGirls = -1;
    
    forn(iter, cntMen)
    {
        v.pb(man());
        
        int cntNumb;
        cin >> cntNumb;
        cin >> v.back().name;
        
        forn(i, cntNumb)
        {
            string s;
            cin >> s;
            
            if (isTaxi(s))
                v.back().cntTaxi++;
            else if (isPizza(s))
                v.back().cntPizza++;
            else
                v.back().cntGirls++;
        }
        
        maxTaxi = max(maxTaxi, v.back().cntTaxi);
        maxPizza = max(maxPizza, v.back().cntPizza);
        maxGirls = max(maxGirls, v.back().cntGirls);
    }
    
    bool fir = true;
    
    printf("If you want to call a taxi, you should call:");
    forn(i, cntMen)
        if (v[i].cntTaxi == maxTaxi)
        {
            if (!fir) putchar(',');
            fir = false;
            printf(" %s", v[i].name.c_str());
        }
    puts(".");
    
    fir = true;
    
    printf("If you want to order a pizza, you should call:");
    forn(i, cntMen)
        if (v[i].cntPizza == maxPizza)
        {
            if (!fir) putchar(',');
            fir = false;
            printf(" %s", v[i].name.c_str());
        }
    puts(".");
    
    fir = true;
    
    printf("If you want to go to a cafe with a wonderful girl, you should call:");
    forn(i, cntMen)
        if (v[i].cntGirls == maxGirls)
        {
            if (!fir) putchar(',');
            fir = false;
            printf(" %s", v[i].name.c_str());
        }       
    puts(".");
    
    return 0;
}