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

const int N = 4000 + 3;
const int M = 1000 * 1000 + 3;

int n;
int a[N];
vector <int> pos[M];
int d[N][N];

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    forn(i, n)
    {
        scanf("%d", &a[i]);
        pos[a[i]].pb(i);
    }
    
    if (n == 1)
    {
        puts("1");
        return 0;
    }
    
    int ans = 2;
    
    forn(i, n)
        forn(j, i)
            d[j][i] = 2;
            
    forn(j, n)
        forn(i, j)
        {
            ans = max(ans, d[i][j]);
            
            int idx = int(lower_bound(all(pos[a[i]]), j + 1) - pos[a[i]].begin());
            
            if (idx < sz(pos[a[i]]))
            {
                idx = pos[a[i]][idx];
                d[j][idx] = max(d[j][idx], d[i][j] + 1);
            }
        }
        
    cout << ans << endl;
    
    return 0;
}