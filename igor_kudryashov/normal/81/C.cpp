#pragma comment(linker, "/stack:64000000")
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

const int N = 2 * 100 * 1000 + 13;

int n, a, b;
int c[N];
int cnt[13];
int ans[N];
int need[13];

void solve ()
{
    if (a < b)
    {
        for (int i = 5; i > 0; i--)
        {
            int val = min(cnt[i], a);
            need[i] = val;
            a -= val;
        }
        
        forn(i, n)
            if (need[c[i]] > 0)
                ans[i] = 1, need[c[i]]--;
            else
                ans[i] = 2;
    
    } else if (a > b)
    {
        for (int i = 1; i <= 5; i++)
        {
            int val = min(cnt[i], a);
            need[i] = val;
            a -= val;
        }
        
        forn(i, n)
            if (need[c[i]] > 0)
                ans[i] = 1, need[c[i]]--;
            else
                ans[i] = 2; 
    } else
    {
        forn(i, n / 2)
            ans[i] = 1;
            
        for (int i = n / 2; i < n; i++)
            ans[i] = 2;
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    cin >> a >> b;
    
    forn(i, n)
        scanf("%d", &c[i]), cnt[c[i]]++;
        
    solve();
    
    forn(i, n)
        printf("%d ", ans[i]);
        
    puts("");

    return 0;
}