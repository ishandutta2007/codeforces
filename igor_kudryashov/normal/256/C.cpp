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
typedef long long li;
typedef pair <li, li> pt;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;

const int M = 100;
const li MAX = 1000LL * 1000 * 1000 * 1000;
const li INF64 = 1000LL * 1000 * 1000 * 1000 * 1000;

vector <pt> segms;
vector <int> vals;
pt d[M];

inline li mypow (const li& v, int pw)
{
    li resi = 1;
    ld resd = 1.0;
    
    forn(i, pw)
    {
        resi *= v;
        resd *= v;
        
        if (resd > INF64) return INF64;
    }
    
    return resi;
}

void prepare ()
{
    segms.pb(mp(0, 3));
    vals.pb(0);
    
    d[0] = mp(4, 81);
    
    li curval = 4;
    
    while (curval < MAX)
    {
        li minrg = INF64;
        int nowans = 0;
        while (d[nowans].ft <= curval && curval <= d[nowans].sc) minrg = min(minrg, d[nowans].sc), nowans++;
        minrg = min(minrg, mypow(curval, 2) - 1);
        
        segms.pb(mp(curval, minrg));
        vals.pb(nowans);
        
        //cerr << curval << ' ' << minrg << endl;
        
        d[nowans] = mp(mypow(curval, 2), mypow(minrg, 4));
        curval = minrg + 1;
    }
}

inline li grandy (li n)
{
    int idx = int(lower_bound(all(segms), mp(n + 1, n + 1)) - segms.begin()) - 1;
    assert(segms[idx].ft <= n && n <= segms[idx].sc);
    return vals[idx];
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    prepare();
    
    int n;
    cin >> n;
    
    li cur = 0;
    
    forn(i, n)
    {
        li a;
        cin >> a;
        cur ^= grandy(a);
    }
    
    if (cur == 0)
        puts("Rublo");
    else
        puts("Furlo");
    
    return 0;
}