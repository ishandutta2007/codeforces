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

const int MAXN = 5e5 + 5;

struct uni {
  vector<int> par;
  vector<int> sz;
  void init(int n) {
    par.resize(n + 5);
    sz.resize(n + 5);
    REP(i, n + 5) {
      par[i] = i;
      sz[i] = 1;
    }
  }
  int f(int x) {
    if(par[x] == x) return x;
    return par[x] = f(par[x]);
  }
  void spoji(int x, int y) {
    x = f(x);
    y = f(y);
    if(x == y) return;
    par[x] = y;
    sz[y] += sz[x];
  }
};

vector<int> e[MAXN];

void solve() {
  int n, m, a, b; cin >> n >> m >> a >> b;
  REP(i, n + 1) e[i].clear();
  REP(i, m) {
    int u, v; cin >> u >> v;
    e[u].pb(v);
    e[v].pb(u);
  }

  uni A;
  A.init(n);
  FOR(i, 1, n + 1) for(int j: e[i]) {
    if(i != a && j != a) A.spoji(i, j);
  }
  int sza = 0;
  FOR(i, 1, n + 1) {
    if(A.f(i) == i && A.f(a) != A.f(i) && A.f(b) != A.f(i)) sza += A.sz[A.f(i)];
  }

  uni B;
  B.init(n);
  FOR(i, 1, n + 1) for(int j: e[i]) {
    if(i != b && j != b) B.spoji(i, j);
  }
  int szb = 0;
  FOR(i, 1, n + 1) {
    if(B.f(i) == i && B.f(a) != B.f(i) && B.f(b) != B.f(i)) szb += B.sz[B.f(i)];
  }

  ll sol = (ll) sza * szb;
  cout << sol << endl;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int t; cin >> t;
  while(t --) solve();
}