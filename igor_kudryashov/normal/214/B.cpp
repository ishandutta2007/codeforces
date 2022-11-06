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

int cnt[10];
int rem;

inline bool read()
{
    int n;
    assert(scanf("%d", &n) == 1);
    forn(i, n)
    {
        int a;
        assert(scanf("%d", &a) == 1);
        cnt[a]++;
        rem += a;
    }
    rem %= 3;
    return true;
}

inline void print()
{
    bool ok = false;
    forn(i, 10) if (cnt[i] > 0) ok = true;
    if (cnt[0] == 0) ok = false;
    if (!ok)
        puts("-1");
    else
    {
        bool mean = false;
        forl(i, 9) mean = mean || (cnt[i] > 0);
        if (!mean) cnt[0] = 1;
        ford(dig, 10)
            forn(i, cnt[dig]) putchar('0' + dig);
        puts("");
    }
    exit(0);
}

inline void solve()
{
    if (rem == 0) print();
    
    forn(i, 10)
        if (cnt[i] > 0 && i % 3 == rem)
        {
            cnt[i]--;
            print();
        }
        
    forn(i, 10)
        forn(j, i + 1)
        {
            --cnt[i], --cnt[j];
            if (cnt[i] >= 0 && cnt[j] >= 0)
            {
                int currem = (rem - i - j) % 3;
                if (currem == 0) print();
            }
            ++cnt[i], ++cnt[j];
        }
        
    puts("-1");         
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    assert(read());
    solve();
    
    return 0;
}