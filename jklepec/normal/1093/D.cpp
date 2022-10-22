#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 3e5 + 5, MAXK = 109, mod = 998244353;

int add(int x, int y) {
  x += y;
  if(x >= mod) return x - mod;
  return x;
}
int mul(int x, int y) {
  return (ll) x * y % mod;
}
int sub(int x, int y) {
  x -= y;
  if(x < 0) return x + mod;
  return x;
}

bool bio[MAXN];
bool fail[MAXN];

int test_case;

int c[MAXN];
vector<int> e[MAXN];

pii dfs(int v, int tmp) {
  if(c[v] != 0 && c[v] != tmp) {
    fail[test_case] = true;
    return pii(0, 0);
  }

  if(c[v] != 0) {
    return pii(0, 0);
  }

  c[v] = tmp;

  pii ret = {0, 0};
  if(tmp == 1) {
    ret.first ++;
  }
  else {
    ret.second ++;
  }

  for(auto w: e[v]) {
    pii rek = dfs(w, 3 - tmp);
    ret.first += rek.first;
    ret.second += rek.second;
  }

  return ret;
}

int pot[MAXN];

void solve() {
  int n, m; cin >> n >> m;

  REP(i, n) e[i].clear();

  REP(i, m) {
    int x, y; cin >> x >> y;
    x --; y --;
    e[x].pb(y);
    e[y].pb(x);
  }

  REP(i, n) c[i] = 0;

  int sol = 1;

  REP(i, n) {
    if(!c[i]) {
      pii tmp = dfs(i, 1);
      sol = mul(sol, add(pot[tmp.first], pot[tmp.second]));
    }
  }

  if(fail[test_case]) {
    cout << 0 << '\n';
  }
  else {
    cout << sol << '\n';
  }
}

int main() {

  ios_base::sync_with_stdio(false); cin.tie(0);

  pot[0] = 1;
  FOR(i, 1, MAXN) pot[i] = mul(pot[i - 1], 2);

  int t; cin >> t;
  while(t --) {
    solve();
    test_case ++;
  }
}