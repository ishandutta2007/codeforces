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

li l1, r1, l2, r2;
li ans;

li getNext (li lf, int k)
{
    li f = (1LL << k) - 1LL;
    
    li cur = f + ((lf - f) / (1LL << (k + 1))) * (1LL << (k + 1));
    
    li res = li(1e18);
    
    for (int dx = -3; dx <= 3; dx++)
    {
        li now = cur + (1LL << (k + 1)) * dx;
        if (now >= lf && now < res)
            res = now;
    }
    
    assert(res < li(1e17));
    
    return res;
}

void solve (li lf, li rg)
{
    int k = -1;
    li pos = -1;
    
    for (int i = 30; i >= 0; i--)
    {
        li curp = getNext(lf, i);
        if (curp <= rg)
        {
            k = i;
            pos = curp;
            break;
        }
    }
    
    li lflen = pos - lf, rglen = rg - pos;
    
    li maxLen = -1;
    
    forn(iter, 2)
    {
        li p = getNext(l2, k);
        if (iter == 1) p = getNext(r2, k);
        
        for (int dx = -3; dx <= 3; dx++)
        {
            li curp = p + (1LL << (k + 1)) * dx;
            if (curp < l2 || curp > r2) continue;
            
            li curLf = curp - l2, curRg = r2 - curp;
            
            maxLen = max(maxLen, min(lflen, curLf) + 1LL + min(rglen, curRg));
            ans = max(ans, maxLen);
        }
    }
    
    if (lflen > 0 && maxLen < rg - lf + 1)
        solve(lf, pos - 1);
        
    if (rglen > 0 && maxLen < rg - lf + 1)
        solve(pos + 1, rg);
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> l1 >> r1 >> l2 >> r2;
    --l1, --r1, --l2, --r2;
    
    if (r1 - l1 > r2 - l2)
        swap(l1, l2), swap(r1, r2);
    
    solve(l1, r1);
    
    cout << ans << endl;

    return 0;
}