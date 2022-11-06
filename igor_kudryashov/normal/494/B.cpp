#undef NDEBUG
#ifdef SU1
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
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
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
template<typename X, typename Y> inline ostream& operator<< (ostream& out, const pair <X, Y>& p) { return out << '(' << p.x << ", " << p.y << ')'; }
template<typename X> inline ostream& operator<< (ostream& out, const vector<X>& p) { forn(i, sz(p)) { if (i != 0) out << ' '; out << p[i]; } return out; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

inline vector<int> calcz(string s)
{
    int n = sz(s);
    int l = 0, r = -1;
    vector<int> z(n, 0);

    forl(i, n - 1)
    {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) l = i, r = i + z[i];
    }

    return z;
}

const int N = 100 * 1000 + 13;
const int mod = 1000 * 1000 * 1000 + 7;

char buf[N];
string s, t;
bool good[N];
int d[N], sum[N], sum2[N];

inline bool read()
{
    if (scanf("%s", buf) != 1) return false;
    s = string(buf);
    assert(scanf("%s", buf) == 1);
    t = string(buf);
    return true;
}

inline int add (int a, int b)
{
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

inline void solve()
{
    string cur = t + "#" + s;
    vector<int> z = calcz(cur);
    
    fore(i, sz(t) + 1, sz(cur) - 1)
        if (z[i] == sz(t))
            good[i - sz(t) - 1] = true;
            
    deque<int> q;
    d[0] = sum[0] = sum2[0] = 1;
            
    forn(i, sz(s))
    {
        if (good[i]) q.pb(i);
        
        int last = -1;
        
        while (!q.empty() && i >= q.front() + sz(t) - 1)
        {
            last = q.front();
            q.pop_front();
        }
        
        if (last != -1)
        {
            d[i + 1] = add(d[i + 1], sum2[last]);
            q.push_front(last);
        }
            
        sum[i + 1] = add(sum[i], d[i + 1]);
        sum2[i + 1] = add(sum2[i], sum[i + 1]);
    }
    
    /*forn(i, sz(s)) cerr << good[i] << ' '; cerr << endl;
    forn(i, sz(s) + 1) cerr << d[i] << ' '; cerr << endl;
    forn(i, sz(s) + 1) cerr << sum[i] << ' '; cerr << endl;
    forn(i, sz(s) + 1) cerr << sum2[i] << ' '; cerr << endl;*/
    
    int ans = sum[sz(s)] - 1;
    if (ans < 0) ans += mod;
    
    printf("%d\n", ans);
}

int main()
{
#ifdef SU1
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif

    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    assert(read());
    solve();
    
#ifdef SU1
    cerr << "=== TIME: " << clock() << " ===" << endl;
#endif

    return 0;
}