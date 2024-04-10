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

const int N = 1000 + 3;

int n, k;
pt p[N];
pair <int, pt> d[N * N];
int szd;
int g[N][N], szg[N];
int vs[N], szvs;
int used[N], u;
bool WRITE;
int taken[N];
int need[N][N], szneed[N];

void halt ()
{
    int cntTaken = 0;
    forn(i, n)
        if (taken[i]) printf("%d ", i + 1), cntTaken++;
    puts("");
    assert(cntTaken == k);
    cerr << clock() << endl;
    exit(0);
}

int STEPS;

bool go (int idx, int rem)
{
    if (++STEPS > 300 * 1000)
        return false;

    if (idx == szvs)
    {
        if (WRITE)
            halt();
        
        return true;
    }
    
    /*if (rem >= szvs - idx)
    {
        if (!WRITE) return true;
        
        for (int i = idx; i < szvs; i++)
            if (!taken[vs[i]] && rem > 0)
                taken[vs[i]] = true, rem--;
                
        assert(rem == 0);
        halt();             
    }*/
    
    int v = vs[idx];
    
    if (taken[v])
        return go(idx + 1, rem);
    
    /*if (szg[v] > k)
    {
        if (rem == 0) return false;
        taken[v] = true;
        bool ans = go(idx + 1, rem - 1);
        taken[v] = false;
        return ans;
    }*/

    int& cursz = szneed[idx];
    cursz = 0;
    
    bool ok = true;
    
    forn(i, szg[v])
    {
        int to = g[v][i];
        if (!taken[to])
        {
            need[idx][cursz++] = to;
            if (szg[to] == 1)
            {
                ok = false;
                break;
            }
        }
    }
            
    if (cursz == 0)
        return go(idx + 1, rem);
            
    if (rem >= cursz && ok)
    {
        forn(i, cursz)
            taken[need[idx][i]] = true;
            
        bool res = go(idx + 1, rem - cursz);
        
        forn(i, cursz)
            taken[need[idx][i]] = false;
            
        if (res)
            return true;
    }
    
    if (rem > 0 && (szg[v] > 1 || !ok))
    {
        taken[v] = true;
        bool res = go(idx + 1, rem - 1);
        taken[v] = false;
        if (res) return true;
    }
    
    return false;
}

bool can (int cntEd)
{
    szvs = 0, u++;
    forn(i, cntEd)
    {
        int a = d[i].sc.ft, b = d[i].sc.sc;
        if (used[a] != u)
        {
            used[a] = u;
            vs[szvs++] = a;
            szg[a] = 0;
        }
        
        if (used[b] != u)
        {
            used[b] = u;
            vs[szvs++] = b;
            szg[b] = 0;
        }
        
        g[a][szg[a]++] = b;
        g[b][szg[b]++] = a;
    }
    //sort(vs, vs + szvs);
    
    int cnt = 0;
    forn(i, szvs)
        if (szg[vs[i]] > k)
            taken[vs[i]] = true, cnt++;
            
    STEPS = 0;
            
    bool ans = (cnt > k ? false : go(0, k - cnt));
            
    forn(i, szvs)
        if (szg[vs[i]] > k)
            taken[vs[i]] = false, cnt++;
            
    return ans;
}

inline int dist2 (const pt& a, const pt& b) { return sqr(a.ft - b.ft) + sqr(a.sc - b.sc); }

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    //srand(time(NULL));
    
    cin >> n >> k;
    
    forn(i, n)
        scanf("%d%d", &p[i].ft, &p[i].sc);
        //p[i].ft = rand(), p[i].sc = rand();
        
    forn(i, n)
        forn(j, i)
            d[szd++] = mp(dist2(p[i], p[j]), mp(j, i));
            
    sort(d, d + szd);
    reverse(d, d + szd);
    
    int lf = 1, rg = szd;
    
    while (lf != rg)
    {   
        int mid = (lf + rg + 1) >> 1;
        
        if (can(mid))
            lf = mid;
        else
            rg = mid - 1;
    }
    
    WRITE = true;
    can(lf);
    
    return 0;
}