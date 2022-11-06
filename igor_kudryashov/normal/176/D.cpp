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
const int INF = 2000 * 1000 * 1000 + 13;

const int N = 2000 + 3;
const int LEN = 1000 * 1000 + 3;

int n, m;
int num[N];
string base[N];
char buf[LEN];
char s[N];
int d[N][N];
vector <int> pos[N][26];
int next[N][26];
int slen;
int prefLen[N];

pt getIdx (int pos)
{
    int lf = 0, rg = m - 1;
    
    while (lf != rg)
    {
        int mid = (lf + rg) >> 1;
        
        if (prefLen[mid] <= pos)
            lf = mid + 1;
        else
            rg = mid;
    }
    return mp(lf, pos - (lf == 0 ? 0 : prefLen[lf - 1]));;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    scanf("%d\n", &n);
    
    forn(i, n)
    {
        gets(buf);
        base[i] = string(buf);
        
        forn(j, sz(base[i]))
            pos[i][base[i][j] - 'a'].pb(j);
    }
    
    scanf("%d", &m);
    
    forn(i, m)
        scanf("%d", &num[i]), num[i]--;
        
    forn(i, m)
    {
        forn(alp, 26)
        {
            next[i][alp] = -1;
            for (int j = i + 1; j < m; j++)
                if (!pos[num[j]][alp].empty())
                {
                    next[i][alp] = j;
                    break;
                }
        }
        
        prefLen[i] = (i == 0 ? 0 : prefLen[i - 1]) + sz(base[num[i]]);
    }
    
    scanf("%s", s);
    slen = strlen(s);
    
    forn(i, slen + 1)
        forn(len, slen + 1)
            d[i][len] = INF;
            
    forn(i, slen)
        forn(j, m)
        {
            int idx = num[j];
            int curchar = s[i] - 'a';
            
            if (!pos[idx][curchar].empty())
                d[i + 1][1] = min(d[i + 1][1], prefLen[j] - sz(base[idx]) + pos[idx][curchar][0]);
        }
        
    forn(poss, slen)
        forn(len, poss + 1)
        {
            int& dv = d[poss][len];
            if (dv == INF) continue;
            
            //cerr << poss << ' ' << len << ' ' << dv << endl;
            
            d[poss + 1][len] = min(d[poss + 1][len], dv);
            
            pt stridx = getIdx(dv);
            int curchar = s[poss] - 'a';
            
            int numbase = num[stridx.ft];
            
            int idx = int(lower_bound(all(pos[numbase][curchar]), stridx.sc + 1) - pos[numbase][curchar].begin());
            
            if (idx < sz(pos[numbase][curchar]))
            {
                int nd = prefLen[stridx.ft] - sz(base[num[stridx.ft]]);
                nd += pos[num[stridx.ft]][curchar][idx];
                
                d[poss + 1][len + 1] = min(d[poss + 1][len + 1], nd);
            
            } else
            {
                int snext = next[stridx.ft][curchar];
                if (snext == -1) continue;
                
                int nextidx = next[stridx.ft][curchar];
                int nd = prefLen[nextidx] - sz(base[num[nextidx]]);
                nd += pos[num[nextidx]][curchar][0];
                
                d[poss + 1][len + 1] = min(d[poss + 1][len + 1], nd);
            }
        }
        
    int ans = 0;
        
    forn(i, slen + 1)
        forn(len, slen + 1)
            if (d[i][len] != INF)
                ans = max(ans, len);
                
    cout << ans << endl;        

    return 0;
}