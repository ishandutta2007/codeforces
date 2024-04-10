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

const int N = 30 + 3;

int n;
int a[N];
int f[N][N];
int perm[N];

void check ()
{
    int sum = 0;
    forn(i, n)
        sum += f[i][0];
        
    forn(i, n)
    {
        int sr = 0, sc = 0;
        
        forn(j, n)
            sr += f[i][j], sc += f[j][i];
            
        if (sr != sum || sc != sum)
            return;
    }
    
    int sm = 0, sp = 0;
    
    forn(i, n)
        sm += f[i][i], sp += f[i][n - 1 - i];
        
    if (sm != sum || sp != sum)
        return;
        
    cout << sum << endl;
    
    forn(i, n)
    {
        forn(j, n)
            cout << f[i][j] << ' ';
        cout << endl;
    }
    
    exit(0);            
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    forn(i, n * n)
        cin >> a[i];
        
    forn(i, n * n)
        perm[i] = i;
        
    do
    {
        forn(i, n)
            forn(j, n)
                f[i][j] = a[perm[i * n + j]];
                
        check();
        
    } while (next_permutation(perm, perm + n * n));

    return 0;
}