#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 1000 + 3;
const int mod = 1000 * 1000 * 1000 + 7;

int n, k;
int next[N];
int ans = 0;
int used[N], u;
int reach[N];
int cur[N], szcur;

bool check ()
{
    int v = 0;
    u++;
    while (used[v] != u)
    {
        used[v] = u;
        v = next[v];
    }
    if (v != 0) return false;
    
    forn(i, k)
        if (used[i] == u) reach[i] = 1; else reach[i] = 0;
        
    forn(i, k)
    {
        int v = i;
        
        szcur = 0;
        
        while (used[v] != u)
        {
            cur[szcur++] = v;
            used[v] = u;
            v = next[v];
        }
        if (reach[v] != 1) return false;
        forn(j, szcur) reach[cur[j]] = 1;
    }
        
    return true;    
}

void go (int idx)
{
    if (idx == k)
    {
        ans += check();
        return;
    }
    
    forn(i, k)
    {
        next[idx] = i;
        go(idx + 1);
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> k;
    
    go(0);
    
    ans %= mod;
    
    //cerr << ans << endl;
    
    forn(i, n - k)
        ans = (ans * 1LL * (n - k)) % mod;
        
    cout << ans << endl;
    
    return 0;
}