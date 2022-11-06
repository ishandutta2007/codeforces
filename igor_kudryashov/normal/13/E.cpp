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

const int N = 100 * 1000 + 3;

int n, m;
int a[N];
int next[N], nextBlock[N], cnt[N];
int numBlock[N];
int BLOCK = 350;

void relax (int idx)
{
    if (numBlock[next[idx]] != numBlock[idx])
    {
        nextBlock[idx] = next[idx];
        cnt[idx] = 1;
    
    } else
    {
        nextBlock[idx] = nextBlock[next[idx]];
        cnt[idx] = cnt[next[idx]] + 1;
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m;
    
    forn(i, n)
    {
        scanf("%d", &a[i]);
        next[i] = (i + a[i] >= n ? n : i + a[i]);
    }
        
    forn(i, n)
        numBlock[i] = i / BLOCK;
    numBlock[n] = n / BLOCK + 1;
    
    ford(i, n)
        relax(i);
        
    forn(i, m)
    {
        int type;
        scanf("%d", &type);
        
        if (type == 0)
        {
            int idx, val;
            scanf("%d%d", &idx, &val);
            --idx;
            next[idx] = (idx + val >= n ? n : idx + val);
            
            for (int j = idx; j >= 0 && numBlock[j] == numBlock[idx]; j--)
                relax(j);
        
        } else
        {
            int idx;
            scanf("%d", &idx);
            --idx;
            
            int res = 0;
            int last = -1;
            
            for (int v = idx; v != n; v = nextBlock[v])
                last = v, res += cnt[v];
                
            while (next[last] != n)
                last = next[last];
                
            printf("%d %d\n", last + 1, res);
        }
    }

    return 0;
}