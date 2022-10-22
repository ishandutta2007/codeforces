#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back
#define fi first
#define se second

typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
int mul(int x, int y) {return (ll) x * y % mod;}

const int off = 1 << 19, MAXN = 5e5 + 5;

struct {
  vector<int> t;
  void init() {
    t.resize(2 * off);
  }
  void upd(int x, int v) {
    x += off;
    t[x] = v;
    for(x /= 2; x; x /= 2) {
      t[x] = add(t[x * 2], t[x * 2 + 1]);
    }
  }
  int get(int x, int lo, int hi, int a, int b) {
    if(lo >= a && hi <= b) return t[x];
    if(lo >= b || hi <= a) return 0;
    int mi = (lo + hi) >> 1;
    return add(get(x * 2, lo, mi, a, b), get(x * 2 + 1, mi, hi, a, b));
  }
} l, r;

int a[MAXN];

bool cmp(const int &A, const int &B) {
  return a[A] < a[B];
}

int povrh;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;
  REP(i, n) cin >> a[i];
  vector<int> v;
  REP(i, n) v.pb(i);
  sort(v.begin(), v.end(), cmp);

  l.init();
  r.init();

  int sol = 0;
  for(auto i: v) {
    sol = add(sol, mul(a[i], mul(i + 1, n - i)));

    sol = add(sol, mul(a[i], mul(i + 1, l.get(1, 0, off, i + 1, off))));
    sol = add(sol, mul(a[i], mul(n - i, r.get(1, 0, off, 0, i))));

    l.upd(i, n - i);
    r.upd(i, i + 1);
  }

  cout << sol << endl;
}