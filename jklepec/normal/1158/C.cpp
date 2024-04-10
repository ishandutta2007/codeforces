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

const int OFF = 1 << 19;

vector<int> e[2 * OFF];

void put_edge(int x, int lo, int hi, int a, int b, int y) {
  if(lo >= a && hi <= b) {
    e[y].pb(x);
    return;
  }
  if(lo >= b || hi <= a) {
    return;
  }

  int mi = (lo + hi) >> 1;
  put_edge(x*2, lo, mi, a, b, y);
  put_edge(x*2 + 1, mi, hi, a, b, y);
}

vector<int> v;
bool bio[2 * OFF];
int ind[2 * OFF];

void topoloski(int x) {
  if(bio[x]) {
    return;
  }
  bio[x] = true;
  for(auto y: e[x]) {
    topoloski(y);
  }
  v.pb(x);
}

void solve() {
  int n; cin >> n;
  int off = 2;
  v.clear();

  while(off < n) off *= 2;
  REP(i, 2 * off) e[i].clear();

  FOR(x, 1, off) {
    e[x].pb(x * 2);
    e[x].pb(x * 2 + 1);
  }

  REP(i, n) {
    int x; cin >> x; --x;
    if(x == -2) continue;
    if(x != n) {
      e[x + off].pb(i + off);
    }
    if(i + 1 != x) put_edge(1, 0, off, i + 1, x, i + off);
  }

  REP(i, 2 * off) {
    bio[i] = false;
  }

  topoloski(1);
  REP(i, 2 * off - 1) {
    ind[v[i]] = i;
  }

  FOR(x, 1, 2 * off) for(auto y: e[x]) {
    if(ind[x] < ind[y]) {
      cout << "-1\n";
      return;
    }
  }

  vector<int> perm(n, 0);
  int cnt = 1;
  for(auto x: v) {
    if(x >= off && x - off < n) perm[x - off] = cnt ++;
  }

  for(auto x: perm) cout << x << " ";
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int t; cin >> t;
  while(t --) {
    solve();
  }
}