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

const int N = 3e5 + 2;
vector<int> g[N];
int d[N], max_d[N];

void dfs(int v, int p = -1) {
  max_d[v] = d[v];
  for(int u : g[v]) {
    if(u == p) continue;
    d[u] = d[v] + 1;
    dfs(u, v);
    max_d[v] = max(max_d[v], max_d[u]);
  }
}

int f[N]; // f[i] = max diameter among vertexes v with max_d[v] > i

void build(int v, int p = -1) {
  int a1 = d[v], a2 = d[v];
  for(int u : g[v]) {
    if(u == p) continue;
    build(u, v);
    if(max_d[u] > a2) {
      a1 = a2;
      a2 = max_d[u];
    } else if(max_d[u] > a1) {
      a1 = max_d[u];
    }
  }
  if(a1)
    f[a1 - 1] = max(f[a1 - 1], a1 + a2 - 2 * d[v]);
}

bool check(int m, int x) {
  return (max_d[0] <= m) || (x + (f[m] + 1) / 2 <= m);
}

void solve() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    for(int i = 0; i < n; i++)
      g[i].clear();
    fill(f, f + n + 1, 0);
    for(int i = 1; i < n; i++) {
      int a, b; cin >> a >> b; a--; b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    d[0] = 0;
    dfs(0);
    build(0);
    for(int i = n - 1; i >= 0; i--)
      f[i] = max(f[i], f[i + 1]);
    for(int x = 1; x <= n; x++) {
      int l = 0, r = n;
      while(r - l > 1) {
        int m = l + r >> 1;
        if(check(m, x))
          r = m;
        else
          l = m;
      }
      cout << r << " ";
    }
    cout << endl;
  }
}