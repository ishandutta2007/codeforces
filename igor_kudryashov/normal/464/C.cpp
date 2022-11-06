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
inline void clocks() {
    #ifdef SU2_PROJ
        cerr << "=== TIME: " << ld(clock()) / CLOCKS_PER_SEC << " sec ===" << endl;
    #endif
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
inline void makeVariablesUsed() { int a = INF; li b = INF64; ld c = EPS, d = PI; d = a * b + c; }

inline int binPow (int a, int b, int mod)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = (res * 1LL * a) % mod;
        a = (a * 1LL * a) % mod;
        b >>= 1;
    }
    return res;
}

const int mod = 1000 * 1000 * 1000 + 7;
const int N = 100 * 1000 + 13;

int n;
string s[N];
int dig[N];
char buf[N];
int Next[N][10];

inline bool read()
{
    if (scanf("%s", buf) != 1) return false;
    s[0] = string(buf);
    dig[0] = -1;

    assert(scanf("%d", &n) == 1);

    forl(i, n)
    {
        assert(scanf("%s", buf) == 1);
        int len = strlen(buf);
        s[i] = string(buf + 3, buf + len);
        dig[i] = buf[0] - '0';
    }
    n++;

    return true;
}

int dmod[N], dlen[N];

int calcLen (int idx)
{
    int& ans = dlen[idx];
    if (ans != -1) return ans;
    ans = 0;

    forn(i, sz(s[idx]))
    {
        int dig = s[idx][i] - '0';
        if (Next[idx + 1][dig] != -1)
            ans += calcLen(Next[idx + 1][dig]);
        else
            ans++;

        while (ans >= mod - 1) ans -= mod - 1;
    }

    return ans;
}

int calcMod (int idx)
{
    int& ans = dmod[idx];
    if (ans != -1) return ans;
    ans = 0;

    int curlen = 0;

    ford(i, sz(s[idx]))
    {
        int dig = s[idx][i] - '0';
        int Nextlen = 1, Nextmod = dig;
        if (Next[idx + 1][dig] != -1)
        {
            Nextlen = calcLen(Next[idx + 1][dig]);
            Nextmod = calcMod(Next[idx + 1][dig]);
        }

        li curval = binPow(10, curlen, mod) * 1LL * Nextmod;
        if (curval >= mod) curval %= mod;

        //cerr << idx << ' ' << i << ' ' << curlen << ' ' << curval << ' ' << Nextlen << ' ' << Nextmod << endl;
        //cerr << Next[idx + 1][dig] << endl;

        ans += int(curval);
        while (ans >= mod) ans -= mod;

        curlen += Nextlen;
        while (curlen >= mod - 1) curlen -= mod - 1;
    }

    return ans;
}

inline void solve()
{
    memset(Next[n], -1, sizeof(Next[n]));
    ford(i, n)
    {
        forn(j, 10) Next[i][j] = Next[i + 1][j];
        if (dig[i] != -1) Next[i][dig[i]] = i;
    }
    //forn(i, n + 1) { forn(j, 10) cerr << Next[i][j] << ' '; cerr << endl; }
    //forn(i, n) cerr << s[i] << endl;
    memset(dmod, -1, sizeof(dmod));
    memset(dlen, -1, sizeof(dlen));
    cout << calcMod(0) << endl;
}

int main()
{
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

    assert(read());
    solve();
    clocks();

    return 0;
}