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

int n, k;
set <int> lucky;

void go (int pos, int cur)
{
    if (pos > 0)
        lucky.insert(cur);
        
    if (pos == 9)
        return;
        
    go(pos + 1, cur * 10 + 4);
    go(pos + 1, cur * 10 + 7);
}

int cntLucky (int last)
{
    int ans = 0;
    
    for (set <int> :: iterator it = lucky.begin(); it != lucky.end(); it++)
        if (*it <= last)
            ans++;
        else
            break;
            
    return ans;
}

inline bool isLucky (int a)
{
    return lucky.count(a);
}

li fact[15];

vector <int> getPerm (int n, int k)
{
    if (fact[n] < k)
        return vector <int> (1, -1);
        
    vector <int> can(n);
    forn(i, n)
        can[i] = i;
        
    k--;
    
    vector <int> ans;
    
    forn(i, n)
    {
        li rg = 0;
        
        forn(j, sz(can))
        {
            if (rg + fact[sz(can) - 1] <= k)
            {
                rg += fact[sz(can) - 1];
                continue;
            }
            
            k -= rg;
            ans.pb(can[j]);
            can.erase(can.begin() + j);
            break;
        }
    }
    
    assert(k == 0 && sz(ans) == n);
    
    return ans;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    fact[0] = 1LL;
    for1(i, 14)
        fact[i] = fact[i - 1] * i;
    
    cin >> n >> k;
    
    go(0, 0);
    
    vector <int> perm = getPerm(min(13, n), k);
    
    /*forn(i, sz(perm))
        cerr << perm[i] + 1 << ' ';
    cerr << endl;*/
    
    if (sz(perm) == 1 && perm[0] == -1)
    {
        puts("-1");
        return 0;
    }
    
    int last = max(0, n - 13);
    
    int ans = cntLucky(last);
    
    forn(i, sz(perm))
    {
        int num = perm[i] + last + 1;
        int idx = last + 1 + i;
        
        if (isLucky(num) && isLucky(idx))
            ans++;
    }
    
    cout << ans << endl;

    return 0;
}