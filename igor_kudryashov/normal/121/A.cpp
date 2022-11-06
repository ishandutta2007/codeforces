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

vector <li> lucky;

void go (int pos, li cur)
{
    if (pos > 0)
        lucky.pb(cur);
        
    if (pos == 10)
        return;
        
    go(pos + 1, cur * 10 + 4);
    go(pos + 1, cur * 10 + 7);
}

li getCnt (li prev, li cur, li lf, li rg)
{
    if (cur <= rg)
        return cur - prev;
        
    return rg - prev;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    int lf, rg;
    cin >> lf >> rg;
    
    go(0, 0);
    
    sort(all(lucky));
    
    li ans = 0;
    
    vector <li> res;
    
    forn(i, sz(lucky))
    {
        if (lucky[i] >= lf && lucky[i] <= rg)
            res.pb(lucky[i]);
        else if (lucky[i] >= rg)
        {
            res.pb(lucky[i]);
            break;
        }
    }
    
    forn(i, sz(res))
        ans += res[i] * 1LL * getCnt(i > 0 ? res[i - 1] : lf - 1, res[i], lf, rg);
        
    cout << ans << endl;

    return 0;
}