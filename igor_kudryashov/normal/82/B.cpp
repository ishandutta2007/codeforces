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
const int INF = 1000 * 1000 * 1000;

const int N = 200 + 13;

int n, m;
vector <int> s[N];
int used[N];

int main()
{
    
    cin >> n;
    m = n * (n - 1) / 2;
    
    forn(i, m)
    {
        int k;
        scanf("%d", &k);
        
        vector <int> cur;
        
        forn(j, k)
        {
            int tmp;
            scanf("%d", &tmp);
            cur.pb(tmp);
        }
        
        sort(all(cur));
        assert(unique(all(cur)) == cur.end());
        
        forn(j, sz(cur))
            s[cur[j]].pb(i);
    }
    
    forn(i, N)
    {
        if (s[i].empty())
            continue;
            
        assert(sz(s[i]) == n - 1);
        sort(all(s[i]));
    }

    bool flag = false;
    
    forn(i, N)
    {
        if (s[i].empty() || used[i])
            continue;
            
        vector <int> cur;
        cur.pb(i);
            
        if (n == 2 && !flag)
        {
            printf("1 %d\n", cur[0]);
            flag = true;
            continue;
        }
            
        for (int j = i + 1; j < N; j++)
        {
            if (s[j].empty())
                continue;
        
            bool ok = true;
            
            forn(k, sz(s[i]))
                if (s[i][k] != s[j][k])
                {
                    ok = false;
                    break;
                }
            
            if (!ok)
                continue;
                
            used[j] = true;
            cur.pb(j);
        }
        
        printf("%d ", sz(cur));
        
        forn(j, sz(cur))
            printf("%d ", cur[j]);
            
        puts("");
    }

    return 0;
}