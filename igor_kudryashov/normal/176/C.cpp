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

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int n, m, x1, yy1, x2, y2;

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m >> x1 >> yy1 >> x2 >> y2;
    --x1, --yy1, --x2, --y2;
    
    int ans = 2;
    
    forn(i, 4)
    {
        int tx = x1 + dx[i], ty = yy1 + dy[i];
        if (!correct(tx, ty, n, m) || abs(tx - x2) >= 4 || abs(ty - y2) >= 4 || (abs(tx - x2) == 3 && abs(ty - y2) == 3))
            continue;
            
        ans = 1;
    }
    
    forn(i, 4)
    {
        int tx = x2 + dx[i], ty = y2 + dy[i];
        if (!correct(tx, ty, n, m) || abs(tx - x1) >= 4 || abs(ty - yy1) >= 4 || (abs(tx - x1) == 3 && abs(ty - yy1) == 3))
            continue;
            
        ans = 1;
    }
    
    if (ans == 1)
        puts("First");
    else
        puts("Second");

    return 0;
}