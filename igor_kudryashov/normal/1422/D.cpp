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

const int N = 100 * 1000 + 3;

int n, m;
pti start, finish;
vector<pti> p;
vector<int> xs, ys;
vector<pti> ysOnx[N];
vector<pti> xsOny[N];

bool read() {
  if (scanf("%d%d", &n, &m) != 2) return false;
  assert(scanf("%d%d", &start.x, &start.y) == 2);
  p.pb(start);
  xs.pb(start.x);
  ys.pb(start.y);
  assert(scanf("%d%d", &finish.x, &finish.y) == 2);
  forn(i, m) {
    int x, y;
    assert(scanf("%d%d", &x, &y) == 2);
    xs.pb(x);
    ys.pb(y);
    p.pb(mp(x, y));
  }
  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());
  sort(all(ys));
  ys.erase(unique(all(ys)), ys.end());
  sort(all(p));
  p.erase(unique(all(p)), p.end());
  return true;
}

li d[N];
map<int, int> xindex, yindex;

void solve() {
  forn(i, sz(xs)) xindex[xs[i]] = i;
  forn(i, sz(ys)) yindex[ys[i]] = i;
  queue<int> q;
  forn(i, sz(p)) {
    ysOnx[xindex[p[i].x]].pb(mp(yindex[p[i].y], i));
    xsOny[yindex[p[i].y]].pb(mp(xindex[p[i].x], i));
    if (p[i] == start) {
      d[i] = 0;
      q.push(i);
    } else {
      d[i] = INF64;
    }
  }
  forn(i, sz(xs)) sort(all(ysOnx[i]));
  forn(i, sz(ys)) sort(all(xsOny[i]));
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    int curxindex = xindex[p[v].x], curyindex = yindex[p[v].y];
    for (int dx = -1; dx <= 1; dx++) {
      int nxindex = curxindex + dx;
      if (nxindex < 0 || nxindex >= sz(xs)) continue;
      int w = abs(xs[curxindex] - xs[nxindex]);
      int ysOnxIndex = int(lower_bound(all(ysOnx[nxindex]), mp(curyindex, -1)) - ysOnx[nxindex].begin());
      for (int dy = -1; dy <= 1; dy++) {
        int nysOnxIndex = ysOnxIndex + dy;
        if (nysOnxIndex < 0 || nysOnxIndex >= sz(ysOnx[nxindex])) continue;
        int nv = ysOnx[nxindex][nysOnxIndex].second;
        if (d[nv] > d[v] + w) {
          d[nv] = d[v] + w;
          q.push(nv);
        }
      }
    }
    for (int dy = -1; dy <= 1; dy++) {
      int nyindex = curyindex + dy;
      if (nyindex < 0 || nyindex >= sz(ys)) continue;
      int w = abs(ys[curyindex] - ys[nyindex]);
      int xsOnyIndex = int(lower_bound(all(xsOny[nyindex]), mp(curxindex, -1)) - xsOny[nyindex].begin());
      for (int dx = -1; dx <= 1; dx++) {
        int nxsOnyIndex = xsOnyIndex + dx;
        if (nxsOnyIndex < 0 || nxsOnyIndex >= sz(xsOny[nyindex])) continue;
        int nv = xsOny[nyindex][nxsOnyIndex].second;
        if (d[nv] > d[v] + w) {
          d[nv] = d[v] + w;
          q.push(nv);
        }
      }
    }
  }
  li ans = abs(start.x - finish.x) + abs(start.y - finish.y);
  forn(i, sz(p)) {
    li cur = d[i] + li(abs(p[i].x - finish.x)) + abs(p[i].y - finish.y);
    ans = min(ans, cur);
  }
  cout << ans << endl;
}

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
    cerr << "Time: " << gett() - stime << endl;
    //break;
  }
  return 0;
}