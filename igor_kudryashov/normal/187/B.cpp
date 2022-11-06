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

const int N = 60 + 3;
const int SZQ = N * N;

int n, m, r;
int w[N][N][N];
int mind[N][N];
int d[N][N];
int z[N][N][N];
pt q[SZQ];
int tail, head;
int inQ[N][N];

void calcZ (int st)
{
    forn(i, n)
        forn(cnt, n + 1)
            z[st][i][cnt] = INF;
            
    tail = head = 0;
    z[st][st][0] = 0;
    q[tail++] = mp(st, 0);
    inQ[st][0] = true;
    
    while (head != tail)
    {
        int v = q[head].ft, cnt = q[head].sc;
        if (++head == SZQ) head = 0;
        inQ[v][cnt] = false;
        
        if (cnt == n) continue;
        
        int dv = z[st][v][cnt];
        
        forn(i, n)
        {
            if (z[st][i][cnt + 1] > dv + mind[v][i])
            {
                z[st][i][cnt + 1] = dv + mind[v][i];
                if (!inQ[i][cnt + 1])
                {
                    inQ[i][cnt + 1] = true;
                    q[tail] = mp(i, cnt + 1);
                    if (++tail == SZQ) tail = 0;
                }
            }
        }
    }
}

void calc (int num)
{
    forn(i, n)
        forn(j, n)
            d[i][j] = w[num][i][j];
            
    forn(k, n)
        forn(i, n)
            forn(j, n)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                
    forn(i, n)
        forn(j, n)
            mind[i][j] = min(mind[i][j], d[i][j]);
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m >> r;
    
    forn(i, n)
        forn(j, n)
            mind[i][j] = INF;
    
    forn(i, m)
        forn(j, n)
            forn(k, n)
                scanf("%d", &w[i][j][k]);
                
    forn(i, m)
        calc(i);
        
    forn(i, n)
        calcZ(i);
        
    forn(i, r)
    {
        int s, t, k;
        scanf("%d%d%d", &s, &t, &k);
        k++, s--, t--;
        k = min(k, n);
        printf("%d\n", z[s][t][k]);
    }
    
    return 0;
}