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

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

map<string, set<string> > a;

inline bool read() {
    int n;
    cin >> n;
    char buf[100];
    string hs("http://");
    forn(i, n) {
        scanf("%s", buf);
        string s(buf);
        s = s.substr(sz(hs));
        int idx = s.find('/');
        if (idx != string::npos) {
            a[s.substr(0, idx)].insert(s.substr(idx));
        } else {
            a[s].insert("");
        }
    }
	return true;
}

map<set<string>, vector<string> > b;

inline void solve() {
    for (auto& item : a) {
        b[item.sc].pb(item.ft);
    }
    int cnt = 0;
    for (const auto& item : b) {
        if (sz(item.sc) > 1) cnt++;
    }
    cout << cnt << endl;
    for (const auto& item : b) {
        if (sz(item.sc) == 1) {
            continue;
        }
        for (const auto& s : item.sc) {
            printf("http://");
            printf(s.c_str());
            putchar(' ');
        }
        puts("");
    }
}

int main() {
#ifdef SU2_PROJ
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif

	cout << setprecision(10) << fixed;
	cerr << setprecision(5) << fixed;

    assert(read());
    solve();
	
#ifdef SU2_PROJ
	cerr << "=== TOTAL TIME: " << clock() / CLOCKS_PER_SEC << " ===" << endl;
#endif

	return 0;
}