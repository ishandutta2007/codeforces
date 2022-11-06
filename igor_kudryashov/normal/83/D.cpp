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
const int INF = 2000 * 1000 * 1000 + 13;

const int N = 50 * 1000 + 13;

int a, b, k;
int prime[N];
int szprime;
int least[N];

int solve (int n, int k)
{
    int maxd = n / k;
    int res = 0;
    
    if (maxd < N)
    {
        for1(i, maxd)
            if (least[i] >= k)
                res++;
    
    } else
    {
        res = maxd;
    
        forn(i, szprime)
            if (prime[i] < k)
                res -= solve(maxd, prime[i]);
            else
                break;
    }
    
    return res;
}

inline bool isPrime (int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
            
    return true;
}

int main()
{
    
    memset(least, -1, sizeof(least));
    least[1] = INF;
    
    for (int i = 2; i < N; i++)
    {
        if (least[i] != -1)
            continue;
        
        prime[szprime++] = i;
        
        for (int j = i; j < N; j += i)
            if (least[j] == -1)
                least[j] = i;
    }
    
    cin >> a >> b >> k;
    
    if (!isPrime(k))
    {
        puts("0");
        return 0;
    }
    
    cout << solve(b, k) - solve(a - 1, k) << endl;

    return 0;
}