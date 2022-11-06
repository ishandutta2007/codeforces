#pragma comment(linker, "/stack:64000000")
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

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    int x, y;
    cin >> x >> y;
    
    int xod = 0;
    
    while (true)
    {
        if (xod == 0)
        {
            int cnt = 0;
            while (x > 0 && cnt < 200)
                x--, cnt += 100;
                
            while (y > 0 && cnt < 220)
                y--, cnt += 10;
                
            if (cnt != 220)
                break;
                
            xod ^= 1;
        
        } else
        {
            if (y >= 22)
                y -= 22, xod ^= 1;
            else if (x > 0 && y >= 12)
                y -= 12, x--, xod ^= 1;
            else if (x > 1 && y >= 2)
                y -= 2, x -= 2, xod ^= 1;
            else
                break;
        }
    }
    
    if (xod == 1)
        cout << "Ciel" << endl;
    else
        cout << "Hanako" << endl;

    return 0;
}