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

string toStr (int n)
{
    string res = "";
    
    while (n > 0)
        res.pb(n % 10 + '0'), n /= 10;
        
    if (res.empty()) res.pb('0');
    
    reverse(all(res));
    
    return res;
}

const int N = 100 * 1000 + 13;

int deg[10];
int ans;
int cur[5];
int good[10];
int prime[N];
string pr;
int len;

void go (int x, int y)
{
    if (x == len)
    {
        int res = 1;
        
        for1(i, len - 1)
        {
            int curVal = 0;
            
            forn(j, 10)
                if (prime[cur[i] + j * deg[len - 1 - i]])
                    curVal++;
                    
            res *= curVal;
            if (res == 0) break;
        }
        
        ans += res;
        return;
    }
    
    if (y == len)
        return go(x + 1, x + 2);
        
    forn(i, 10)
    {
        if (y == len - 1 && !good[i]) continue;
        
        int cur1 = cur[x], cur2 = cur[y];
        
        cur[x] += i * deg[len - 1 - y];
        cur[y] += i * deg[len - 1 - x];
        
        go(x, y + 1);
        
        cur[x] = cur1;
        cur[y] = cur2;
    }
}

int solve (int p)
{
    ans = 0;
    cur[0] = p;
    
    pr = toStr(p);
    len = sz(pr);
    
    for1(i, len - 1)
        cur[i] = (pr[i] - '0') * deg[len - 1];
        
    go(1, 2);
    
    return ans;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    deg[0] = 1;
    for1(i, 9) deg[i] = deg[i - 1] * 10;
    
    forn(i, 10)
        if (i % 2 == 1 || i == 2) good[i] = true;
        
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    
    for (int i = 2; i < N; i++)
        if (prime[i])
            for (int j = 2 * i; j < N; j += i)
                prime[j] = false;
    
    int testCount;
    cin >> testCount;
    
    forn(test, testCount)
    {
        int p;
        scanf("%d", &p);
        printf("%d\n", solve(p));
    }

    return 0;
}