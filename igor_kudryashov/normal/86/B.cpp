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

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m;
int a[N][N];
vector <pt> neib;
int used[N][N], u = 0;

void dfs (int x, int y, int col)
{
    used[x][y] = u;
    neib.pb(mp(x, y));
    
    forn(i, 4)
    {
        int tx = x + dx[i], ty = y + dy[i];
        
        if (!correct(tx, ty, n, m) || a[tx][ty] != col)
            continue;
            
        if (used[tx][ty] == u)
            continue;
            
        dfs(tx, ty, col);
    }
}

bool color[10];

int getCol (const vector <pt>& v)
{
    memset(color, 0, sizeof(color));

    forn(i, sz(v))
    {
        int x = v[i].ft, y = v[i].sc;
        
        forn(j, 4)
        {   
            int tx = x + dx[j], ty = y + dy[j];
            
            if (!correct(tx, ty, n, m) || a[tx][ty] < 0 || a[tx][ty] > 9)
                continue;
                
            bool ok = true;
            
            forn(k, sz(v))
                if (mp(tx, ty) == v[k])
                {
                    ok = false;
                    break;
                }
                
            if (!ok)
                continue;
                
            color[a[tx][ty]] = true;
        }
    }
    
    forn(i, 10)
        if (!color[i])
            return i;
            
    return -1;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m;
    
    forn(i, n)
    {
        char buf[N];
        scanf("%s", buf);
        
        forn(j, m)
            if (buf[j] == '#')
                a[i][j] = -2;
            else
                a[i][j] = -1;
    }
    
    forn(i, n)
        forn(j, m)
        {
            if (a[i][j] != -1 || j + 1 >= m || a[i][j + 1] != -1)
                continue;
                
            vector <pt> v;
            v.pb(mp(i, j));
            v.pb(mp(i, j + 1));
                
            int c = getCol(v);
            
            a[i][j] = a[i][j + 1] = c;
        }
        
    forn(i, n)
        forn(j, m)
        {
            if (a[i][j] != -1 || i + 1 >= n || a[i + 1][j] != -1)
                continue;
                
            vector <pt> v;
            v.pb(mp(i, j));
            v.pb(mp(i + 1, j));
            
            int c = getCol(v);
            
            a[i][j] = a[i + 1][j] = c;
        }
        
    forn(i, n)
        forn(j, m)
        {
            if (a[i][j] != -1)
                continue;
                
            int c = -1;
            
            forn(k, 4)
            {
                int tx = i + dx[k], ty = j + dy[k];
                
                if (!correct(tx, ty, n, m) || a[tx][ty] == -2)
                    continue;
                    
                neib.clear();
                neib.pb(mp(i, j));
            
                u++;
                dfs(tx, ty, a[tx][ty]);
                
                assert(sz(neib) <= 5);
                
                c = getCol(neib);
                
                forn(t, sz(neib))
                    a[neib[t].ft][neib[t].sc] = c;
            }
            
            if (c == -1)
            {
                puts("-1");
                return 0;
            }
        }
        
    forn(i, n)
    {
        forn(j, m)
            if (a[i][j] == -2)
                putchar('#');
            else
            {
                assert(a[i][j] >= 0 && a[i][j] <= 9);
                printf("%d", a[i][j]);
            }
            
        puts("");
    }

    return 0;
}