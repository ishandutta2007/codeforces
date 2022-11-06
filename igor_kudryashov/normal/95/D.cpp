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

const int N = 1000 + 13;
const int mod = 1000 * 1000 * 1000 + 7;

int k;
int d[N][N][2];
int allGood[N];
int lenLast0[N][N];
char lf[N], rg[N];

int solveRg ()
{
    int n = strlen(rg);
    int res = allGood[n - 1];
    int lastGood = -INF, was = 0;
    
    forn(i, n)
    {
        forn(cur, rg[i] - '0')
        {
            if (i == 0 && cur == 0)
                continue;

            res = (res + allGood[n - 1 - i]) % mod;
            if (lastGood == -INF && cur != 4 && cur != 7)
                continue;
                
            int nlastGood = ((cur == 4 || cur == 7) ? 0 : i - lastGood);
            int nwas = was || ((cur == 4 || cur == 7) && i - lastGood <= k);
            
            if (nwas)
                res = (res + lenLast0[n - 1 - i][k + 1]) % mod;
            else if (k - nlastGood - 1 >= 0)
                res = (res + lenLast0[n - 1 - i][k - nlastGood - 1]) % mod;
        }
        
        if (lastGood != -INF && (rg[i] == '4' || rg[i] == '7') && i - lastGood <= k)
            was = true;
        if (rg[i] == '4' || rg[i] == '7')
            lastGood = i;
    }
    
    if (was)
        res = (res + 1) % mod;
    
    return res;
}

int solveLf ()
{
    int n = strlen(lf);
    int cur = n - 1;
    while (lf[cur] == '0')
        lf[cur--] = '9';
    lf[cur]--;
    
    if (n == 1 && lf[0] == '0')
        return 0;
        
    if (lf[0] == '0')
    {
        forn(i, n - 1)
            lf[i] = lf[i + 1];
        n--;
    }
    
    int res = allGood[n - 1];
    int lastGood = -INF, was = 0;
    
    forn(i, n)
    {
        forn(cur, lf[i] - '0')
        {
            if (i == 0 && cur == 0)
                continue;

            res = (res + allGood[n - 1 - i]) % mod;
            if (lastGood == -INF && (cur != 4 && cur != 7))
                continue;
                
            int nlastGood = (cur == 4 || cur == 7 ? 0 : i - lastGood);
            int nwas = was || ((cur == 4 || cur == 7) && i - lastGood <= k);
            
            if (nwas)
                res = (res + lenLast0[n - 1 - i][k + 1]) % mod;
            else if (k - nlastGood - 1 >= 0)
                res = (res + lenLast0[n - 1 - i][k - nlastGood - 1]) % mod;
        }
        
        if (lastGood != -INF && (lf[i] == '4' || lf[i] == '7') && i - lastGood <= k)
            was = true;
        if (lf[i] == '4' || lf[i] == '7')
            lastGood = i;
    }
    
    if (was)
        res = (res + 1) % mod;
    
    return res;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    int testCount;
    cin >> testCount >> k;
    
    d[0][k + 1][0] = 1;
    
    forn(len, 1005)
        forn(lastGood, k + 2)
            forn(was, 2)
            {
                int& dv = d[len][lastGood][was];
                if (dv == 0)
                    continue;
                    
                forn(next, 10)
                    if (next == 4 || next == 7)
                    {
                        d[len + 1][0][was || (lastGood + 1 <= k)] += dv;
                        while (d[len + 1][0][was || (lastGood + 1 <= k)] >= mod)
                            d[len + 1][0][was || (lastGood + 1 <= k)] -= mod;
                    } else
                    {
                        d[len + 1][min(lastGood + 1, k + 1)][was] += dv;
                        while (d[len + 1][min(lastGood + 1, k + 1)][was] >= mod)
                            d[len + 1][min(lastGood + 1, k + 1)][was] -= mod;
                    }
            }
            
    forn(len, 1006)
        forn(lastGood, k + 2)
        {
            allGood[len] += d[len][lastGood][1];
            while (allGood[len] >= mod)
                allGood[len] -= mod;
        }
        
    forn(len, 1006)
        forn(lastGood, k + 2)
            lenLast0[len][lastGood] = (d[len][lastGood][0] + (lastGood == 0 ? 0 : lenLast0[len][lastGood - 1])) % mod;
            
    forn(test, testCount)
    {
        scanf("%s %s", lf, rg);
        int ans = solveRg() - solveLf();
        while (ans < 0)
            ans += mod;
            
        printf("%d\n", ans);
    }

    return 0;
}