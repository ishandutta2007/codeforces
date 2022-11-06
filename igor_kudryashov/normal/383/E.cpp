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

const int N = 24;

int n;
int cnt1[N], cnt2[N][N], cnt3[N][N][N];
int a[N][N][10];
int d[(1 << N) + 3], cnt[(1 << N) + 3];

inline bool read()
{
    if (scanf("%d", &n) != 1) return false;
    
    char buf[5];
    
    forn(i, n)
    {
        assert(scanf("%s", buf) == 1);
        string s = string(buf);
        sort(all(s));
        
        vector <int> v;
        forn(j, sz(s)) v.pb(s[j] - 'a');
        v.erase(unique(all(v)), v.end());
        
        if (sz(v) == 1) cnt1[v[0]]++;
        else if (sz(v) == 2) cnt2[v[0]][v[1]]++;
        else cnt3[v[0]][v[1]][v[2]]++;
    }
    
    return true;
}

inline void prepare()
{
    forn(i, N) fore(j, i + 1, N - 1) fore(k, j + 1, N - 1)
    {
        assert(cnt3[i][j][k] <= 6);
        a[i][j][cnt3[i][j][k]] |= (1 << k);
    }
    
    forl(mask, (1 << N) - 1) cnt[mask] = cnt[mask & (mask - 1)] + 1;
}

inline void solve()
{
    prepare();
    
    int ans = sqr(n);
    
    forl(mask, (1 << N) - 1)
    {
        int f = 0;
        forn(i, N) if (mask & (1 << i)) { f = i; break; }
        
        d[mask] = d[mask ^ (1 << f)];
        d[mask] += cnt1[f];
        
        fore(s, f + 1, N - 1)
        {
            if ((mask & (1 << s)) == 0) continue;
            d[mask] += cnt2[f][s];
            
            forl(res, 6)
                d[mask] += cnt[a[f][s][res] & mask] * res;
        }
        
        //if (d[mask] != 0)
        //  cerr << mask << ' ' << d[mask] << endl;
        
        ans ^= sqr(n - d[mask]);
    }
    
    cout << ans << endl;    
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