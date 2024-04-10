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
const int ALP = 30;

int n, k;
string t;
int used[N];
int p[N];
int pa[N][ALP];
int m;
string ans;
int z[N][N];

int go (int pos, int pf)
{
    int& res = z[pos][pf];
    
    if (res != -1)
        return res;
        
    if (pos == n)
        return 1;
        
    forn(i, k)
    {
        int nw = pa[pf][i];
        
        if (pos + 1 >= m - 1 && (used[pos + 1 - (m - 1)] != (nw == m - 1)))
            continue;
            
        if (go(pos + 1, nw) == 1)
        {
            ans.pb('a' + i);
            return res = 1;
        }
    }
    
    return res = 0;
}

int main()
{
    
    cin >> n >> k >> t;
    t.pb('$');
    m = sz(t);
    
    forn(i, n)
    {
        char c;
        cin >> c;
        used[i] = (c == '1');
    }
    
    for1(i, m - 1)
    {
        int j = i - 1;
        
        while (j > 0 && t[p[j]] != t[i])
            j = p[j] - 1;
            
        if (j > 0)
            p[i] = p[j] + 1;
        else
            p[i] = (t[0] == t[i]);
    }
    
    forn(i, m)
        forn(j, k)
            if ('a' + j == t[i])
                pa[i][j] = i + 1;
            else if (i > 0)
                pa[i][j] = pa[p[i - 1]][j];
    
    memset(z, -1, sizeof(z));
                
    if (!go(0, 0))
        cout << "No solution" << endl;
    else
    {
        reverse(all(ans));
        cout << ans << endl;
    }   
    
    return 0;
}