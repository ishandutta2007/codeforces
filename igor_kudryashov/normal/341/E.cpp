#undef NDEBUG
#ifdef SU2_PROJ
#define _GLIBCXX_DEBUG
#endif

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
inline ostream& operator<< (ostream& out, const pt& p) { return out << '(' << p.x << ", " << p.y << ')'; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 1000 + 13;

int n;
int a[N];
set <pt> s;

inline bool read()
{
    if (scanf("%d", &n) != 1)
        return false;
        
    forn(i, n)
    {
        assert(scanf("%d", &a[i]) == 1);
        if (a[i] > 0) s.insert(mp(a[i], i));
    }
        
    return true;
}

vector <pt> ans;

void calc (int A, int B, int C)
{
    int a = ::a[A], b = ::a[B], c = ::a[C];
    
    int r = b % a;
    int q = b / a;
    
    vector <int> d;
    forn(i, 20) if (q & (1 << i)) d.pb(i);
    
    int starta = a;
    
    forn(i, sz(d))
    {
        int needa = starta * (1 << d[i]);
        
        while (a != needa)
        {
            c -= a;
            a *= 2;
            ans.pb(mp(A, C));
        }
        
        b -= a;
        a *= 2;
        
        ans.pb(mp(A, B));
    }
    
    assert(b == r);
    
    ::a[A] = a;
    ::a[B] = b;
    ::a[C] = c;
}

inline void solve()
{
    if (sz(s) == 2)
    {
        puts("0");
        return;
    }
    
    if (sz(s) < 2)
    {
        puts("-1");
        return;
    }
    
    while (sz(s) != 2)
    {
        int a1 = s.begin()->sc;
        s.erase(s.begin());
        int a2 = s.begin()->sc;
        s.erase(s.begin());
        int a3 = s.begin()->sc;
        s.erase(s.begin());
        
        calc(a1, a2, a3);
        
        if (a[a1] > 0) s.insert(mp(a[a1], a1));
        if (a[a2] > 0) s.insert(mp(a[a2], a2));
        if (a[a3] > 0) s.insert(mp(a[a3], a3));
    }
    
    cout << sz(ans) << endl;
    
    forn(i, sz(ans)) printf("%d %d\n", ans[i].ft + 1, ans[i].sc + 1);
}

int main()
{
#ifdef SU2_PROJ
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    assert(read());
    solve();
    
#ifdef SU2_PROJ
    cerr << "== TIME: " << clock() << " ==" << endl;
#endif

    return 0;
}