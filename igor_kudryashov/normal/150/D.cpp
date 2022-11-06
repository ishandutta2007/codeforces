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

const int N = 150 + 13;

int n;
int a[N];
char s[N];
int p[N][N];
int z[N][N][N];
int d[N][N];

int calcZ (int, int, int);

int calcD (int lf, int rg)
{
    int& ans = d[lf][rg];
    if (ans != -1) return ans;
    
    ans = -2;
    
    for (int mid = lf; mid < rg; mid++)
    {
        int t1 = calcD(lf, mid), t2 = calcD(mid + 1, rg);
        if (t1 != -2 && t2 != -2)
            ans = max(ans, t1 + t2);
    }
    
    if (s[lf] == s[rg])
    {
        for (int len = 1; len <= rg - lf + 1; len++)
        {
            if (a[len] == -1) continue;
            
            int t = calcZ(lf + 1, rg - 1, len - 1 - (lf != rg));
            if (t == -2) continue;
            
            ans = max(ans, t + a[len]);
        }
    }
    
    return ans;
}

int calcZ (int lf, int rg, int len)
{
    int& ans = z[lf][rg][len];
    if (ans != -1) return ans;
    
    if (lf > rg)
        return ans = (len == 0 ? 0 : -2);
        
    if (len == 0)
        return ans = calcD(lf, rg);
        
    ans = -2;
        
    for (int mid = lf; mid <= rg; mid++)
    {
        if (mid != rg)
        {
            int t1 = calcZ(lf, mid, len);
            int t2 = calcD(mid + 1, rg);
            if (t1 != -2 && t2 != -2)
                ans = max(ans, t1 + t2);            
        }
        
        if (mid != lf)
        {
            int t1 = calcD(lf, mid - 1);
            int t2 = calcZ(mid, rg, len);
            if (t1 != -2 && t2 != -2)
                ans = max(ans, t1 + t2);
        }
    }
    
    if (s[lf] == s[rg])
        ans = max(ans, calcZ(lf + 1, rg - 1, len - 1 - (lf != rg)));
    
    return ans;
}

int calcP (int lf, int rg)
{
    int& ans = p[lf][rg];
    if (ans != -1) return ans;
    
    ans = 0;
    
    for (int i = lf; i < rg; i++)
        ans = max(ans, calcP(lf, i) + calcP(i + 1, rg));
        
    if (s[lf] == s[rg])
    {
        for (int len = 1; len <= rg - lf + 1; len++)
        {
            if (a[len] == -1) continue;
                
            int t = calcZ(lf + 1, rg - 1, len - 1 - (lf != rg));
            
            if (t == -2) continue;
            
            ans = max(ans, t + a[len]);
        }
    }
        
    return ans;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    for1(i, n)
        scanf("%d", &a[i]);
        
    scanf("%s", s);
    
    memset(p, -1, sizeof(p));
    memset(z, -1, sizeof(z));
    memset(d, -1, sizeof(d));
    
    cout << calcP(0, n - 1) << endl;

    return 0;
}