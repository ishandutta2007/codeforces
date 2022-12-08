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

const int N = 3e5 + 2;

int par[N], sz[N];

void build() {
  for (int i = 0; i < N; i++) {
    par[i] = i;
    sz[i] = 1;
  }
}

int get_par(int k) {
  if (par[k] == k) return k;
  return par[k] = get_par(par[k]);
}

void merge(int a, int b) {
  a = get_par(a);
  b = get_par(b);
  if (a == b) return;
  if (sz[a] < sz[b]) swap(a, b);
  sz[a] += sz[b];
  par[b] = a;
}

struct Edge {
  int v, u, id;
};

vector<Edge> g[N];
Edge p[N];
int w[N];

void build_dfs(int v, int pr = -1) {
  for (auto[a, b, id] : g[v]) {
    if (b == pr) continue;
    p[b] = Edge{a, b, id};
    build_dfs(b, v);
  }
}

vector<vector<int>> ans;

int get_ans(int v, int pr = -1) {
  int rt = 0;
  bool fl = (pr != -1 && (w[p[v].id] & 1));
  int kek = 0;
  for (auto[a, b, id] : g[v]) {
    if (b == pr) continue;
    p[b] = Edge{a, b, id};
    if(w[id] & 1)
      kek++;
    rt += get_ans(b, v);
  }
  if(fl && (kek == 0))
    return rt;
  else if(fl)
    kek--;
  rt += (kek + 1) / 2;
  return rt;
}

void solve() {
  fill(w, w + N, 0);
  build();
  int n, m;
  cin >> n >> m;
  int cur_i = 0;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (get_par(a) == get_par(b)) continue;
    g[a].push_back(Edge{a, b, cur_i});
    g[b].push_back(Edge{b, a, cur_i});
    cur_i++;
    merge(a, b);
  }
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    build_dfs(a);
    ans.push_back(vector<int>());
    while (b != a) {
      ans.back().push_back(b);
      auto[x1, x2, id] = p[b];
      w[id]++;
      b = x1;
    }
    ans.back().push_back(a);
    reverse(all(ans.back()));
  }
  int an = get_ans(0);
  if(an) {
    cout << "NO\n";
    cout << an << endl;
  } else {
    cout << "YES\n";
    for(auto v : ans) {
      cout << v.size() << endl;
      for(int u : v)
        cout << u + 1 << " ";
      cout << endl;
    }
  }
}