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

const int P = 2003;
const int N = 30 + 3;

int n;
int a[N];
bool can[(1 << 16) + 3][P];
int bit[30];
int f[N][N];
int sumc[5], sumr[5], sumd1, sumd2, curSum;
int nn;
int sums[(1 << 16) + 3];
int minv[(1 << 16) + 3];
int maxv[(1 << 16) + 3];

inline bool check (int x, int y, int mask)
{
    int revMask = mask ^ (bit[nn] - 1);
    
    if (sumr[x] + maxv[revMask] * (n - 1 - y) < curSum)
        return false;
    if (sumr[x] + minv[revMask] * (n - 1 - y) > curSum)
        return false;
    if (sumc[y] + maxv[revMask] * (n - 1 - x) < curSum)
        return false;
    if (sumc[y] + minv[revMask] * (n - 1 - x) > curSum)
        return false;

    int remC = curSum - sumc[y];
    if (abs(remC) > P) remC %= P;
    if (remC < 0) remC += P;
    if (!can[revMask][remC]) return false;
    
    int remR = curSum - sumr[y];
    if (abs(remR) > P) remR %= P;
    if (remR < 0) remR += P;
    if (!can[revMask][remR]) return false;
    
    if (x == y)
    {
        int remD1 = curSum - sumd1;
        if (abs(remD1) > P) remD1 %= P;
        if (remD1 < 0) remD1 += P;
        if (!can[revMask][remD1]) return false;
    }
    
    if (x == n - 1 - y)
    {
        int remD2 = curSum - sumd2;
        if (abs(remD2) > P) remD2 %= P;
        if (remD2 < 0) remD2 += P;
        if (!can[revMask][remD2]) return false;
    }

    return true;
}

void go (int x, int y, int mask)
{
    if (y == n) return go(x + 1, 0, mask);
    if (x == n)
    {
        cout << curSum << endl;
        forn(i, n)
        {
            forn(j, n)
                cout << f[i][j] << ' ';
            cout << endl;
        }
        exit(0);
    }
    
    forn(i, nn)
    {
        if (mask & bit[i]) continue;
        int cura = a[i];
        
        if (x > 0 && y == n - 1 && cura != curSum - sumr[x])
            continue;
            
        if (x == n - 1 && (cura != curSum - sumc[y] || (y == 0 && cura != curSum - sumd2)
                                                    || (y == n - 1 && cura != curSum - sumd1)))
            continue;
            
        if (x == 0)
        {
            curSum += cura;
            sumr[x] += cura;
            sumc[y] += cura;
            if (x == y) sumd1 += cura;
            if (x == n - 1 - y) sumd2 += cura;
            f[x][y] = cura;
            
            go(x, y + 1, mask ^ bit[i]);
            
            curSum -= cura;
            sumr[x] -= cura;
            sumc[y] -= cura;
            if (x == y) sumd1 -= cura;
            if (x == n - 1 - y) sumd2 -= cura;
            
        } else
        {
            int nmask = mask ^ bit[i];
            
            sumr[x] += cura;
            sumc[y] += cura;
            if (x == y) sumd1 += cura;
            if (x == n - 1 - y) sumd2 += cura;
            f[x][y] = cura;
            
            if (check(x, y, nmask))
                go(x, y + 1, nmask);
            
            sumr[x] -= cura;
            sumc[y] -= cura;
            if (x == y) sumd1 -= cura;
            if (x == n - 1 - y) sumd2 -= cura;
        }
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    forn(i, 30) bit[i] = (1 << i);
    
    cin >> n;
    nn = n * n;
    
    forn(i, n * n)
        cin >> a[i];
        //a[i] = rand();

    if (n == 1)
    {
        cout << a[0] << endl;
        cout << a[0] << endl;
        return 0;
    }
        
    forn(mask, bit[n * n])
    {
        int minvv = INF, maxvv = -INF;
        int sum = 0;
        forn(i, n * n)
            if (mask & bit[i])
                sum += a[i], minvv = min(minvv, a[i]), maxvv = max(maxvv, a[i]);
                
        sum %= P;
        sum += P;
        sum %= P;
        sums[mask] = sum;
        minv[mask] = minvv;
        maxv[mask] = maxvv;
    }

    forn(mask, bit[n * n])
        for (int nmask = mask; ; nmask = ((nmask - 1) & mask))
        {
            can[mask][sums[nmask]] = true;
            if (nmask == 0) break;
        }
    
    go(0, 0, 0);
    
    throw;
    
    return 0;
}