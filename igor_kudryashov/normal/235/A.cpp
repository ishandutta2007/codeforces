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

li gcd (li a, li b) { return a == 0 ? b : gcd(b % a, a); }

li lcm (li a, li b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    li n;
    cin >> n;
    
    li ans = n;
    li v[3] = {n, n, n};
    
    for (li i = n - 1; i > 0; i--)
    {
        li best = 0;
        int idx = -1;
    
        forn(j, 3)
        {
            li cur = 1;
        
            forn(k, 3)
                if (j != k)
                    cur = lcm(cur, v[k]);
                else
                    cur = lcm(cur, i);
                    
            if (best < cur)
                best = cur, idx = j;
        }
        
        if (best > ans)
        {
            ans = best;
            v[idx] = i;
        }
    }
    
    /*li ansv = 0;
    
    for1(i, n)
        for1(j, n)
            for1(k, n)
                if (ansv < lcm(lcm(i, j), k))
                {
                ansv = max(ansv, lcm(lcm(i, j), k));
                //cerr << i << ' ' << j << ' ' << k << endl;
                }
                
    cerr << n << ' ' << ansv << ' ' << ans << endl;
                
    assert(ansv == ans);
    }*/
                
    //cerr << ansv << endl;
        
    cout << ans << endl;    
    
    return 0;
}