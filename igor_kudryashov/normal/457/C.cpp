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

const int N = 100 * 1000 + 13;

int n;
vector<int> a[N];
int totalCnt, totalSum;
vector<int> byOrd[N];

inline bool read()
{
    if (scanf("%d", &n) != 1) return false;

    forn(i, n)
    {
        int cand, value;
        assert(scanf("%d%d", &cand, &value) == 2);
        a[cand].pb(value);
        if (cand != 0)
            totalSum += value;
    }

    return true;
}

inline void solve()
{
    totalCnt = n;

    forl(i, N - 1)
    {
        sort(all(a[i]));
        reverse(all(a[i]));
        forn(j, sz(a[i])) byOrd[j + 1].pb(a[i][j]);
    }

    //cerr << "IN" << endl;

    multiset<int> q;

    int answer = totalSum;

    forl(maxCnt, N - 1)
    {
        //cerr << "m = " << maxCnt << endl;
        forn(i, sz(byOrd[maxCnt]))
        {
            totalSum -= byOrd[maxCnt][i];
            totalCnt--;
            q.insert(byOrd[maxCnt][i]);
        }

        //cerr << "to = " << totalCnt << ' ' << sz(q) << endl;

        while (!q.empty() && totalCnt <= maxCnt)
        {
            totalCnt++;
            totalSum += *q.begin();
            q.erase(q.begin());
        }

        if (totalCnt > maxCnt)
            answer = min(answer, totalSum);
        //cerr << "m = " << maxCnt << endl;
    }

    cout << answer << endl;
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