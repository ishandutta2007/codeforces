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

const int N = 100 * 1000 + 13;

int len, b, f, m;
li sum[N];
int car[N];

bool empty (int lf, int rg)
{
    return sum[rg] == sum[lf] && car[lf] == 0 && car[rg] == 0;
}

int main()
{
    
    cin >> len >> b >> f;
    
    cin >> m;

    memset(car, 0, sizeof(car));
    
    forn(i, m)
    {
        int type, sec;
        scanf("%d%d", &type, &sec);
        
        if (type == 1)
        {
            int curlen = sec;
            
            int pos = -1;
             
            forn(j, len - curlen + 1)
                if (empty(max(0, j - b), max(0, j - 1)) && empty(j, j + curlen - 1) && empty(min(j + curlen, len - 1), min(j + curlen + f - 1, len - 1)))
                {
                    pos = j;
                    
                    for (int p = j; p < j + curlen; p++)
                        car[p] = i + 1;
                        
                    break;
                }

            printf("%d\n", pos);
        } else
        {
            forn(j, len)
                if (car[j] == sec)
                    car[j] = 0;
        }
                    
        sum[0] = car[0];
        
        for1(j, len - 1)
            sum[j] = sum[j - 1] + car[j];
    }

    return 0;
}