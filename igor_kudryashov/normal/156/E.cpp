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

const int N = 30 * 1000 + 13;

int n, m;
li a[N];
int r[N][5];
int prod[5];
int mods[4];
int p[100], szp;

int calcedRems[N][4], szcalced;
map <string, int> cache[19];

int curprod[5];
int base;
int deg[20];
int pat[20], szpat;

void go (int pos, int idx)
{
    if (idx >= n) return;

    if (pos == szpat)
    {
        forn(i, 4) curprod[i] = (curprod[i] * 1LL * r[idx][i]) % mods[i];
        return;
    }
    
    if (pat[pos] != -1)
        go(pos + 1, idx + pat[pos] * deg[pos]);
    else
        forn(i, base)
            go(pos + 1, idx + i * deg[pos]);
}

inline int getDig (char c) { return isdigit(c) ? (c - '0') : (c - 'A' + 10); }

inline li minimal (const string& pat, int base)
{
    li res = 0, deg = 1;
    
    forn(i, sz(pat))
        if (pat[i] != '?' && pat[i] != '0')
        {
            res += deg * getDig(pat[i]), deg *= base;
            if (i >= 14) return INF;
        }
        
    return res;
}

inline string normalPat (string pat, int base)
{
    int deg = 1, cnt = 1;
    while (deg <= n) deg *= base, cnt++;
    deg /= base, cnt--;
    
    while (sz(pat) > cnt) pat.erase(sz(pat) - 1);
    return pat;
}

int solve (int base, string curpat, li c)
{
    if (minimal(curpat, base) >= n)
    {
        forn(i, szp)
            if ((c + 1) % p[i] == 0)
                return p[i];
        return -1;
    }
    
    curpat = normalPat(curpat, base);
    
    if (cache[base].count(curpat))
    {
        int idx = cache[base][curpat];
        forn(i, 4)
            curprod[i] = calcedRems[idx][i];
    } else
    {
        forn(i, 4) curprod[i] = 1;
    
        deg[0] = 1;
        for1(i, 19) deg[i] = deg[i - 1] * base;
        
        szpat = 0;
        forn(i, sz(curpat))
            if (curpat[i] == '?')
                pat[szpat++] = -1;
            else
                pat[szpat++] = getDig(curpat[i]);
                
        ::base = base;
        go(0, 0);
        
        forn(i, 4)
            calcedRems[szcalced][i] = curprod[i];
        cache[base][curpat] = szcalced;
        szcalced++;
    }
    
    /*forn(i, 4)
        cerr << curprod[i] << ' ';
    cerr << endl;*/
    
    forn(i, 4)
        curprod[i] = (curprod[i] + c) % mods[i];
    
    forn(i, szp)
        forn(j, 4)
            if (mods[j] % p[i] == 0 && curprod[j] % p[i] == 0)
                return p[i];
                
    return -1;
}

inline bool isPrime (int n)
{
    if (n == 1) return false;       
    for (int i = 2; i < n; i++)
        if (n % i == 0) return false;
    return true;
}

void precalc ()
{
    for1(i, 100)
        if (isPrime(i))
            p[szp++] = i;
            
    int idx = 0;
    int dx = 1;
    forn(i, 4)
        mods[i] = 1;
    
    ford(i, szp)
    {
        mods[idx] *= p[i];
        idx += dx;
        if (idx == 4)
            idx = 3, dx = -1;
        else if (idx == -1)
            idx = 0, dx = 1;
    }
    
    forn(i, n)
        forn(j, 4)
            r[i][j] = a[i] % mods[j];
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    forn(i, n)
        scanf("%I64d", &a[i]);

    precalc();
    
    cin >> m;
    
    forn(i, m)
    {
        int base;
        char buf[33];
        li c;
        scanf("%d%s%I64d", &base, buf, &c);
        string curpat = string(buf);
        reverse(all(curpat));
        
        printf("%d\n", solve(base, curpat, c));
    }
    
    return 0;
}