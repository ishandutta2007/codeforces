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

const int N = 20 + 3;

int n, k;
int d[N][N];
int z[(1 << 20) + 3];
int bit[30];
string s[N];

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    forn(i, 30)
        bit[i] = (1 << i);
    
    cin >> n >> k;
    
    forn(i, n)
        cin >> s[i];
        
    forn(i, n)  
        forn(j, n)
        {
            int cnt = min(sz(s[i]), sz(s[j]));
            for (int len = cnt; len >= 1; len--)
                if (s[i].substr(0, len) == s[j].substr(0, len))
                {
                    d[i][j] = len;
                    break;
                }
        }
        
    int ans = 0;
        
    for1(mask, bit[n] - 1)
    {
        int prevMask = (mask & (mask - 1));
        int pos = -1, cnt = 0;
        forn(i, n)
            if ((mask ^ prevMask) & bit[i])
            {
                pos = i;
                break;
            }
        assert(pos != -1);
        
        z[mask] = z[prevMask];
        
        forn(i, n)
        {
            if (mask & bit[i])
                cnt++;
        
            if (prevMask & bit[i])
                z[mask] += d[i][pos];
        }
                
        if (cnt == k)
            ans = max(ans, z[mask]);
    }
    
    cout << ans << endl;
        
    return 0;
}