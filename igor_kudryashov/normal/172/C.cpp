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

const int N = 100 * 1000 + 3;

int n, m;
int t[N], x[N];
int ans[N];

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m;
    
    forn(i, n)
        scanf("%d%d", &t[i], &x[i]);
        
    int lastMan = 0, curTime = 0;
    
    while (true)
    {
        if (lastMan == n)
            break;
            
        vector <pt> v;
        
        while (sz(v) < m && lastMan < n)
        {
            v.pb(mp(x[lastMan], lastMan));
            curTime = max(curTime, t[lastMan]);
            lastMan++;
        }
        v.pb(mp(0, -1));
        
        sort(all(v));
        
        for (int i = 1; i < sz(v); )
        {
            int st = i;
            while (i < sz(v) && v[st].ft == v[i].ft)
                i++;
                
            curTime += (v[st].ft - v[st - 1].ft);
            
            for (int j = st; j < i; j++)
                ans[v[j].sc] = curTime;
                
            curTime += (1 + (i - st) / 2);
        }
        
        curTime += v.back().ft;
    }
    
    forn(i, n)
        printf("%d ", ans[i]);
        
    puts("");

    return 0;
}