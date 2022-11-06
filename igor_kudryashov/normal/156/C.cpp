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

const int N = 3000 + 3;
const int mod = 1000 * 1000 * 1000 + 7;

int d[N][105];
char buf[N];

int solve (int n, int k)
{
    int& ans = d[n][k];
    if (ans != -1)
        return ans;
        
    if (k == 0)
        return ans = (n == 0);
        
    ans = 0;
    
    forn(i, min(n, 25) + 1)
    {
        ans += solve(n - i, k - 1);
        while (ans >= mod) ans -= mod;
    }
    
    return ans;
}

int solve ()
{
    int k = strlen(buf);
    int s = 0;
    
    forn(i, k)
        s += (buf[i] - 'a');
        
    return solve(s, k);
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    int testCount;
    scanf("%d\n", &testCount);
    
    memset(d, -1, sizeof(d));
    
    forn(test, testCount)
    {
        gets(buf);
        printf("%d\n", solve() - 1);
    }

    return 0;
}