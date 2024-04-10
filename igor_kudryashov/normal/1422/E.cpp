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

string s;

bool read() {
  if (!(cin >> s)) return false;
  return true;
}

const int N = 100 * 1000 + 3;

string start[N], finish[N], all[N];
char first_diff[N];
int len[N];

void update(int i) {
  while (sz(all[i]) > 10) all[i].erase(sz(all[i]) - 1);
  while (sz(start[i]) > 5) start[i].erase(sz(start[i]) - 1);
  if (sz(finish[i]) > 2) finish[i] = finish[i].substr(sz(finish[i]) - 2);
}

void solve() {
  nfor(i, sz(s)) {
    if (i == sz(s) - 1 || s[i] != s[i + 1]) {
      first_diff[i] = start[i + 1].empty() ? 0 : start[i + 1][0] == s[i] ? first_diff[i + 1] : start[i + 1][0];
      len[i] = len[i + 1] + 1;
      string cur = "";
      cur.pb(s[i]);
      all[i] = cur + all[i + 1];
      start[i] = cur + start[i + 1];
      finish[i] = cur + finish[i + 1];
      update(i);
      continue;
    }
    string nstart = start[i + 2].substr(0, 2);
    string cur = s.substr(i, 2);
    if (nstart < cur || (nstart == cur && first_diff[i + 2] < cur[0])) {
      first_diff[i] = first_diff[i + 2];
      len[i] = len[i + 2];
      all[i] = all[i + 2];
      start[i] = start[i + 2];
      finish[i] = finish[i + 2];
      continue;
    }
    if (sz(nstart) > 0 && nstart[0] != cur[0]) first_diff[i] = nstart[0]; else
    if (sz(nstart) > 1 && nstart[1] != cur[0]) first_diff[i] = nstart[1]; else
    first_diff[i] = first_diff[i + 2];
    len[i] = len[i + 2] + 2;
    all[i] = cur + all[i + 2];
    start[i] = cur + start[i + 2];
    finish[i] = cur + finish[i + 2];
    update(i);
  }
  //forn(i, sz(s)) cerr << first_diff[i] << endl;
  forn(i, sz(s)) {
    printf("%d ", len[i]);
    if (len[i] <= 10) {
      printf("%s\n", all[i].c_str());
    } else {
      assert(sz(start[i]) == 5 && sz(finish[i]) == 2);
      printf("%s...%s\n", start[i].c_str(), finish[i].c_str());
    }
  }
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