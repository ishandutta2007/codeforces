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

const int N = 2 * 100 * 1000 + 13;
const int M = (1 << 20) + 13;

int n, L;
char a[N][23];
int d[21][(1 << 20) + 13];
short cntBit[M];
int ma[N];
int bit[30];

inline int f (const int& ma, const int& mb)
{
    forn(i, L)
    {
        int nma = ma >> i;
        int nmb = mb & (bit[L - i] - 1);
        
        if (nma == nmb)
            return i;
    }
    
    return L;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    forn(i, 30)
        bit[i] = (1 << i);
    
    for1(mask, M - 1)
        cntBit[mask] = cntBit[mask & (mask - 1)] + 1;
    
    cin >> n;
    
    gets(a[0]);
    forn(i, n)
        gets(a[i]);
        
    L = strlen(a[0]);
    
    forn(i, n)
        forn(j, L)
            if (a[i][j] == '1')
                ma[i] |= bit[j];
        
    memset(d, 63, sizeof(d));
    
    d[0][0] = 0;
    
    int bal = 0;
    
    forn(i, n)
    {
        int nbal = bal + (i == 0 ? L : f(ma[i - 1], ma[i]));
        int minv = INF;
        
        int mask = 0;
        
        forn(len, L + 1)
        {
            int nd = d[len][mask] + bal + L - len;
            minv = min(minv, nd);
            
            if (a[i][len] == '1')
                mask |= bit[len];
        }
        
        if (i > 0)
        {
            int mask = 0;
            
            forn(len, L + 1)
            {
                if (d[len][mask] + nbal > minv)
                    d[len][mask] = minv - nbal;
                    
                if (len < L)
                    mask = (mask << 1) ^ (a[i - 1][L - 1 - len] == '1');
            }
        }
        
        bal = nbal;
    }
    
    int ans = INF;
    
    forn(i, L + 1)
        forn(j, bit[i + 1])
            ans = min(ans, d[i][j] + bal);
            
    assert(ans < INF);
            
    cout << ans << endl;

    return 0;
}