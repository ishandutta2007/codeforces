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

const int N = 1000 + 13;

int n;
char a[N][50];
vector <int> can[N];

char buf[4];

void gen (int idx)
{
    forn(i, 4)
    {
        forn(j, 4)
            buf[j] = a[idx][j];
            
        int st = 0;
        if (i == 0)
            st = 1;
            
        for (int cur = st; cur < 10; cur++)
        {
            buf[i] = ('0' + cur);
            
            int tmp = atoi(buf);
            
            if (tmp >= 1000 && tmp <= 2011)
                can[idx].pb(tmp);
        }
    }
}

int p[N][2 * N];

int main()
{
    
    cin >> n;
    
    forn(i, n)
    {
        scanf("%s", a[i]);
        gen(i);
        
        sort(all(can[i]));
    }
    
    memset(p, -1, sizeof(p));
    
    forn(j, sz(can[0]))
        p[0][can[0][j]] = 0;
    
    for1(i, n)
    {
        forn(j, sz(can[i]))
        {
            forn(k, sz(can[i - 1]))
            {
                if (can[i - 1][k] > can[i][j])
                    break;
            
                if (p[i - 1][can[i - 1][k]] != -1)
                {
                    p[i][can[i][j]] = can[i - 1][k];
                    break;
                }
            }
        }
    }
    
    int idx = -1;
    
    for (int i = 1000; i <= 2011; i++)
        if (p[n - 1][i] != -1)
        {
            idx = i;
            break;
        }
        
    if (idx == -1)
    {
        puts("No solution");
        return 0;
    }
    
    vector <int> ans;
    
    for (int i = n - 1; i >= 0; i--)
    {
        ans.pb(idx);
        idx = p[i][idx];
    }
    
    reverse(all(ans));
    
    forn(i, sz(ans))
        printf("%d\n", ans[i]);
    
    return 0;
}