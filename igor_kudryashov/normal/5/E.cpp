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

const int N = 1000 * 1000 + 13;

int n;
int tmp[N];
int a[N];
li ans = 0;
vector <int> val, cnt;
int used[N];

int main()
{
    
    cin >> n;
    
    int id = 0;
    
    forn(i, n)
    {
        scanf("%d", &tmp[i]);
        
        if (tmp[i] > tmp[id])
            id = i;
    }
    
    forn(i, n)
    {
        a[i] = tmp[id++];
        
        if (id == n)
            id = 0;
    }
    
    forn(i, n)
    {
        if (a[i] == a[0])
            val.clear(), cnt.clear();
        else
        {
            while (!val.empty() && val.back() < a[i])
            {
                ans += cnt.back();
                val.pop_back();
                cnt.pop_back();
            }
            
            if (!val.empty() && a[i] == val.back())
            {
                ans += cnt.back();
                
                if (sz(val) > 1)
                    ans++;
                    
                cnt.back()++;
            } else
            {
                if (!val.empty())
                    ans++;
            
                val.pb(a[i]);
                cnt.pb(1);
            }
        }
    }
    
    vector <int> pos;
    
    forn(i, n)
        if (a[i] == a[0])
            pos.pb(i);
            
    ans += sz(pos) * 1LL * (sz(pos) - 1) / 2;
    
    if (sz(pos) == 1)
    {
        int idx = n - 1;
        int maxv = 0;
        
        while (true)
        {
            if (a[idx] == a[0])
                break;
                
            if (a[idx] >= maxv)
                used[idx] = true;
                
            maxv = max(maxv, a[idx--]);
        }
        
        idx = 1;
        maxv = 0;
        
        while (true)
        {
            if (a[idx] == a[0])
                break;
                
            if (a[idx] >= maxv)
                used[idx] = true;
                
            maxv = max(maxv, a[idx]);
            
            idx++;
            if (idx == n)
                idx -= n;
        }
        
        forn(i, n)
            ans += used[i];
    
    } else
    {
        forn(i, sz(pos))
        {
            int idx = pos[i] - 1 < 0 ? n - 1 : pos[i] - 1;
            int maxv = 0;
            
            while (true)
            {
                if (a[idx] == a[0])
                    break;
                    
                if (a[idx] >= maxv)
                    ans++;
                    
                maxv = max(maxv, a[idx]);
                
                idx--;
                if (idx < 0)
                    idx += n;
            }
            
            idx = pos[i] + 1 == n ? 0 : pos[i] + 1;
            maxv = 0;
            
            while (true)
            {
                if (a[idx] == a[0])
                    break;
                    
                if (a[idx] >= maxv)
                    ans++;
                    
                maxv = max(maxv, a[idx]);
                
                idx++;
                if (idx == n)
                    idx -= n;
            }
        }
    }
    
    cout << ans << endl;

    return 0;
}