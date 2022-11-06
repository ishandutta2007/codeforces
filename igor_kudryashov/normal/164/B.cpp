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

const int N = 2000 * 1000 + 3;

int n, m;
int a[N], b[N];
int pos1[N], pos2[N];

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m;
    
    memset(pos1, -1, sizeof(pos1));
    memset(pos2, -1, sizeof(pos2));
    
    forn(i, n)
    {
        //a[i] = i;
        scanf("%d", &a[i]);
        a[n + i] = a[i];
        pos1[a[i]] = i;
    }
    
    forn(i, m)
    {
        //b[i] = m - i;
        scanf("%d", &b[i]);
        pos2[b[i]] = i;
    }
    
    int ans = 0;
    int lf = 0, rg = 0;
    queue <li> q;
    li last = 0;
    
    while (lf < n)
    {
        while (rg - lf < n && pos2[a[rg]] != -1)
        {
            li curLast = pos2[a[rg]];
            curLast += (last / m) * m;
            while (curLast < last) curLast += m;
            
            if (q.empty() || curLast - q.front() < m)
            {
                q.push(curLast);
                last = curLast;
                rg++;
                
            } else
                break;
        }
        
        ans = max(ans, sz(q));
        
        if (pos2[a[lf]] != -1)
        {
            //cerr << a[lf] << ' ' << pos2[a[lf]] << ' ' << q.front() << endl;
            assert(abs(pos2[a[lf]] - q.front()) % m == 0);
            q.pop();
        }
        
        lf++;
        if (rg < lf)
        {
            assert(lf == rg + 1);
            rg++;
        }
    }
    
    cout << ans << endl;

    return 0;
}