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
#define x first
#define y second
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

int n, m;
int a[N][N];
int r[N], c[N];
int ansr[N], ansc[N];

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m;
    
    forn(i, n)
        forn(j, m)
        {
            scanf("%d", &a[i][j]);
            //a[i][j] = rand() % 201 - 100;
            r[i] += a[i][j];
            c[j] += a[i][j];
        }
        
    while (true)
    {
        int idx = -1;
        
        forn(i, n)
            if (r[i] < 0)
            {
                idx = i;
                break;
            }
            
        if (idx != -1)
        {
            ansr[idx] ^= 1;
            r[idx] *= -1;
            
            forn(j, m)
            {
                c[j] -= a[idx][j];
                a[idx][j] *= -1;
                c[j] += a[idx][j];
            }
            
            continue;
        }
        
        forn(j, m)
            if (c[j] < 0)
            {
                idx = j;
                break;
            }
            
        if (idx == -1) break;
        
        ansc[idx] ^= 1;
        c[idx] *= -1;
        
        forn(i, n)
        {
            r[i] -= a[i][idx];
            a[i][idx] *= -1;
            r[i] += a[i][idx];
        }
    }
    
    vector <int> rs, cs;
    
    forn(i, n)
        if (ansr[i])
            rs.pb(i);
            
    forn(j, m)
        if (ansc[j])
            cs.pb(j);
            
    cout << sz(rs);
    
    forn(i, sz(rs))
        printf(" %d", rs[i] + 1);
        
    puts("");
    
    cout << sz(cs);
    
    forn(i, sz(cs))
        printf(" %d", cs[i] + 1);
        
    puts("");
    
    
    return 0;
}