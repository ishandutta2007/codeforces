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

const int N = 5 * 1000 * 1000 + 13;

int n;
char s[N];
int d1[N], d2[N];
int k[N];

int main()
{

    scanf("%s", s);
    
    n = strlen(s);
    
    int lf = 0, rg = -1;
    
    forn(i, n)
    {
        if (i <= rg)
            d1[i] = min(d1[lf + (rg - i)], rg - i + 1);
            
        while (i + d1[i] < n && i - d1[i] >= 0 && s[i + d1[i]] == s[i - d1[i]])
            d1[i]++;
            
        if (rg < i + d1[i] - 1)
            rg = i + d1[i] - 1, lf = i - d1[i] + 1;
    }
    
    lf = 0, rg = -1;
    
    forn(i, n)
    {
        if (i <= rg)
            d2[i] = min(d2[lf + (rg - i)], rg - i);
            
        while (i + d2[i] < n && i - 1 - d2[i] >= 0 && s[i + d2[i]] == s[i - 1 - d2[i]])
            d2[i]++;
            
        if (rg < i + d2[i])
            rg = i + d2[i], lf = i - d2[i];
    }
    
    li ans = 0;
    int cur = 0;
    
    k[0] = 1;
    for1(i, n - 1)
    {
        if (i - d2[i] == 0)
            k[i + d2[i] - 1] = k[i - 1] + 1;
            
        if (i - d1[i] + 1 == 0)
            k[i + d1[i] - 1] = k[i - 1] + 1;
    }
    
    forn(i, n)
        ans += k[i];
    
    cout << ans << endl;

    /*
    forn(i, n)
        cerr << d1[i] << ' ';
    cerr << endl;
    
    forn(i, n)
        cerr << d2[i] << ' ';
    cerr << endl;
    */
    
    return 0;
}