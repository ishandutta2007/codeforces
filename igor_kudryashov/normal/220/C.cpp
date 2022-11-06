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

const int N = 200 * 1000 + 13;

int n;
int p1[N], p2[N], num[N];
int ans[N];
int lfmax[N], rgmax[N];

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    forn(i, n)
    {
        scanf("%d", &p1[i]);
        --p1[i];
        num[p1[i]] = i;
    }
    
    memset(ans, 63, sizeof(ans));
    memset(lfmax, -1, sizeof(lfmax));
    memset(rgmax, -1, sizeof(rgmax));
    
    forn(i, n)
    {
        scanf("%d", &p2[i]);
        --p2[i];
        
        int d = i - num[p2[i]];
        if (d < 0) d += n;
        
        int currg = num[p2[i]], curlf = n - 1 - num[p2[i]];
        
        ans[d] = ans[d + n] = 0;
        rgmax[d] = max(rgmax[d], currg);
        lfmax[d] = max(lfmax[d], curlf);
        
        rgmax[d + n] = max(rgmax[d + n], currg);
        lfmax[d + n] = max(lfmax[d + n], curlf);
    }
    
    /*forn(i, 2 * n)
        cerr << rgmax[i] << ' ';
    cerr << endl;   */
    
    vector <pt> st;
    
    forn(i, 2 * n)
    {
        if (rgmax[i] != -1)
            st.pb(mp(i, rgmax[i]));
            
        while (!st.empty() && st.back().ft + st.back().sc < i)
            st.pop_back();
            
        if (!st.empty())
            ans[i] = min(ans[i], i - st.back().ft);
    }
    
    st.clear();
    
    ford(i, 2 * n)
    {
        if (lfmax[i] != -1)
            st.pb(mp(i, lfmax[i]));
            
        while (!st.empty() && st.back().ft - st.back().sc > i)
            st.pop_back();
            
        if (!st.empty())
            ans[i] = min(ans[i], st.back().ft - i);
    }
    
    forn(i, n)
        printf("%d\n", min(ans[i], ans[i + n]));    
    
    return 0;
}