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

const int mod = 2520;

map <int, int> lcmToNum;
int numToLcm[50];
int sz = 0;
int nextLcm[50][10];
int nextMod[2][mod][10];
li d[30][252][50][2];
int digs[20];

int gcd (int a, int b)
{
    return a == 0 ? b : gcd(b % a, a);
}

inline int lcm (int a, int b)
{
    if (a == 0)
        return b;
        
    if (b == 0)
        return a;

    return a / gcd(a, b) * b;
}

li solve (li n)
{
    li tmp = n;
    
    forn(i, 20)
        digs[19 - i] = tmp % 10, tmp /= 10;
        
    memset(d, 0, sizeof(d));
    
    d[0][0][0][0] = 1;
    
    forn(i, 20)
        forn(j, 2)
            forn(k, 252)
                forn(t, sz)
                {
                    if (d[i][k][t][j] == 0)
                        continue;
                        
                    if (j)
                    {
                        forn(dig, 10)
                        {
                            int nwmod = nextMod[i == 19][k][dig];
                            int nwlcm = nextLcm[t][dig];
                            
                            d[i + 1][nwmod][nwlcm][1] += d[i][k][t][j];
                        }
                    
                    } else
                    {
                        forn(dig, digs[i] + 1)
                        {
                            int nwmod = nextMod[i == 19][k][dig];
                            int nwlcm = nextLcm[t][dig];
                            
                            d[i + 1][nwmod][nwlcm][dig < digs[i]] += d[i][k][t][j];
                        }
                        
                    }
                }
                
    li ans = 0;
    
    forn(i, mod)
        forn(j, sz)
            if (i % numToLcm[j] == 0)
                ans += d[20][i][j][1];
                
    return ans;
}

int main()
{
    
    for1(i, mod)
        if (mod % i == 0)
            lcmToNum[i] = 0;
            
    for (map <int, int> :: iterator it = lcmToNum.begin(); it != lcmToNum.end(); it++)
    {
        it->second = sz;
        numToLcm[sz] = it->first;
        sz++;
    }
    
    forn(i, sz)
        forn(j, 10)
            nextLcm[i][j] = lcmToNum[lcm(numToLcm[i], j)];
            
    forn(t, 2)
        forn(i, mod)
            forn(j, 10)
                nextMod[t][i][j] = (i * 10 + j) % ((t == 0) ? mod / 10 : mod);
    
    int testCount;
    cin >> testCount;
    
    forn(test, testCount)
    {
        li lf, rg;
        cin >> lf >> rg;
        
        cout << solve(rg + 1) - solve(lf) << endl;
    }

    return 0;
}