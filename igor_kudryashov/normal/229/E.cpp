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
typedef pair<int, int> pti;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 1000 + 13;

int n, m;
vector <int> g[N];
vector <int> a;
int k[N];
bool havelast[N];
int needLast, cntLast, last;
ld d[N][N];
ld C[N][N];

inline bool read()
{
    if (scanf("%d%d", &m, &n) != 2)
        return false;
        
    forn(i, n)
    {
        int cnt;
        assert(scanf("%d", &cnt) == 1);
        g[i].resize(cnt);
        
        forn(j, cnt) assert(scanf("%d", &g[i][j]) == 1), a.pb(g[i][j]);
    }
    
    return true;
}

inline void solve()
{
    C[0][0] = 1;
    forl(i, N - 1)
        forn(j, i + 1)
            C[i][j] = (j == 0 ? 0 : C[i - 1][j - 1]) + C[i - 1][j];
            
    sort(all(a));
    reverse(all(a));
    
    last = a[m - 1];
    int cur = m - 1;
    while (cur >= 0 && a[cur] == last) needLast++, cur--;
    forn(i, sz(a)) if (a[i] == last) cntLast++;
    
    forn(i, n)
        forn(j, sz(g[i]))
            if (g[i][j] > last) k[i]++;
            else if (g[i][j] == last) havelast[i] = true;
            
    d[0][0] = 1.0;
    
    //cerr << last << ' ' << needLast << ' ' << cntLast << endl;
    
    forn(i, n)
        forn(taken, needLast + 1)
        {
            const ld& dv = d[i][taken];
            
            //cerr << i << ' ' << taken << ' ' << dv << endl;
            
            d[i + 1][taken] += dv / C[sz(g[i])][k[i]];
            if (havelast[i]) d[i + 1][taken + 1] += dv / C[sz(g[i])][k[i] + 1];
        }
    
    cout << setprecision(15) << fixed;
    cout << d[n][needLast] / C[cntLast][needLast] << endl;  
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