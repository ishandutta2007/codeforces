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

const int N = 30 * 1000 + 3;

int n, a[N];

bool read() {
  if (scanf("%d", &n) != 1) return false;
  forn(i, n) assert(scanf("%d", &a[i]) == 1);
  return true;
}

int b[N];

bool can(int lf) {
  forn(i, lf - 1) if (a[i] < a[i + 1]) return false;
  int maxv = lf == 0 ? 0 : a[lf - 1];
  for (int i = lf; i < n; i++) {
    int can_dec = std::min(a[i], maxv);
    if (i > lf) can_dec = std::min(can_dec, a[i] - b[i - 1]);
    if (can_dec < 0) return false;
    b[i] = a[i] - can_dec;
    maxv = min(maxv, can_dec);
  }
  /*
  std::cerr << lf << endl;
  forn(i, lf) cerr << a[i] << ' ';
  for(int i = lf; i < n; i++) cerr << b[i] << ' ';
  cerr << endl;
  */
  return true;
}

void solve() {
  forn(lf, n) {
    if (can(lf)) {
      puts("YES");
      return;
    }
  }
  puts("NO");
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