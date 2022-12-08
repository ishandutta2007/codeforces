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

const int N = 2e5 + 2;
int p[N], sz[N], f[N], f_tmp[N];

void build(int n) {
  for(int i = 0; i < n; i++) {
    p[i] = i;
    sz[i] = 1;
    f[i] = -1;
    f_tmp[i] = -1;
  }
}

int get_par(int k) {
  if(p[k] == k) return k;
  return p[k] = get_par(p[k]);
}

void merge(int a, int b) {
  a = get_par(a); b = get_par(b);
  if(a == b) return;
  if(sz[a] < sz[b]) swap(a, b);
  sz[a] += sz[b];
  p[b] = a;
}

struct Edge {
  int v, u;
  int tp = -1;
};

vector<Edge> g[N];
int ans[N];
bool used[N];

int dfs(int v) {
  used[v] = true;
  int s = ans[v];
//  cout << v << " " << ans[v] << endl;
  for(auto e : g[v]) {
    int x, p;
    if(e.v == v) {
      p = e.u;
      x = e.tp ^ ans[v];
    } else {
      p = e.v;
      x = e.tp != ans[v];
    }
    if(used[p]) {
      if(ans[p] != x) {
        return -1;
      }
      continue;
    }
    ans[p] = x;
    int y = dfs(p);
    if(y == -1) return -1;
    s += y;
  }
  return s;
}

void solve() {
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    fill(g, g + n, vector<Edge>());
    fill(used, used + n, false);
    fill(ans, ans + n, -1);
    build(n);
    for(int i = 0; i < m; i++) {
      int a, b; cin >> a >> b; a--; b--;
      string s; cin >> s;
      if(s == "imposter") {
        g[a].push_back({a, b, 1});
        g[b].push_back({a, b, 1});
      } else {
        g[a].push_back({a, b, 0});
        g[b].push_back({a, b, 0});
      }
      merge(a, b);
    }
    for(int i = 0; i < n; i++) {
      if(!used[get_par(i)]) {
        ans[get_par(i)] = 0;
        int x = dfs(get_par(i));
        f_tmp[get_par(i)] = x;
      }
    }
    fill(used, used + n, false);
    fill(ans, ans + n, -1);
    for(int i = 0; i < n; i++) {
      if(!used[get_par(i)]) {
        ans[get_par(i)] = 1;
        int x = dfs(get_par(i));
        f[get_par(i)] = x;
      }
    }
    int ans = 0;
    bool fl = true;
    fill(used, used + n, false);
    for(int i = 0; i < n; i++) {
      if(!used[get_par(i)]) {
        int x = max(f[get_par(i)], f_tmp[get_par(i)]);
        if(x == -1) {
          fl = false;
          break;
        }
        used[get_par(i)] = true;
        ans += x;
      }
    }
    if(!fl)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
}