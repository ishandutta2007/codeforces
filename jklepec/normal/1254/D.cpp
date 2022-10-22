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

typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 998244353 ;
int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
int mul(int x, int y) {return (ll) x * y % mod;}
int exp(int x, int pot) {
  if(pot == 1) return x;
  if(pot == 0) return 1;
  int pola = exp(x, pot / 2);
  pola = mul(pola, pola);
  if(pot % 2) return mul(pola, x);
  return pola;
}

const int MAXN = 2e5 + 5, off = 1 << 18, B = 200;

struct tour1 {
  vector<int> t;
  void init() {
    t.resize(2 * off);
  }
  void upd(int x, int lo, int hi, int a, int b, int d) {
    if(lo >= a && hi <= b) {
      t[x] = add(t[x], d);
      return;
    }
    if(lo >= b || hi <= a) {
      return;
    }
    int mi = (lo + hi) >> 1;
    upd(x * 2, lo, mi, a, b, d);
    upd(x * 2 + 1, mi, hi, a, b, d);
  }
  int get(int x) {
    x+=off;
    int ret = 0;
    for(; x; x/=2) {
      ret = add(ret, t[x]);
    }
    return ret;
  }
};


int nn;
vector<int> veliki, e[MAXN];

int cookie;
int par[MAXN];
int sz[MAXN];
int lo[MAXN], hi[MAXN];
void dfs(int u, int v) {
  lo[v] = cookie++;
  sz[v] = 1;
  par[v] = u;
  for(auto w: e[v]) {
    if(w != u) {
      dfs(v, w);
      sz[v] += sz[w];
    }
  }
  hi[v] = cookie;
}

int fix[MAXN];
vector<int> ne[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, q; cin >> n >> q;
  nn = exp(n, mod-2);
  REP(i, n - 1) {
    int u, v; cin >> u >> v;
    u --; v --;
    e[u].pb(v);
    e[v].pb(u);
  }

  dfs(0, 0);
  REP(i, n) {
    REP(j, e[i].size()) {
      if(e[i][j] != par[i]) ne[i].pb(e[i][j]);
    }
    e[i] = ne[i];
  }
  tour1 T1;
  T1.init();
  REP(i, n) {
    if(e[i].size() > B) {
      veliki.pb(i);
    }
  }

  REP(i, q) {
    int type; cin >> type;
    if(type == 1) {
      int v, d; cin >> v >> d;
      v --;

      T1.upd(1, 0, off, 0, lo[v], mul(sz[v], d));
      T1.upd(1, 0, off, hi[v], n + 5, mul(sz[v], d));
      T1.upd(1, 0, off, lo[v], lo[v] + 1, mul(n, d));
      if(e[v].size() <= B) {
        for(auto w: e[v]) {
          T1.upd(1, 0, off, lo[w], hi[w], mul(sub(n, sz[w]), d));
        }
      }
      else {
        fix[v] = add(fix[v], d);
      }
    }
    else {
      int v; cin >> v; v--;
      int sol = 0;

      sol = mul(nn, T1.get(lo[v]));
      for(auto x: veliki) {
        if(lo[x] < lo[v] && hi[x] > lo[v]) {
          int loo = 0, hii = e[x].size() - 1;
          while(loo < hii) {
            int mi = (loo + hii + 1) >> 1;
            if(lo[e[x][mi]] > lo[v]) {
              hii = mi - 1;
            }
            else {
              loo = mi;
            }
          }
          sol = add(sol, mul(nn, mul(sub(n, sz[e[x][loo]]), fix[x])));
        }
      }
      cout << sol << endl;
    }
  }
}