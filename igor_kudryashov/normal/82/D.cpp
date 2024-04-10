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

const int N = 1000 + 13;

int n;
int a[N];
int z[N][N];
int p[N][N];
pt pe[N][N];

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    forn(i, n)
        scanf("%d", &a[i]);
        
    memset(z, 63, sizeof(z));
    memset(p, -1, sizeof(p));
    
    z[0][0] = 0;
    
    forn(i, (n + 1) / 2)
        forn(j, n)
        {
            if (z[i][j] > INF)
                continue;

            int pos = 2 * i + 1;    
            vector <int> cur;
            
            cur.pb(j);
            forn(k, 2)
                if (pos + k < n)
                    cur.pb(pos + k);
                    
            if (sz(cur) == 1)
            {
                if (z[i + 1][n] > z[i][j] + a[cur[0]])
                {
                    z[i + 1][n] = z[i][j] + a[cur[0]];
                    p[i + 1][n] = j;
                    pe[i + 1][n] = mp(cur[0], -1);
                }
            }
            else if (sz(cur) == 2)
            {
                if (z[i + 1][n] > z[i][j] + max(a[cur[0]], a[cur[1]]))
                {
                    z[i + 1][n] = z[i][j] + max(a[cur[0]], a[cur[1]]);
                    p[i + 1][n] = j;
                    pe[i + 1][n] = mp(cur[0], cur[1]);
                }
                
            } else
            {
                assert(sz(cur) == 3);
                
                forn(k, 3)
                {
                    vector <int> ncur;
                    int nmax = -INF;
                    forn(k2, 3)
                        if (k2 != k)
                        {
                            nmax = max(nmax, a[cur[k2]]);
                            ncur.pb(cur[k2]);
                        }
                    
                    if (z[i + 1][cur[k]] > z[i][j] + nmax)
                    {
                        z[i + 1][cur[k]] = z[i][j] + nmax;
                        p[i + 1][cur[k]] = j;
                        pe[i + 1][cur[k]] = mp(ncur[0], ncur[1]);
                    }
                }
            }
        }
        
    int ansVal = z[(n + 1) / 2][n];
    assert(p[(n + 1) / 2][n] != -1);
    
    vector <pt> ans;
    
    int f = n;
    
    for (int i = (n + 1) / 2; i > 0; i--)
    {
        assert(f != -1);
        ans.pb(pe[i][f]);
        f = p[i][f];
    }
    
    reverse(all(ans));
    
    cout << ansVal << endl;
    
    forn(i, sz(ans))
    {
        printf("%d ", ans[i].ft + 1);
        
        if (ans[i].sc != -1)
            printf("%d ", ans[i].sc + 1);
            
        puts("");
    }

    return 0;
}