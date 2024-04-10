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

const int N = 100 * 1000 + 13;

int n, m;
char s[N];
int z[13][N];
string v[13];
int used[N];

void calc (int idx, string t)
{
    memset(used, 0, sizeof(used));
    
    forn(i, n)
        if (i + 1 >= sz(t))
        {
            bool bad = true;
        
            forn(j, sz(t))
                if (t[j] != s[i - sz(t) + 1 + j])
                {
                    bad = false;
                    break;
                }
                
            used[i] = bad;
        }
        
    int cnt = 0;
    
    forn(i, n)
    {
        cnt++;
        
        if (used[i])
            cnt = sz(t) - 1;
            
        z[idx][i] = cnt;
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    gets(s);
    n = strlen(s);
    
    cin >> m;
    
    forn(i, m)
        cin >> v[i];
        
    forn(i, m)
        calc(i, v[i]);

    /*  
    forn(i, m)
    {
        forn(j, n)
            cerr << z[i][j] << ' ';
        cerr << endl;
    }
    */
        
    int maxv = 0, anspos = 0;
    
    forn(i, n)
    {
        int cur = INF;
        forn(j, m)
            cur = min(cur, z[j][i]);
            
        if (maxv < cur)
            maxv = cur, anspos = i - cur + 1;
    }
    
    cout << maxv << ' ' << anspos << endl;

    return 0;
}