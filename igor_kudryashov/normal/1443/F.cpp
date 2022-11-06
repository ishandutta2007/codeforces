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

const int mod = 998244353;

const int N = 200 * 1000 + 3;

int n, k;
int a[N], b[N];
map<pti, int> Next;
set<pti> s;
map<int, int> pos;

bool read() {
  if (scanf("%d%d", &n, &k) !=2) return false;
  Next.clear();
  s.clear();
  pos.clear();
  forn(i, n) {
    assert(scanf("%d", &a[i]) == 1);
    a[i]--;
    pos[a[i]] = i;
  }
  forn(i, k) {
    assert(scanf("%d", &b[i]) == 1);
    b[i]--;
    b[i] = pos[b[i]];
  }
  return true;
}

int solve(int lf, int rg) {
  if (lf > rg) return 0;
  if (!Next.count(mp(lf, rg))) {
    return 1;
  }
  int mid = Next[mp(lf, rg)];
  assert(lf <= mid && mid <= rg);
  if (mid == lf) return solve(lf + 1, rg);
  if (mid == rg) return solve(lf, rg - 1);
  return (solve(lf, mid - 1) * 2LL * solve(mid + 1, rg)) % mod;
}

void solve() {
  s.insert(mp(0, n - 1));
  nfor(i, k) {
    auto iter = s.lower_bound(mp(b[i], INF));
    iter--;
    Next[*iter] = b[i];
    pti p1(iter->first, b[i] - 1);
    pti p2(b[i] + 1, iter->second);
    s.erase(iter);
    s.insert(p1);
    s.insert(p2);
  }
  /*
  for (auto item : Next) {
    cerr << item.first.x + 1 << ' ' << item.first.y + 1 << ' ' << item.second + 1 << endl;
  }
  */
  cout << solve(0, n -1) << endl;
}

int main() {
#ifdef SU1
  assert(freopen("input.txt", "rt", stdin));
  //assert(freopen("output.txt", "wt", stdout));
#endif

  cout << setprecision(10) << fixed;
  cerr << setprecision(5) << fixed;

  int testCount;
  cin >> testCount;
  forn(test, testCount) {
    read();
    solve();
    //break;
  }
  return 0;
}