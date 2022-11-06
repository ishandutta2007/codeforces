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

const int mod = 1000 * 1000 * 1000 + 7;
const int N = 100 + 13;

int n, k;
li m;
int R;
int c1[N], c2[N];
int invs[N];
int z[N][N * N];

int solve (int idx, int rem)
{
    int& ans = z[idx][rem];
    if (ans != -1) return ans;
    
    if (idx == n) return ans = (rem == 0);
    
    ans = 0;
    if (rem > (n - idx) * n) return ans;
    if (rem == 0) return ans = 1;
    
    int fin = min(n, rem);
    
    forn(cnt, fin + 1)
    {
        int t = solve(idx + 1, rem - cnt);
        if (t != 0)
        {
            li cur = t;
            
            if (idx < R) cur *= c1[cnt]; else cur *= c2[cnt];
            if (cur >= mod) cur %= mod;
            
            ans += cur;
            if (ans >= mod) ans -= mod;
        }
    }
    
    return ans;
}

int binPow (int a, li b, int mod)
{
    int res = 1;
    
    while (b)
    {
        if (b & 1) res = (res * 1LL * a) % mod;
        a = (a * 1LL * a) % mod;
        b >>= 1;
    }
    
    return res;
}

int C (int n, int k)
{
    if (k < 0 || k > n) return 0;

    int ans = 1;
    
    for1(i, n) ans = (ans * 1LL * i) % mod;
    
    for1(i, k) ans = (ans * 1LL * invs[i]) % mod;
    
    for1(i, n - k) ans = (ans * 1LL * invs[i]) % mod;
    
    return ans;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    for1(i, N - 1) invs[i] = binPow(i, mod - 2, mod);
    
    cin >> n >> m >> k;
    
    R = m % n;
    
    forn(i, n + 1)
    {
        c1[i] = binPow(C(n, i), m / n + 1, mod);
        c2[i] = binPow(C(n, i), m / n, mod);
    }
    
    /*forn(i, n + 1)
        cerr << c2[i] << endl;
    cerr << endl;*/
        
    memset(z, -1, sizeof(z));
    
    cout << solve(0, k) << endl;
    
    return 0;
}