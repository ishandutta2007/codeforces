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

const int N = 500 + 13;

int n, m;
int a[N], b[N];
int used[N];
map <int, int> pos;
int next[N][N];
int d[N][N];
pt p[N][N];

int main()
{
    
    cin >> n;
    
    forn(i, n)
        scanf("%d", &a[i]);
        
    cin >> m;
    
    vector <int> v;
    
    forn(i, m)
    {
        scanf("%d", &b[i]);
        v.pb(b[i]);
    }
    
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    
    forn(i, sz(v))
        pos[v[i]] = i;
        
    forn(i, m)
        forn(j, sz(v))
            next[i][j] = INF;
        
    for (int i = m - 1; i >= 0; i--)
    {
        int num = pos[b[i]];
        
        for (int j = i - 1; j >= 0; j--)
            next[j][num] = min(next[j][num], i);
    }
    
    forn(i, n)
        forn(j, m)
        {
            p[i][j] = mp(-1, -1);
        
            if (a[i] == b[j])
                d[i][j] = 1;
        }
                
    int best = 0, id = -1, jd = -1;
                
    forn(i, n)
        forn(j, m)
        {
            if (d[i][j] == 0)
                continue;
                
            if (d[i][j] > best)
            {
                best = d[i][j];
                id = i;
                jd = j;
            }
                
            for (int k = i + 1; k < n; k++)
            {
                if (a[k] <= a[i] || pos.count(a[k]) == 0)
                    continue;
                    
                int idx = pos[a[k]];
                
                if (next[j][idx] == INF)
                    continue;
                    
                int nj = next[j][idx];
                
                if (d[k][nj] < d[i][j] + 1)
                {
                    d[k][nj] = d[i][j] + 1;
                    p[k][nj] = mp(i, j);
                }
            }
        }
        
    vector <int> ans;
    
    while (id != -1 && jd != -1)
    {
        assert(a[id] == b[jd]);
    
        ans.pb(a[id]);
        
        int oldid = id, oldjd = jd;
        
        id = p[oldid][oldjd].ft, jd = p[oldid][oldjd].sc;
    }
    
    reverse(all(ans));
    
    assert(sz(ans) == best);
    
    cout << sz(ans) << endl;
    
    forn(i, sz(ans))
        printf("%d ", ans[i]);
        
    puts("");

    return 0;
}