#pragma comment(linker, "/stack:64000000")
#define _SECURE_SCL 0
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

const int N = 100 + 13;

int n, vb, vs;
int x[N];
int finx, finy;

ld dist (int ax, int ay, int bx, int by)
{
    return sqrt(sqr(ld(ax - bx)) + sqr(ld(ay - by)));
}

int main()
{
    
    cin >> n >> vb >> vs;
    
    forn(i, n)
        cin >> x[i];
        
    cin >> finx >> finy;
    
    ld best = 1e10;
    int idx = 1;
    ld tb = 0.0;
    
    for1(i, n - 1)
    {
        tb += abs(x[i] - x[i - 1]) * 1.0 / vb;
        
        ld t = tb + dist(x[i], 0, finx, finy) / vs;
        
        if (t + EPS < best || (abs(t - best) < EPS && dist(x[i], 0, finx, finy) + EPS < dist(x[idx], 0, finx, finy)))
        {
            best = t;
            idx = i;
        }
    }
    
    cout << idx + 1 << endl;

    return 0;
}