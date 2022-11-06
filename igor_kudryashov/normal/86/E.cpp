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

li c[51] = {
0LL,
0LL,
3LL, 
6LL,
12LL, 
23LL, 
54LL, 
85LL, 
150LL, 
408LL, 
562LL, 
1541LL, 
3002LL, 
5307LL, 
12208LL, 
20743LL, 
50381LL, 
124977LL, 
152029LL, 
359498LL, 
684180LL, 
1081539LL, 
3237552LL, 
7178036LL, 
14098937LL, 
17724970LL, 
59376847LL, 
84071740LL, 
203004953LL, 
317544656LL, 
604058870LL, 
2046199308LL, 
2204277251LL, 
8527213096LL, 
11816358072LL, 
20491257044LL, 
61947009164LL, 
126411736298LL, 
143599289310LL, 
499373316031LL, 
796020681876LL, 
1871509509299LL, 
3922069193205LL, 
7529257751876LL, 
17324782011524LL, 
29238521227978LL, 
53153974982529LL, 
102063103466563LL, 
196360980655640LL, 
312947656150253LL, 
966809786466498LL
};

li bit[60];

int main()
{
    forn(i, 60)
        bit[i] = (1LL << i);

    int n;  
    cin >> n;
    
    forn(i, n)
    {
        if (c[n] & bit[i])
            putchar('1');
        else
            putchar('0');
            
        putchar(' ');
    }
    
    puts("");
    
    forn(i, n)
        printf("1 ");
    
    puts("");
            
    return 0;
}