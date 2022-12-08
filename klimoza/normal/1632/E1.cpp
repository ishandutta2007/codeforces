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

//#define endl '\n'

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

const int N = 3e3 + 2;
vector<int> g[N];
int d[N], max_d[N];
int par[N];

void dfs(int v, int p = -1) {
  par[v] = p;
  max_d[v] = d[v];
  for(int u : g[v]) {
    if(u == p) continue;
    d[u] = d[v] + 1;
    dfs(u, v);
    max_d[v] = max(max_d[v], max_d[u]);
  }
}

bool check(int v, int m, int x, int p = -1, int r = inf0) { // m --  <= , x -- 
  if(r < 0) return false;
  if(max_d[v] - max(d[v] - x, 0) <= m)
    return true;
//  if(m == 2 && x == 2)
//    cout << "kek\n";
  bool fl = false;
  for(int i = 0; i < g[v].size(); i++) {
    if(g[v].size() == 1) {
      if(d[v] <= m)
        return check(g[v][0], m, x, v, r - 1);
      else
        return check(g[v][0], m, x, v, min(r - 1, m - x - 1));
    }
    else {
      int f = 0;
      if(i == 0) {
        f = max_d[g[v][1]];
      } else {
        f = max_d[g[v][0]];
      }
      if(f <= m)
        fl = fl || check(g[v][i], m, x, v, r - 1);
      else if(f - max(d[v] - x, 0) > m)
        continue;
      else
        fl = fl || check(g[v][i], m, x, v, min(r - 1, m - (f - max(d[v] - x, 0)) - 1));
    }
  }
  return fl;
}

void solve() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    for(int i = 0; i < n; i++)
      g[i].clear();
    for(int i = 1; i < n ;i++) {
      int a, b; cin >> a >> b; a--; b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    d[0] = 0;
    dfs(0);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < g[i].size(); j++) {
        if (g[i][j] == par[i]) {
          if(j + 1 != g[i].size()) {
            swap(g[i].back(), g[i][j]);
            break;
          }
        }
      }
      if(i)
        g[i].pop_back();
      sort(all(g[i]), [&](int x, int y) { return max_d[x] < max_d[y]; });
      reverse(all(g[i]));
    }
    for(int x = 1; x <= n; x++) {
      int l = 0, r = n;
//      cout << x << " kek " << endl;
      while(r - l > 1) {
        int m = l + r >> 1;
        if(check(0, m, x))
          r = m;
        else
          l = m;
      }
      cout << r << " ";
    }
    cout << endl;
  }
}