#include <math.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double pi = acos((double) -1);
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = 4e18;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

void solve();

signed main() {
#ifdef DEBUG
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#endif
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed;
  cout.precision(15);
  solve();
  return 0;
}

struct T {
  vector<pair<int, int>> a, t;
  vector<int> u;
  T(){}
  T(vector<pair<int ,int>> a) : a(a) {
    t.resize(4 * a.size());
    u.assign(4 * a.size(), 0);
    build(0, 0, a.size());
  }
  void build(int v, int l, int r) {
    if(r - l == 1) {
      t[v] = a[l];
      return;
    }
    build(2 * v + 1,l ,l + r >> 1);
    build(2 * v + 2 ,l + r >> 1, r);
    t[v] = max(t[2 * v+  1], t[2 *v +2]);
  }
  void push(int v, int l, int r) {
    if(!u[v]) return;
    if(r - l == 1) {
      t[v].first += u[v];
      u[v] = 0;
      return;
    }
    t[v].first += u[v];
    u[2 * v + 1] += u[v];
    u[2 * v + 2] += u[v];
    u[v] = 0;
  }
  void upd(int v, int l, int r, int vl, int vr ,int d) {
    push(v, l, r);
    if(vl >= r || l >= vr) return;
    if(vl <= l && r <= vr) {
      u[v] += d;
      push(v, l, r);
      return;
    }
    upd(2 * v + 1,l ,l + r >> 1, vl, vr, d);
    upd(2 * v + 2,l + r >> 1, r, vl, vr, d);
    t[v] = max(t[2 * v+  1], t[ 2* v + 2]);
  }
  pair<int, int> get(int v, int l, int r, int vl, int vr) {
    push(v, l, r);
    if(vl >= r || l >= vr) return {-1, -1};
    if(vl <= l && r <= vr) return t[v];
    return max(get(2 * v + 1, l, l + r >> 1, vl, vr), get(2 * v + 2, l + r >> 1, r, vl, vr));
  }
};

const int N =  2e5 + 2;

int par[N];
int d[N];
pair<int, int> seg[N];
vector<pair<int, int>> leaf;
vector<int> g[N];

void dfs(int v, int p = -1) {
  par[v] = p;
  if(p != -1)
    d[v] = d[p] + 1;
  int lm = inf0;
  int rm = -1;
  for(int u : g[v]) {
    if(u == p) continue;
    dfs(u, v);
    lm = min(lm, seg[u].first);
    rm = max(rm, seg[u].second);
  }
  if(rm == -1) {
    seg[v] = {leaf.size(), leaf.size()};
    leaf.push_back({d[v], v});
  } else {
    seg[v] = {lm, rm};
  }
}

bool used[N];

void solve() {
  int n, k; cin >> n >> k;
  for(int i = 1; i < n; i++) {
    int a, b; cin >> a >> b; a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  fill(used, used + N, false);
  d[0] = 1;
  dfs(0);
  T t(leaf);
  int m = leaf.size();
  ll cnt = 0;
  ll ans = -(n / 2) * 1ll * (n - (n / 2));
  ll kek = n;
  while(k--) {
    auto v = t.get(0, 0, m, 0, m);
    cnt++;
    int x = v.second;
    while(true) {
      if(used[x] || x == -1) break;
      t.upd(0, 0, m, seg[x].first, seg[x].second + 1, -1);
      used[x] = true;
      x = par[x];
      kek--;
    }
    if(kek >= (n / 2))
      ans = max(ans, cnt * 1ll * (n - cnt) - (n / 2) * 1ll * (n - (n / 2)));
    else
      ans = max(ans, cnt * 1ll * (n - cnt) - kek * 1ll * (n - kek));
  }
  cout << ans << endl;
}