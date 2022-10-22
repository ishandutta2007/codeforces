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

const int MAXN = 5e5 + 5;

pii p[MAXN];

ll ccw(const pii &A, const pii &B, const pii &C) {
  return (ll) A.fi * (B.se - C.se) +
         (ll) B.fi * (C.se - A.se) +
         (ll) C.fi * (A.se - B.se);
}

int ogledna;
bool cmp_a(const int &A, const int &B) {
  return ccw(p[ogledna], p[A], p[B]) < 0;
}
bool cmp_x(const int &A, const int &B) {
  return p[A] < p[B];
}

vector<int> sol, pts;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;
  REP(i, n) {
    int x, y; cin >> x >> y;
    p[i].fi = x;
    p[i].se = y;
    pts.pb(i);
  }
  sort(pts.begin(), pts.end(), cmp_x);

  sol.pb(pts[0]);
  pts.erase(pts.begin());

  ogledna = sol.back();
  sort(pts.begin(), pts.end(), cmp_a);

  string s; cin >> s;

  for(auto c: s) {
    if(c == 'L') {
      reverse(pts.begin(), pts.end());
    }
    sol.pb(pts[0]);
    ogledna = sol.back();
    pts.erase(pts.begin());
    sort(pts.begin(), pts.end(), cmp_a);
  }
  sol.pb(pts[0]);

  for(auto x: sol) {
    cout << x + 1 << " ";
  }
}