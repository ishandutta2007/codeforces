#include <cmath>
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

const int N = 2e3 + 2;

int p[N], sz[N];

void build() {
  for(int i = 0; i < N; i++) {
    p[i] = i;
    sz[i] = 1;
  }
}

int get_par(int k) {
  if(p[k] == k) return k;
  return p[k] = get_par(p[k]);
}

void merge(int a, int b) {
  a = get_par(a);
  b = get_par(b);
  if(a == b) return;
  if(sz[a] < sz[b])
    swap(a, b);
  p[b] = a;
  sz[a] += sz[b];
}

vector<pair<int, ll>> g[N];
vector<pair<pair<int, int>, ll>> ed;
vector<pair<ll, pair<int, int>>> a;
vector<ll> f;

int dfs(int v, int p = -1) {
  int s = 1;
  for(auto u : g[v]) {
    if(u.first == p) continue;
    int st = dfs(u.first, v);
    ed.push_back(mp(mp(v, u.first), (f[v] - u.second) / st));
    s += st;
  }
  return s;
}

void solve() {
  build();
  int n; cin >> n;
  f.resize(n);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= i; j++) {
      ll x; cin >> x;
      if(j == i)
        f[i] = x;
      else
        a.push_back(mp(x, mp(j, i)));
    }
  }
  sort(rall(a));
  for(auto v : a) {
    ll w = v.first;
    int x = v.second.first;
    int y = v.second.second;
    if(get_par(x) == get_par(y)) continue;
    g[x].push_back(mp(y, w));
    g[y].push_back(mp(x, w));
    merge(x, y);
  }
  dfs(0);
  for(auto v : ed) {
    cout << v.first.first + 1 << " " << v.first.second + 1 << " " << v.second << endl;
  }
}