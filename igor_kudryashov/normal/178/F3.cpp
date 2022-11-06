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

const int SZT = 2000 * 500 + 3;

struct node
{
    int next[26];
    int term;
    
    node ()
    {
        memset(next, -1, sizeof(next));
        term = 0;
    }
};

const int N = 4000 + 13;
const int K = 2000 + 13;

int n, k;
node t[SZT];
int szt = 1;
int vs[N], szvs;
int numInVs[SZT];
vector <pt> g[N];
int cntLeafes[N];
int d[N][K];

int solve (int v, int k)
{
    int& ans = d[v][k];
    if (ans != -1) return ans;
    
    assert(0 < k && k <= cntLeafes[v]);
    
    /*if (g[v].empty())
        return ans = 0;
        
    if (k == 1)
        return ans = 0;*/
        
    int secondDim = cntLeafes[v] + 1;
        
    int** z = new int*[sz(g[v]) + 1];
    forn(i, sz(g[v]) + 1)
    {
        z[i] = new int[secondDim];
        forn(j, secondDim) z[i][j] = -1;
    }
    forn(i, t[vs[v]].term + 1) z[0][i] = 0;
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i].ft, len = g[v][i].sc;
        
        forn(j, secondDim)
        {
            int& zv = z[i][j];
            if (zv == -1) continue;
            
            z[i + 1][j] = max(z[i + 1][j], zv);
            
            for (int nowTake = 1; j + nowTake <= k && nowTake <= cntLeafes[to]; nowTake++)
            {
                int toVal = solve(to, nowTake);
                
                z[i + 1][j + nowTake] = max(z[i + 1][j + nowTake], zv + toVal + len * nowTake * (nowTake - 1) / 2);
            }
        }
    }
    
    forn(i, secondDim) d[v][i] = z[sz(g[v])][i];
    ans = z[sz(g[v])][k];
    assert(ans != -1);
    forn(i, sz(g[v]) + 1) delete(z[i]);
    delete(z);
    
    return ans;
}

int calcCnt (int v)
{
    int& ans = cntLeafes[v];
    if (ans != -1) return ans;
    
    ans = t[vs[v]].term;
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i].ft;
        ans += calcCnt(to);
    }
    
    return ans;
}

void add (const string& s)
{
    int v = 0;
    
    forn(i, sz(s))
    {
        if (t[v].next[s[i] - 'a'] == -1)
            t[v].next[s[i] - 'a'] = szt++;
            
        v = t[v].next[s[i] - 'a'];
    }
    t[v].term++;
}

pt getNext (int v)
{
    if (numInVs[v] != -1)
        return mp(v, 0);
        
    forn(i, 26)
        if (t[v].next[i] != -1)
        {
            pt tmp = getNext(t[v].next[i]);
            tmp.sc++;
            return tmp;
        }
        
    throw;
}

int perm[N], szperm;

void dfs (int v)
{
    forn(i, sz(g[v]))
    {
        int to = g[v][i].ft;
        dfs(to);
    }
    perm[szperm++] = v;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> k;
    
    forn(i, n)
    {
        char buf[513];
        scanf("%s", buf);
        
        /*forn(j, 500)
            buf[j] = rand() % 26 + 'a';
        buf[500] = 0;*/
        add(string(buf));
    }
    
    memset(numInVs, -1, sizeof(numInVs));
    
    vs[szvs] = 0;
    numInVs[0] = szvs++;
            
    for1(i, szt - 1)
    {   
        int cnt = 0;
        forn(j, 26)
            if (t[i].next[j] != -1) cnt++;
            
        if (cnt != 1 || t[i].term)
        {
            vs[szvs] = i;
            numInVs[i] = szvs++;
        }
    }

    forn(i, szvs)
        forn(j, 26)
            if (t[vs[i]].next[j] != -1)
            {
                pt tmp = getNext(t[vs[i]].next[j]);
                tmp.ft = numInVs[tmp.ft];
                tmp.sc++;
                g[i].pb(tmp);
            }
            
    memset(cntLeafes, -1, sizeof(cntLeafes));
            
    forn(i, szvs)
        cntLeafes[i] = calcCnt(i);
        
    dfs(0);
    assert(szperm == szvs);
    
    /*forn(i, szperm)
        cerr << perm[i] << ' ';
    cerr << endl;*/
        
    /*forn(i, szvs)
        cerr << cntLeafes[i] << ' ';
    cerr << endl;*/
        
    /*forn(i, szvs)
    {
        forn(j, sz(g[i]))
            cerr << g[i][j].ft << ',' << g[i][j].sc << ' ';
        cerr << endl;
    }*/

    memset(d, -1, sizeof(d));
    
    forn(i, szperm)
        solve(perm[i], cntLeafes[perm[i]]);
        
    cout << solve(0, k) << endl;
    
    cerr << clock() << endl;

    return 0;
}