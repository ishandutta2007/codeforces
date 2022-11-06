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
#define x first
#define y second
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

const int N = 100 + 3;

int n, m, k;
int g[N][N];

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> m;
    
    while (k * (k - 1) * (k - 2) / 6 <= m) k++;
    k--;
    
    forn(i, k)
        forn(j, k)
            g[i][j] = (i == j ? 0 : 1);
            
    m -= k * (k - 1) * (k - 2) / 6;
    
    n = k;
    
    while (m > 0)
    {
        int cur = 0;
        while (cur * (cur - 1) / 2 <= m) cur++;
        cur--;
        
        forn(i, cur) g[i][n] = g[n][i] = 1;
        n++;
        m -= cur * (cur - 1) / 2;
    }
    
    assert(m == 0);
    
    assert(n <= 100);
    
    cout << n << endl;
    
    forn(i, n)
    {
        forn(j, n)
            printf("%d", g[i][j]);
        puts("");
    }
    
    return 0;
}