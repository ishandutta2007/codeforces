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
int a[N][N];

int used[N], u;

void check ()
{
    forn(i, n)
    {
        u++;
    
        forn(j, n)
        {
            assert(a[i][j] >= 0 && a[i][j] < n);
            assert(a[i][j] == a[j][i] && used[a[i][j]] != u);
            used[a[i][j]] = u;
        }
    }
}

void fillEven (int idx)
{
    forn(i, idx)
    {
        assert(a[i][idx - 1 - i] == -1);
        a[i][idx - 1 - i] = idx;
    }
    
    if (idx == n - 2)
    {
        assert(a[n - 2][n - 1] == -1 && a[n - 1][n - 2] == -1);
        a[n - 2][n - 1] = a[n - 1][n - 2] = idx;
        return;
    }
    
    int fin = (n - 2 - idx) / 2;
    
    forn(i, fin)
    {
        assert(a[idx + i][n - 2 - i] == -1 && a[n - 2 - i][idx + i] == -1);
        a[idx + i][n - 2 - i] = a[n - 2 - i][idx + i] = idx;
    }
    
    assert(a[n - 1][n / 2 - 1 + idx / 2] == -1 && a[n / 2 - 1 + idx / 2][n - 1] == -1);
    a[n - 1][n / 2 - 1 + idx / 2] = a[n / 2 - 1 + idx / 2][n - 1] = idx;
}

void fillOdd (int idx)
{
    forn(i, idx)
    {
        if (i == idx - 1 - i)
            continue;
            
        assert(a[i][idx - 1 - i] == -1);
        a[i][idx - 1 - i] = idx;
    }
    
    assert(a[idx / 2][n - 1] == -1 && a[n - 1][idx / 2] == -1);
    a[idx / 2][n - 1] = a[n - 1][idx / 2] = idx;
    
    forn(i, n - 1 - idx)
    {
        assert(a[idx + i][n - 2 - i] == -1);
        a[idx + i][n - 2 - i] = idx;
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    memset(a, -1, sizeof(a));
    
    forn(i, n)
    {
        a[i][i] = 0;
        a[i][n - 1 - i] = 1;
    }
    
    for (int i = 2; i < n; i++)
        if (i & 1)
            fillOdd(i);
        else
            fillEven(i);
            
    check();
            
    forn(i, n)
    {
        forn(j, n)
            printf("%d ", a[i][j]);
            
        puts("");
    }
        
    return 0;
}