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

const int N = 100 * 1000 + 13;
const int S = 500;

int n, m;
int a[N];
int cnt[S][N];
int xs[N];
int b[N], szb;

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m;
    
    forn(i, n)
    {
        scanf("%d", &a[i]);
        xs[i] = a[i];
    }
    
    sort(xs, xs + n);
    
    for (int i = 0; i < n; )
    {
        int st = i;
        while (i < n && xs[i] == xs[st]) i++;
        
        if (i - st >= xs[st]) b[szb++] = xs[st];
    }
    
    assert(szb <= S);
    
    forn(i, n)
    {
        int num = int(lower_bound(b, b + szb, a[i]) - b);
        cnt[num][i]++;
    }
    
    forn(i, szb)
        for1(j, n - 1)
            cnt[i][j] += cnt[i][j - 1];
            
    forn(i, m)
    {
        int lf, rg;
        scanf("%d%d", &lf, &rg);
        --lf, --rg;
        
        int ans = 0;
        
        forn(j, szb)
        {
            int curcnt = cnt[j][rg] - (lf == 0 ? 0 : cnt[j][lf - 1]);
            if (curcnt == b[j])
                ans++;
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}