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

const int N = 50 + 13;
const int M = N * N;

int n, m, k;
char f[N][N];
int stx, sty, finx, finy;

char c[4];
bool used[300];

pt q[N * N];
int tail, head;
int d[2][N][N];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int ansVal = INF;
string ans;
string best;

inline bool cmp (const pair <char, pt>& a, const pair <char, pt>& b)
{
    if (a.ft != b.ft)
    {
        if (a.ft == 'T')
            return true;
            
        if (b.ft == 'T')
            return false;
            
        return a.ft < b.ft;
    }
    
    return a.sc < b.sc;
}

void restore (int stx, int sty)
{   
    vector <pt> cur;
    cur.pb(mp(stx, sty));
    
    while (true)
    {
        vector <pair <char, pt> > neibs;
    
        forn(i, sz(cur))
        {
            int x = cur[i].ft, y = cur[i].sc;
            
            forn(j, 4)
            {
                int tx = x + dx[j], ty = y + dy[j];
                
                if (!correct(tx, ty, n, m) || d[0][x][y] + 1 + d[1][tx][ty] != d[0][finx][finy])
                    continue;
                    
                neibs.pb(mp(f[tx][ty], mp(tx, ty)));
            }
        }
        
        sort(all(neibs), cmp);
        neibs.erase(unique(all(neibs)), neibs.end());
        
        cur.clear();
        assert(!neibs.empty());
        
        if (neibs[0].ft == 'T')
            return;
        
        ans.pb(neibs[0].ft);
        
        forn(i, sz(neibs))
            if (neibs[i].ft == neibs[0].ft)
                cur.pb(neibs[i].sc);
            else
                break;
    }
}

/*
bool dfs (int x, int y)
{
    if (x == finx && y == finy)
        return true;
        
    vector <pair <char, pt> > neib;
    
    forn(i, 4)
    {   
        int tx = x + dx[i], ty = y + dy[i];
        
        if (!correct(tx, ty, n, m) || !used[f[tx][ty]])
            continue;
            
        if (d[0][x][y] + 1 + d[1][tx][ty] != d[0][finx][finy])
            continue;
            
        neib.pb(mp(f[tx][ty], mp(tx, ty)));
    }
    
    sort(all(neib), cmp);
    
    forn(i, sz(neib))
        if (dfs(neib[i].sc.ft, neib[i].sc.sc))
        {
            if (x != stx || y != sty)
                ans.pb(f[x][y]);
                
            return true;
        }
        
    return false;
}
*/

void bfs (int idx, int stx, int sty, int finx, int finy)
{
    memset(d[idx], 63, sizeof(d[idx]));
    d[idx][stx][sty] = 0;

    tail = head = 0;
    q[tail++] = mp(stx, sty);
    
    while (head != tail)
    {
        int x = q[head].ft, y = q[head].sc;
        head++;
        if (head == M)
            head = 0;
            
        forn(i, 4)
        {
            int tx = x + dx[i], ty = y + dy[i];
            
            if (!correct(tx, ty, n, m) || !used[f[tx][ty]])
                continue;
                
            if (d[idx][x][y] + 1 < d[idx][tx][ty])
            {
                d[idx][tx][ty] = d[idx][x][y] + 1;
                q[tail++] = mp(tx, ty);
                if (tail == M)
                    tail = 0;
            }
        }
    }
}

void go (int pos)
{
    if (pos == k)
    {
        bfs(0, stx, sty, finx, finy);
        
        if (d[0][finx][finy] > ansVal)
            return;
            
        ansVal = d[0][finx][finy];
            
        bfs(1, finx, finy, stx, sty);
        
        restore(stx, sty);
        
        if (sz(ans) < sz(best) || (sz(ans) == sz(best) && ans < best))
            best = ans;
            
        ans = "";
        
        return;
    }
    else
    {
        char stc = 'a';
        if (pos != 0)
            stc = c[pos - 1] + 1;
            
        for (char curc = stc; curc <= 'z'; curc++)
        {
            c[pos] = curc;
            used[curc] = true;
            go(pos + 1);
            used[curc] = false;
        }
    }
}

int main()
{
    
    cin >> n >> m >> k;
    
    gets(f[0]);
    forn(i, n)
        gets(f[i]);
        
    forn(i, n)
        forn(j, m)
        {
            if (f[i][j] == 'S')
                stx = i, sty = j;
                
            if (f[i][j] == 'T')
                finx = i, finy = j;
        }
        
    used['S'] = used['T'] = true;
    best = string(n * m, 'z');
        
    go(0);
    
    if (ansVal == INF)
    {
        puts("-1");
        return 0;
    }
    
    puts(best.c_str());

    return 0;
}