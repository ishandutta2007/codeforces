#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define nfor(i, n) for (int i = int(n) - 1; i >= 0; i--)
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
typedef pair<int, int> pti;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

template<typename A, typename B> inline ostream& operator<< (ostream& out, const pair<A, B>& p) { return out << "(" << p.x << ", " << p.y << ")"; }
template<typename T> inline ostream& operator<< (ostream& out, const vector<T>& a) { out << "["; forn(i, sz(a)) { if (i) out << ','; out << ' ' << a[i]; } return out << " ]"; }
template<typename T> inline ostream& operator<< (ostream& out, const set<T>& a) { return out << vector<T>(all(a)); }
template<typename X, typename Y> inline ostream& operator<< (ostream& out, const map<X, Y>& a) { return out << vector<pair<X, Y>>(all(a)); }
template<typename T> inline ostream& operator<< (ostream& out, pair<T*, int> a) { return out << vector<T>(a.x, a.x + a.y); }

inline ld gett() { return ld(clock()) / CLOCKS_PER_SEC; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

#ifdef SU1
#define LOG
#endif

const int N = 200 * 1000 + 3;

int n, m;
vector <pti> g[N];

bool read() {
  if (scanf("%d%d", &n ,&m) != 2) return false;
  forn(i, m) {
    int a, b;
    assert(scanf("%d%d", &a, &b) == 2);
    a--, b--;
    g[a].pb(mp(b, 0));
    g[b].pb(mp(a, 1));
  }
  return true;
}

pti d[N][2];

const int mod = 998244353;

const int LOGN = 21;

int z[N][LOGN];

void solve2() {
  queue<pti> q;
  q.push(mp(0, 0));
  forn(i, n) forn(j, LOGN) z[i][j] = INF;
  z[0][0] = 0;
  while (!q.empty()) {
    int v = q.front().first, cnt = q.front().second;
    q.pop();
    forn(i, sz(g[v])) {
      int to = g[v][i].first, dir = g[v][i].second;
      int w = 1;
      if (dir != cnt % 2) w = (1 << cnt) + 1;
      //cerr << v << ' ' << cnt << ' ' << to << ' ' << dir << ' ' << w << endl;
      int ncnt = dir == cnt % 2 ? cnt : (cnt + 1);
      if (ncnt < LOGN && z[to][ncnt] > z[v][cnt] + w) {
        z[to][ncnt] = z[v][cnt] + w;
        q.push(mp(to, ncnt));
      }
    }
  }
  /*
  forn(i, n) {
    forn(j, LOGN) cerr << z[i][j] << ' ';
    cerr << endl;
  }
  */
  int ans = INF;
  forn(i, LOGN) ans = min(ans, z[n - 1][i]);
  cout << ans << endl;
}

void solve() {
  queue<pti> q;
  q.push(mp(0, 0));
  forn(i, n) forn(j, 2) d[i][j] = mp(INF, INF);
  d[0][0] = mp(0, 0);
  while (!q.empty()) {
    int v = q.front().first, par = q.front().second;
    q.pop();
    pti dv = d[v][par];
    forn(i, sz(g[v])) {
      int to = g[v][i].first, dir = g[v][i].second;
      pti dto = dv;
      int npar = dir == par ? par : (par ^ 1);
      dto.second++;
      if (dir != par) dto.first++;
      if (d[to][npar] > dto) {
        d[to][npar] = dto;
        q.push(mp(to, npar));
      }
    }
  }
  pti best = min(d[n - 1][0], d[n - 1][1]);
  if (best.first > 20) {
    int res = 0;
    int p = 1;
    forn(i, best.first) {
      res = (res + p) % mod;
      p = (p * 2) % mod;
    }
    res = (res + best.second) % mod;
    cout << res << endl;
    return;
  }
  cerr << "solve2" << endl;
  solve2();
}

int main() {
#ifdef SU1
  assert(freopen("input.txt", "rt", stdin));
  //assert(freopen("output.txt", "wt", stdout));
#endif

  cout << setprecision(10) << fixed;
  cerr << setprecision(5) << fixed;

  if (read()) {
    ld stime = gett();
    solve();
    cerr << "Time: " << gett() - stime << endl;
    //break;
  }
  return 0;
}