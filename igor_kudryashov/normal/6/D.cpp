#pragma comment(linker, "/stack:64000000")
#define _SECURE_SCL 0
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
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

const int N = 15;

int n, a, b;
int h[N];

int fire[N];
int best = INF;
int ans[N];
int add[N];

void go (int idx, int sum)
{
    if (sum > best)
        return;

    if (idx == n - 2)
    {
        int cnt1 = fire[2] * b;
        
        if (cnt1 <= h[1])
            fire[1] = (h[1] - cnt1) / a + 1;
            
        int cnt2 = fire[n - 3];
        
        if (cnt2 <= h[n - 2])
            fire[n - 2] = (h[n - 2] - cnt2) / a + 1;
    
        int res = 0;
            
        for (int i = 1; i < n - 1; i++)
        {
            res += fire[i];
            
            if (res > best)
                return;
        
            int cnt = fire[i] * a + fire[i - 1] * b + fire[i + 1] * b;
            
            if (cnt <= h[i])
                return;
        }
        
        best = res;
        memcpy(ans, fire, sizeof(int) * n);
    
    } else
    {
        forn(i, 10)
        {
            fire[idx] = i;
            go(idx + 1, sum + i);
        }
    }
}

void writeAns ()
{
    while (h[1] >= 0)
        h[1] -= a, add[1]++;

    cout << add[1] << endl;
    
    forn(i, add[1])
        printf("%d ", 2);
        
    puts("");
        
    exit(0);
}

void solve ()
{
    pt bestAns = mp(100, 100);
    
    forn(i, 20)
        forn(j, 20)
        {
            int cnt1 = a * i + b * j;
            int cnt2 = a * j + b * i;
            
            if (cnt1 > h[1] && cnt2 > h[2] && bestAns.ft + bestAns.sc > i + j)
                bestAns = mp(i, j);
        }
        
    add[1] += bestAns.ft;
    add[2] += bestAns.sc;
    
    cout << add[1] + add[2] << endl;
    
    forn(i, add[1])
        printf("2 ");
        
    forn(j, add[2])
        printf("3 ");
        
    puts("");
    
    exit(0);
}

int main()
{
    
    cin >> n >> a >> b;
    
    forn(i, n)
        cin >> h[i];
        
    while (h[0] >= 0)
        h[1] -= a, h[0] -= b, h[2] -= b, add[1]++;
        
    while (h[n - 1] >= 0)
        h[n - 2] -= a, h[n - 1] -= b, h[n - 3] -= b, add[n - 2]++;
        
    if (n == 3)
        writeAns();
        
    if (n == 4)
        solve();
    
    go(2, 0);
    
    vector <int> res;
    
    forn(i, n)
        forn(j, ans[i] + add[i])
            res.pb(i);
            
    cout << sz(res) << endl;
    
    forn(i, sz(res))
        printf("%d ", res[i] + 1);
        
    puts("");

    return 0;
}