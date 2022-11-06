#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <map>
#include <utility>
#include <algorithm>
#include <numeric>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for(int i = int(l); i <= int(r); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 5 * 1000 * 1000 + 13;

int n, r, c;
string s[N];
char buf[N];
int a[N];
int next[N];
int lastv[N], lastcnt[N];
pt inv[N];

inline bool read()
{
    if (scanf("%d%d%d", &n, &r, &c) != 3)
        return false;

    forn(i, n)
    {
        assert(scanf("%s", buf) == 1);
        s[i] = string(buf);
        a[i] = sz(s[i]) + 1;
    }
    c++;

    return true;
}

void prepare ()
{
    next[n] = n;
    int rg = n - 1, sum = 0;
    
    ford(lf, n)
    {
        sum += a[lf];
        while (sum > c) sum -= a[rg--];
        next[lf] = rg + 1;
    }
}

inline void solve()
{
    prepare();
    
    int ansVal = 0, ansPos = -1;
    
    forn(i, n) inv[i] = mp(-1, -1);
    
    forn(start, n)
    {
        int curcnt = 0, curptr = start;
        lastv[curptr] = start, lastcnt[curptr] = 0;
        
        while (true)
        {
            if (curcnt == r) break;
            if (next[lastv[curptr]] == lastv[curptr]) break;
            
            int v = lastv[curptr];
            
            if (inv[v] == mp(-1, -1))
            {
                inv[v] = mp(curptr, lastcnt[curptr]++);
                lastv[curptr] = next[v];
                curcnt++;               
            } else
            {
                curcnt += lastcnt[inv[v].ft] - inv[v].sc;
                assert(curcnt <= r);
                curptr = inv[v].ft;
            }
        }
        
        int curVal = lastv[curptr] - start;
        if (ansVal < curVal) ansVal = curVal, ansPos = start;
    }
    
    int start = ansPos, fin = ansPos + ansVal - 1;

    int rem = c;
    bool fir = true;

    fore(i, start, fin)
    {
        if (sz(s[i]) + 1 > rem)
        {
            rem = c;
            puts("");
            fir = true;
        }

        rem -= sz(s[i]) + 1;
        if (!fir) putchar(' ');
        fir = false;
        printf("%s", s[i].c_str());
    }
    
    puts("");
}

int main()
{
    //assert(freopen("input.txt", "rt", stdin));
    //assert(freopen("output.txt", "wt", stdout));

    assert(read());
    solve();

    return 0;
}