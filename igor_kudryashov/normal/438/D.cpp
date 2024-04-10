#undef NDEBUG
#ifdef SU2_PROJ
#define _GLIBCXX_DEBUG
#endif

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

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

const int N = 100 * 1000 + 13;
const int SN = 1000 + 13;

int n, m;
int a[N];

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2) return false;
    
    forn(i, n) assert(scanf("%d", &a[i]) == 1);
    
    return true;
}

int blockLen, blockCnt;
vector <pt> blocks[SN];
li sum[SN];

inline void prepare ()
{
    blockLen = int(sqrt(ld(n)));
    blockCnt = (n + blockLen - 1) / blockLen;
    
    forn(i, n)
    {
        int numBlock = i / blockLen;
        blocks[numBlock].pb(mp(a[i], i));
        sum[numBlock] += a[i];
    }
    
    forn(i, blockCnt) sort(all(blocks[i]));
}

inline void Insert (int numBlock, const pt& val)
{
    blocks[numBlock].pb(val);
    
    int p = sz(blocks[numBlock]) - 1;
    
    while (p > 0 && blocks[numBlock][p].ft < blocks[numBlock][p - 1].ft)
        swap(blocks[numBlock][p], blocks[numBlock][p - 1]), p--;
}

inline void NaiveMod (int numBlock, int lf, int rg, int mod)
{
    bool was = false;
    
    forn(i, sz(blocks[numBlock]))
    {
        int idx = blocks[numBlock][i].sc;
        if (lf <= idx && idx <= rg && blocks[numBlock][i].ft >= mod)
        {
            sum[numBlock] -= blocks[numBlock][i].ft;
            blocks[numBlock][i].ft %= mod;
            sum[numBlock] += blocks[numBlock][i].ft;
            was = true;
        }
    }
    
    if (was) sort(all(blocks[numBlock]));
}

inline void takeMod (int lf, int rg, int mod)
{
    int start = lf / blockLen;
    int finish = rg / blockLen;
    
    NaiveMod(start, lf, min(rg, (start + 1) * blockLen - 1), mod);
    NaiveMod(finish, max(lf, finish * blockLen), rg, mod);
    
    fore(i, start + 1, finish - 1)
    {
        while (blocks[i].back().ft >= mod)
        {
            pt tmp = blocks[i].back();
            blocks[i].pop_back();
            sum[i] -= tmp.ft;
            tmp.ft %= mod;
            sum[i] += tmp.ft;
            Insert(i, tmp);
        }
    }
}

inline void assign (int pos, int val)
{
    int numBlock = pos / blockLen;
    
    forn(i, sz(blocks[numBlock]))
        if (blocks[numBlock][i].sc == pos)
        {
            sum[numBlock] -= blocks[numBlock][i].ft;
            blocks[numBlock][i].ft = val;
            sum[numBlock] += blocks[numBlock][i].ft;
            pt tmp = blocks[numBlock][i];
            blocks[numBlock].erase(blocks[numBlock].begin() + i);
            Insert(numBlock, tmp);
            return;         
        }
}

inline li naive (int numBlock, int lf, int rg)
{
    li res = 0;
    forn(i, sz(blocks[numBlock]))
        if (lf <= blocks[numBlock][i].sc && blocks[numBlock][i].sc <= rg)
            res += blocks[numBlock][i].ft;
    return res;
}

inline li Sum (int lf, int rg)
{
    int start = lf / blockLen;
    int finish = rg / blockLen;
    
    li res = 0;
    if (start == finish)
        res = naive(start, lf, rg);
    else
        res = naive(start, lf, (start + 1) * blockLen - 1) + naive(finish, finish * blockLen, rg);
    
    for (int i = start + 1; i < finish; i++)
        res += sum[i];
        
    return res; 
}

inline void solve()
{
    prepare();
    
    forn(q, m)
    {
        int type;
        assert(scanf("%d", &type) == 1);
        
        if (type == 1)
        {
            int lf, rg;
            assert(scanf("%d%d", &lf, &rg) == 2);
            --lf, --rg;
            printf("%I64d\n", Sum(lf, rg));
            
        } else if (type == 2)
        {
            int lf, rg, mod;
            assert(scanf("%d%d%d", &lf, &rg, &mod) == 3);
            --lf, --rg;
            takeMod(lf, rg, mod);
            
        } else if (type == 3)
        {
            int pos, val;
            assert(scanf("%d%d", &pos, &val) == 2);
            --pos;
            assign(pos, val);
            
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
    cerr << "=== TIME: " << clock() << " ===" << endl;
#endif

    return 0;
}