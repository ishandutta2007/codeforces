#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
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
 
int m, d;
string a, b;
 
inline bool read() {
    if (!(cin >> m >> d)) return false;
    assert(cin >> a >> b);
    return true;
}
 
const int mod = 1000 * 1000 * 1000 + 7;
 
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline void inc(int& a, int b) { a = add(a, b); }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline void dec(int& a, int b) { a = sub(a, b); }
 
const int N = 2020;
 
int z[N][N][2];
 
int solve(string s) {
    int n = sz(s);
    forn(i, n + 1) forn(j, m) forn(k, 2) z[i][j][k] = 0;
    z[0][0][1] = 1;
    forn(i, n)
        forn(j, m)
            forn(k, 2)
                for (int p = 0; p <= (k ? int(s[i] - '0') : 9); p++) {
                    if ((i & 1) && p != d) continue;
                    if (!(i & 1) && p == d) continue;
                    if (!i && !p) continue;
                    int ni = i + 1;
                    int nj = (j * 10 + p) % m;
                    int nk = k && (p == int(s[i] - '0'));
                    inc(z[ni][nj][nk], z[i][j][k]);
                }
    int ans = 0;
    forn(k, 2) inc(ans, z[n][0][k]);
    return ans;
}
 
bool good(string s) {
    int rm = 0;
    forn(i, sz(s)) {
        int p = int(s[i] - '0');
        if ((i & 1) && p != d) return false;
        if (!(i & 1) && p == d) return false;
        rm = (rm * 10 + p) % m;
    }
    return !rm;
}
 
inline void solve() {
    int ans = 0;
    inc(ans, solve(b));
    dec(ans, solve(a));
    inc(ans, good(a));
    cout << ans << endl;
}
 
inline ld gett() { return ld(clock()) / CLOCKS_PER_SEC; }
 
int main() {
#ifdef SU1
    assert(freopen("input.txt", "rt", stdin));
    //assert(freopen("output.txt", "wt", stdout));
#endif
   
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
 
    while (read()) {
        ld stime = gett();
        solve();
        cerr << gett() - stime << endl;
    }
   
    return 0;
}