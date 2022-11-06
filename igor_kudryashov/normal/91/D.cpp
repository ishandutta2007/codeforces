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

int n;
int p[N];
queue <int> cyc[N];
int szcyc;
set <pt> s;
int used[N], U = 0;
vector <int> ans1[N], ans2[N];
int szans = 0;

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    forn(i, n)
        scanf("%d", &p[i]), p[i]--;
        
    U++;
    forn(i, n)
    {
        if (used[i] == U || p[i] == i)
            continue;
        
        int v = i;
        while (used[v] != U)
        {
            cyc[szcyc].push(v);
            used[v] = U;
            v = p[v];
        }
        
        s.insert(mp(sz(cyc[szcyc]), szcyc));
        szcyc++;
    }
    
    while (!s.empty() && (--s.end())->ft > 3)
    {
        int num = (--s.end())->sc;
        s.erase(--s.end());
        
        if (sz(cyc[num]) <= 5)
        {
            while (!cyc[num].empty())
            {
                int cur = cyc[num].front();
                cyc[num].pop();
                ans1[szans].pb(cur);
                ans2[szans].pb(p[cur]);
            }
        
        } else
        {
            forn(i, 5)
            {
                int cur = cyc[num].front();
                cyc[num].pop();
                if (i == 4)
                {
                    ans1[szans].pb(cur);
                    ans2[szans].pb(cyc[num].back());
                    
                    p[cyc[num].back()] = p[cur];
                
                } else
                {
                    ans1[szans].pb(cur);
                    ans2[szans].pb(p[cur]);
                    
                    if (i == 0)
                        cyc[num].push(cur);
                }
            }
            
            s.insert(mp(sz(cyc[num]), num));
        }
        
        szans++;
    }
    
    while (!s.empty() && s.begin()->ft == 2 && (--s.end())->ft == 3)
    {
        int num = s.begin()->sc;
        s.erase(s.begin());
        while (!cyc[num].empty())
        {
            int cur = cyc[num].front();
            cyc[num].pop();
            ans1[szans].pb(cur);
            ans2[szans].pb(p[cur]);
        }
        
        num = (--s.end())->sc;
        s.erase(--s.end());
        while (!cyc[num].empty())
        {
            int cur = cyc[num].front();
            cyc[num].pop();
            ans1[szans].pb(cur);
            ans2[szans].pb(p[cur]);
        }
        
        szans++;
    }
    
    if (!s.empty() && (--s.end())->ft == 2)
    {
        while (!s.empty())
        {
            int num = s.begin()->sc;
            s.erase(s.begin());
            while (!cyc[num].empty())
            {
                int cur = cyc[num].front();
                cyc[num].pop();
                ans1[szans].pb(cur);
                ans2[szans].pb(p[cur]);
            }
            
            if (!s.empty())
            {
                num = s.begin()->sc;
                s.erase(s.begin());
                while (!cyc[num].empty())
                {
                    int cur = cyc[num].front();
                    cyc[num].pop();
                    ans1[szans].pb(cur);
                    ans2[szans].pb(p[cur]);
                }
            }
            
            szans++;
        }
    
    } else if (!s.empty() && (--s.end())->ft == 3)
    {
        //assert(s.begin()->ft == 3);
        
        while (!s.empty())
            if (sz(s) == 1)
            {
                //assert(s.begin()->ft == 3);
                int num = s.begin()->sc;
                s.erase(s.begin());
                while (!cyc[num].empty())
                {
                    int cur = cyc[num].front();
                    cyc[num].pop();
                    ans1[szans].pb(cur);
                    ans2[szans].pb(p[cur]);
                }
                szans++;
                
            } else if (s.begin()->ft == 2 && (--s.end())->ft == 3)
            {
                int num = s.begin()->sc;
                s.erase(s.begin());
                while (!cyc[num].empty())
                {
                    int cur = cyc[num].front();
                    cyc[num].pop();
                    ans1[szans].pb(cur);
                    ans2[szans].pb(p[cur]);
                }
                
                num = (--s.end())->sc;
                s.erase(--s.end());
                while (!cyc[num].empty())
                {
                    int cur = cyc[num].front();
                    cyc[num].pop();
                    ans1[szans].pb(cur);
                    ans2[szans].pb(p[cur]);
                }
                
                szans++;
                
            } else
            {
                int num = s.begin()->sc;
                s.erase(s.begin());
                while (!cyc[num].empty())
                {
                    int cur = cyc[num].front();
                    cyc[num].pop();
                    ans1[szans].pb(cur);
                    ans2[szans].pb(p[cur]);
                }
                
                num = s.begin()->sc;
                s.erase(s.begin());
                int cur1 = cyc[num].front(); cyc[num].pop();
                int cur2 = cyc[num].front(); cyc[num].pop();
                ans1[szans].pb(cur1);
                ans1[szans].pb(cur2);
                ans2[szans].pb(cur2);
                ans2[szans].pb(cur1);
                p[cur1] = p[cur2];
                cyc[num].push(cur1);
                                
                s.insert(mp(sz(cyc[num]), num));

                szans++;
                
            }
    }
    
    printf("%d\n", szans);
    
    forn(i, szans)
    {
        printf("%d\n", sz(ans1[i]));
        
        forn(j, sz(ans1[i]))
            printf("%d ", ans1[i][j] + 1);
        puts("");
        
        forn(j, sz(ans2[i]))
            printf("%d ", ans2[i][j] + 1);
        puts("");
    }

    return 0;
}