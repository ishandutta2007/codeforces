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

int n, m;
li tmul[N][N][2], tadd[N][N][2];

inline int par (int x) { return (x & 1); }

inline li Xor (li t[N][N][2], int x, int y)
{
    li mul = 0, add = 0;
    
    for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
        mul ^= t[x][j][0], add ^= t[x][j][1];
        
    return (mul * par(y + 1)) ^ add;
}

inline li Xor (int x, int y)
{
    li mul = 0, add = 0;
    
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        mul ^= Xor(tmul, i, y), add ^= Xor(tadd, i, y);
        
    return (mul * par(x + 1)) ^ add;
}

inline li Xor (int ax, int ay, int bx, int by)
{
    return Xor(bx, by) ^ Xor(bx, ay - 1) ^ Xor(ax - 1, by) ^ Xor(ax - 1, ay - 1);
}

inline void upd (li t[N][N][2], int x, int y, li mul, li add)
{
    for (int i = x; i < n; i = (i | (i + 1)))
        for (int j = y; j < n; j = (j | (j + 1)))
            t[i][j][0] ^= mul, t[i][j][1] ^= add;
}

inline void upd2 (int x, int y1, int y2, li mul, li add)
{
    upd(tmul, x, y1, mul, mul * par(y1));
    upd(tmul, x, y2 + 1, mul, mul * par(y2 + 1));
    
    upd(tadd, x, y1, add, add * par(y1));
    upd(tadd, x, y2 + 1, add, add * par(y2 + 1));
}

inline void upd (int ax, int ay, int bx, int by, li val)
{
    upd2(ax, ay, by, val, val * par(ax));
    upd2(bx + 1, ay, by, val, val * par(bx + 1));
}

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2) return false;
    return true;
}

inline void solve()
{
    forn(iter, m)
    {
        int type;
        int ax, ay, bx, by;
        assert(scanf("%d%d%d%d%d", &type, &ax, &ay, &bx, &by) == 5);
        --ax, --ay, --bx, --by;
        
        //cerr << tmul[0][0][0] << ' ' << tmul[0][0][1] << endl;
        //cerr << tadd[0][0][0] << ' ' << tadd[0][0][1] << endl;
        
        if (type == 1)
        {
            printf("%I64d\n", Xor(ax, ay, bx, by));
            
        } else if (type == 2)
        {
            li val;
            assert(scanf("%I64d", &val) == 1);
            upd(ax, ay, bx, by, val);
            
        } else throw;
    }
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