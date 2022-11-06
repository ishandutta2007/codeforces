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

const int N = 100 * 1000 + 13;

li k;
int n;
int a[N];
set <pt> s;
queue <int> q;

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> k;
    
    forn(i, n)
    {
        scanf("%d", &a[i]);
        s.insert(mp(a[i], i));
    }
    
    li curCnt = 0;
    
    while (true)
    {
        if (s.empty() && k > 0)
        {
            puts("-1");
            return 0;
        }
        
        if (s.empty() && k == 0)
        {
            puts("");
            return 0;
        }
    
        li cnt = s.begin()->ft - curCnt;
        
        assert(cnt > 0);
        
        if (cnt * sz(s) <= k)
        {
            k -= cnt * sz(s);
            
            int f = s.begin()->ft;
            
            while (!s.empty() && s.begin()->ft == f)
                s.erase(s.begin());
                
            curCnt += cnt;
            
        } else
        {
            bool need = false;
            int f = s.begin()->ft;
            if ((cnt - 1) * sz(s) < k)
                need = true;
            k %= sz(s);
            
            vector <int> v;
        
            for (set <pt> :: iterator it = s.begin(); it != s.end(); it++)
                v.pb(it->sc);
                
            sort(all(v));
            
            forn(i, sz(v))
                q.push(v[i]);
            
            while (k > 0)
            {
                int v = q.front();
                q.pop();

                if (!need || a[v] != f)         
                    q.push(v);
                k--;
            }
            
            while (!q.empty())
            {
                int v = q.front();
                q.pop();
                
                printf("%d ", v + 1);
            }
                
            puts("");
            
            return 0;
        }
    }
    

    return 0;
}