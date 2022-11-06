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

const int N = 10 * 1000 * 1000 + 3;

int a, n;
int lessDiv[N], degDiv[N], grSq[N];

void precalc ()
{
    memset(lessDiv, -1, sizeof(lessDiv));
    lessDiv[1] = 1;
    
    for (int i = 2; i < N; i++)
        if (lessDiv[i] == -1)
        {
            lessDiv[i] = i;
            degDiv[i] = 1;
            
            for (int j = 2 * i; j < N; j += i)
                if (lessDiv[j] == -1)
                    lessDiv[j] = i;
            
        } else
        {
            int prev = i / lessDiv[i];
            assert(lessDiv[prev] >= lessDiv[i]);
            
            if (lessDiv[prev] == lessDiv[i])
                degDiv[i] = degDiv[prev] + 1;
            else
                degDiv[i] = 1;
        }
        
    grSq[1] = 1;
    
    for (int i = 2; i < N; i++)
    {
        grSq[i] = grSq[i / lessDiv[i]];
        if ((degDiv[i] & 1) == 0) grSq[i] *= sqr(lessDiv[i]);
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    precalc();
    
    cin >> a >> n;
    
    li ans = 0;
    
    for (int i = a; i < a + n; i++)
        ans += i / grSq[i];
        
    cout << ans << endl;
    
    return 0;
}