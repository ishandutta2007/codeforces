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
typedef pair <int, int> pt;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;

const int N = 100 * 1000 + 13;

int n, h;
int ans = INF;
int minv = INF, minidx = -1;
int res[N];
int a[N];

int main()
{
    
    cin >> n >> h;
    
    forn(i, n)
    {
        scanf("%d", &a[i]);
        if (a[i] < minv)
            minv = a[i], minidx = i;
    }
    
    sort(a, a + n);
    
    {
        int min1 = a[0] + a[1], max1 = a[n - 1] + a[n - 2];
        ans = max1 - min1;
    }
    
    {
        int min2 = (n == 2 ? a[0] + a[1] + h : min(a[0] + a[1] + h, a[1] + a[2]));
        int max2 = (n == 2 ? a[0] + a[1] + h : max(a[n - 1] + a[n - 2], a[0] + a[n - 1] + h));
        
        if (ans > max2 - min2)
        {
            ans = max2 - min2;
            res[minidx] = 1;
        }
    }
    
    cout << ans << endl;
    
    forn(i, n)
        printf("%d ", res[i] + 1);
    
    puts("");
    
    return 0;
}