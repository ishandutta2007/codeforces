#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back
#define fi first
#define se second
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define TRACE(x) cerr << #x << "  " << x << endl
template<typename T1, typename T2>inline void minaj(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void maxaj(T1 &x, T2 y) { x = (x < y ? y: x);}

typedef pair<int, int> pii;

const int OFF = 1 << 19;

int t[2 * OFF];
int p[2 * OFF];
int off = 2;

void prop(int x) {
  if (p[x]) {
    t[x] += p[x];
    if (x < off) {
      p[x*2] += p[x];
      p[x*2+1] += p[x];
    }
    p[x] = 0;
  }
}

int get(int x, int lo, int hi, int a, int b) {
  if (lo >= b || hi <= a) return 0;
  prop(x);
  if (lo >= a && hi <= b) return t[x];
  int mi = (lo + hi) >> 1;
  return get(x*2, lo, mi, a, b) + get(x*2+1, mi, hi, a, b);
}

void upd(int x, int lo, int hi, int a, int b, int v) {

  if (lo >= a && hi <= b) {
    p[x] += v;
    prop(x);
    return;
  }
  prop(x);
  if (lo >= b || hi <= a) return;

  int mi = (lo + hi) >> 1;
  upd(x*2, lo, mi, a, b, v);
  upd(x*2+1, mi, hi, a, b, v);
  t[x] = t[x*2] + t[x*2+1];
}

const int MAXN = 3e5 + 5;

vector<int> e1[MAXN];
vector<int> e2[MAXN];

int cookie ;

int lo[MAXN];
int hi[MAXN];

void dfs(int u, int v) {
  lo[v] = cookie++;

  for (auto w: e2[v]) {
    if (w == u) continue;
    dfs(v, w);

  }
  hi[v] = cookie;
}

int sol;
int tmp;

void stavi(int v, stack<pair<pii, int>> &s) {
  int bio = get(1, 0, off, lo[v], lo[v] + 1) - 1;
  if (bio != -1) {
    upd(1, 0, off, lo[bio], hi[bio], -bio - 1);
    s.push({{lo[bio], hi[bio]}, -bio - 1});
    tmp --;
  }

  if (get(1, 0, off, lo[v], hi[v]) > 0) return;

  upd(1, 0, off, lo[v], hi[v], v + 1);
  s.push({{lo[v], hi[v]}, v + 1});

  tmp ++;
}

void rijesi(int u, int v) {
  stack<pair<pii, int>> promjene;
  int tmporg = tmp;

  stavi(v, promjene);

  sol = max(sol, tmp);
  for (int w: e1[v]) {
    if (w != u) rijesi(v, w);
  }

  tmp = tmporg;
  while (promjene.size()) {
    auto pp = promjene.top();
    promjene.pop();
    upd(1, 0, off, pp.fi.fi, pp.fi.se, -pp.se);
  }
}

void solve() {
  int n; cin >> n;
  REP(i, n) e1[i].clear();
  REP(i, n) e2[i].clear();

  off = 2;
  while (off <= n) off *= 2;

  REP(i, 2 * off) t[i] = p[i] = 0;

  REP(i, n-1) {
    int v; cin >> v;
    e1[--v].pb(i + 1);
    e1[i + 1].pb(v);
  }

  REP(i, n-1) {
    int v; cin >> v;
    e2[--v].pb(i + 1);
    e2[i + 1].pb(v);
  }
  cookie = 0;
  dfs(0, 0);
  tmp = 0;
  sol = 0;
  rijesi(0, 0);
  cout << sol << endl;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tt; cin >> tt;
  while(tt--) solve();
}