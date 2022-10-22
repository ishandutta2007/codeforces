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

const int mod = 1e9 + 7;
int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
int mul(int x, int y) {return (ll) x * y % mod;}

const int MAXN = 1e5 + 5, off = 1 << 17, inf = 1e9;

bool bio[MAXN];

struct tour {
  vector<pii> t;
  void init() {
    t.resize(2 * off);
  }
  pii get(int x, int lo, int hi, int a, int b) {
    if(lo >= a && hi <= b) {
      return t[x];
    }
    if(lo >= b || hi <= a) {
      return {inf, 0};
    }
    int mi = (lo + hi) >> 1;
    return min(get(x * 2, lo, mi, a, b), get(x * 2 + 1, mi, hi, a, b));
  }
  void upd(int x, int v) {
    x += off;
    t[x].fi += v;
    for(x /= 2; x; x/= 2) {
      t[x] = min(t[x * 2], t[x * 2 + 1]);
    }
  }
} t;

vector<int> e[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int comp = 0;

  int n, m; cin >> n >> m;
  REP(i, m) {
    int u, v; cin >> u >> v;
    u --; v --;
    e[u].pb(v);
    e[v].pb(u);
  }
  t.init();

  REP(i, n) {
    t.t[i + off].se = i;
  }
  for(int x = off - 1; x > 0; --x) t.t[x] = min(t.t[x * 2], t.t[x * 2 + 1]);

  REP(i, n) {
    if(!bio[i]) {
      comp ++;
      queue<int> q;
      q.push(i);
      bio[i] = true;
      t.upd(i, inf);
      while(q.size()) {
        int x = q.front();
        q.pop();

        for(auto y: e[x]) {
          t.upd(y, 1);
        }
        pii G = t.get(1, 0, off, 0, n);
        while(G.fi == 0) {
          t.upd(G.se, inf);
          bio[G.se] = true;
          q.push(G.se);
          G = t.get(1, 0, off, 0, n);
        }
        for(auto y: e[x]) {
          t.upd(y, -1);
        }
      }
    }
  }

  cout << comp - 1 << endl;
}