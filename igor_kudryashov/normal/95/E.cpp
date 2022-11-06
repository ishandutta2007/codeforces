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
vector <int> g[N];
int v[N], szv;
int used[N];
int C;
pt a[N];
int sza;
int c[N];

void dfs (int v)
{
    used[v] = true;
    C++;
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        if (!used[to])
            dfs(to);
    }
}

int bit[30];

inline bool good (int n)
{
    if (n == 0)
        return false;

    while (n > 0)
        if (n % 10 != 4 && n % 10 != 7)
            return false;
        else
            n /= 10;
            
    return true;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    forn(i, 30)
        bit[i] = (1 << i);
    
    cin >> n >> m;
    
    forn(i, m)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    forn(i, n)
        if (!used[i])
        {
            C = 0;
            dfs(i);
            v[szv++] = C;
        }
    
    sort(v, v + szv);
    
    for (int i = 0; i < szv; )
    {
        int st = i;
        while (i < szv && v[st] == v[i])
            i++;
            
        int cnt = i - st;
        if (cnt & (cnt + 1))
        {
            int deg = 0;
            while (bit[deg] - 1 < cnt)
                deg++;
            deg--;
            assert(bit[deg] - 1 < cnt && bit[deg + 1] - 1 > cnt);
            int ncnt = bit[deg] - 1;
            a[sza++] = mp(v[st] * (cnt - ncnt), cnt - ncnt);
            cnt = ncnt;
        }
        
        assert((cnt & (cnt + 1)) == 0);
        
        int deg = 0;
        while (bit[deg] <= cnt)
        {
            a[sza++] = mp(v[st] * bit[deg], bit[deg]);
            deg++;
        }
    }
    
    sort(a, a + sza);
    
    memset(c, 63, sizeof(c));
    c[0] = 0;
    
    forn(i, sza)
        for (int j = n; j >= a[i].ft; j--)
            c[j] = min(c[j], c[j - a[i].ft] + a[i].sc);
            
    int ans = INF;
            
    for1(i, n)
        if (good(i))
            ans = min(ans, c[i] - 1);
            
    if (ans > INF / 2)
        ans = -1;
        
    cout << ans << endl;

    return 0;
}