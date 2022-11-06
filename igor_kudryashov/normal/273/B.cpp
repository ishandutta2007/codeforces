#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <numeric>
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

const int N = 200 * 1000 + 13;

int n, mod;
vector <pt> v;
pt fact[N];

inline int binPow (int a, int b, int mod)
{
    int res = 1;
    
    while (b)
    {
        if (b & 1) res = (res * 1LL * a) % mod;
        b >>= 1;
        a = (a * 1LL * a) % mod;
    }
    
    return res;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    forn(iter, 2)
    forn(i, n)
    {
        int x;
        assert(scanf("%d", &x) == 1);
        v.pb(mp(x, i));
    }
    
    cin >> mod;
    
    fact[0] = mp(0, 1);
    
    forl(i, N - 1)
    {
        int t = i, p2 = 0;
        while ((t & 1) == 0) t >>= 1, p2++;
        
        fact[i] = fact[i - 1];
        fact[i].ft += p2;
        fact[i].sc = (fact[i].sc * 1LL * t) % mod;
    }
    
    sort(all(v));
    
    int ans = 1;
    
    for (int i = 0; i < sz(v); )
    {
        int st = i, k = 0;
        while (i < sz(v) && v[i].ft == v[st].ft)
        {
            if (i > 0 && v[i] == v[i - 1]) k++;
            i++;
        }
        
        pt cur = fact[i - st];
        assert(cur.ft >= k);
        cur.ft -= k;
        
        //cerr << cur.ft << ' ' << cur.sc << endl;
        
        int now = binPow(2, cur.ft, mod);
        now = (now * 1LL * cur.sc) % mod;
        
        ans = (ans * 1LL * now) % mod;
    }
    
    cout << ans << endl;
    
    return 0;
}