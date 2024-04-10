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

struct query
{
    int lf, rg;
    int idx;
};

const int N = 200 * 1000 + 13;
const int M = 1000 * 1000 + 13;

int n, m;
int a[N];
int cnt[M];
int block[N];
query q[N];
li ans[N];

inline bool cmp (const query& a, const query& b)
{
    if (block[a.lf] != block[b.lf])
        return block[a.lf] < block[b.lf];
        
    return a.rg < b.rg;
}

inline int sign (int n)
{
    return n > 0 ? 1 : n < 0 ? -1 : 0;
}

inline void add (li& ansv, int val, int dx)
{
    ansv -= li(cnt[val]) * li(cnt[val]) * li(val);
    
    cnt[val] += dx;
    
    ansv += li(cnt[val]) * li(cnt[val]) * li(val);
}

int main()
{
    
    cin >> n >> m;
    
    forn(i, n)
        scanf("%d", &a[i]);
        
    forn(i, m)
        scanf("%d%d", &q[i].lf, &q[i].rg), q[i].lf--, q[i].rg--, q[i].idx = i;
        
    int p = int(sqrt(ld(n)));
    int cur = 0, cnt = 0;
    
    forn(i, n)
    {
        block[i] = cur;
        cnt++;
        
        if (cnt == p)
            cnt = 0, cur++;
    }
        
    sort(q, q + m, cmp);
    
    li ansv = 0;
    
    forn(i, m)
        if (i == 0)
        {
            for (int j = q[i].lf; j <= q[i].rg; j++)
                add(ansv, a[j], 1);
                
            ans[q[i].idx] = ansv;
        
        } else
        {
            int prevlf = q[i - 1].lf, prevrg = q[i - 1].rg;
            int curlf = q[i].lf, currg = q[i].rg;
            int dxlf = sign(curlf - prevlf), dxrg = sign(currg - prevrg);
            
            if (dxlf == -1)
            {
                for (int j = prevlf + dxlf; j != curlf + dxlf; j += dxlf)
                    add(ansv, a[j], 1);
            
            } else if (dxlf == 1)
            {
                for (int j = prevlf; j != curlf; j += dxlf)
                    add(ansv, a[j], -1);
            }
            
            if (dxrg == -1)
            {
                for (int j = prevrg; j != currg; j += dxrg)
                    add(ansv, a[j], -1);
            
            } else if (dxrg == 1)
            {
                for (int j = prevrg + dxrg; j != currg + dxrg; j += dxrg)
                    add(ansv, a[j], 1);
            }

            ans[q[i].idx] = ansv;
        }
        
    forn(i, m)
        printf("%I64d\n", ans[i]);

    return 0;
}