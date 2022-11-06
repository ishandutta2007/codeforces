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

const int ALP = 30;
const int N = 200 * 1000 + 13;

vector <int> pos[ALP];

char buf[N];

li solve ()
{
    int n = strlen(buf);
    
    li ans = 0;
    
    forn(i, n)
    {
        int c = (buf[i] - 'a');
        
        if (pos[c].empty())
        {
            ans += n;
        } else
        {
            int minv = INF;
            
            int k = int(lower_bound(all(pos[c]), i) - pos[c].begin());
            
            for (int j = -2; j <= 2; j++)
                if (k + j >= 0 && k + j < sz(pos[c]))
                    minv = min(minv, abs(pos[c][k + j] - i));
                    
            ans += minv;
        }
    }
    
    return ans;
}

int main()
{
    
    int n, m;
    
    cin >> n >> m;
    scanf("%s", buf);
    
    forn(i, m)
        pos[buf[i] - 'a'].pb(i);
        
    forn(i, n)
    {
        scanf("%s", buf);
        printf("%I64d\n", solve());
    }   

    return 0;
}