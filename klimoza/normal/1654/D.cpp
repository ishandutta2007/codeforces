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
//const ll mod = 1e9 + 7;
const ll mod = 998244353;

void solve();

signed main() {
#ifdef DEBUG
  freopen("/Users/klimoza/CLionProjects/Test/test.in", "r", stdin);
  freopen("/Users/klimoza/CLionProjects/Test/test.out", "w", stdout);
#endif
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed;
  cout.precision(15);
  solve();
  return 0;
}

ll add(ll a, ll b) {
  a += b;
  if(a >= mod)
    a -= mod;
  return a;
}

ll mul(ll a, ll b) {
  return a * b % mod;
}

ll bp(ll a, ll k) {
  ll res = 1;
  while(k) {
    if(k & 1)
      res = mul(res, a);
    a = mul(a, a);
    k >>= 1;
  }
  return res;
}

ll gcd(ll a, ll b) {
  while(b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

struct Edge {
  int v, u;
  ll x, y;
};

const int N = 2e5 + 2;
vector<Edge> g[N];
ll a[N];

map<int, int> base;
void dfs(int v, map<int, int> &cur, int p = -1) {
  for(auto e : g[v]) {
    if(e.u == p) continue;
    vector<pair<int, int>> kek1, kek2;
    for(int i = 2; i * 1ll * i <= e.x; i++) {
      if(e.x % i == 0) {
        kek1.push_back({i, 0});
        while(e.x % i == 0) {
          e.x /= i;
          kek1.back().second++;
        }
      }
    }
    if(e.x)
      kek1.push_back({e.x, 1});
    for(int i = 2; i * 1ll * i <= e.y; i++) {
      if(e.y % i == 0) {
        kek2.push_back({i, 0});
        while(e.y % i == 0) {
          e.y /= i;
          kek2.back().second++;
        }
      }
    }
    if(e.x)
      kek2.push_back({e.y, 1});
    for(auto [a, b] : kek2)
      cur[a] += b;
    for (auto [a, b] : kek1) {
      if(cur[a] < b) {
        base[a] += b - cur[a];
        cur[a] = 0;
      } else {
        cur[a] -= b;
      }
    }
    dfs(e.u, cur, e.v);
    for(auto [a, b] : kek1)
      cur[a] += b;
    for (auto [a, b] : kek2)
      cur[a] -= b;
  }
}

void dfs2(int v, int p = -1) {
  for(auto e : g[v]) {
//    cout << v << " " << e.u << " " << a[e.u] << endl;
    if(e.u == p) continue;
    a[e.u] = mul(mul(a[v], e.y), bp(e.x, mod - 2));
//    cout << v << " " << e.u << " " << a[e.u] << endl;
    dfs2(e.u, v);
  }
}

void solve() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    for(int i = 0; i < n; i++)
      g[i].clear();
    base.clear();
    fill(a, a + n, 0);
    for(int i = 0; i < n - 1; i++) {
      int a, b, x, y; cin >> a >> b >> x >> y;
      a--; b--;
      g[a].push_back(Edge{a, b, x, y});
      g[b].push_back(Edge{b, a, y, x});
    }
    dfs(0, base);
    a[0] = 1;
    for(auto [x, y] : base)
      a[0] = mul(a[0], bp(x, y));
    dfs2(0);
    ll s = 0;
//    for(int i = 0; i < n; i++)
//      cout << a[i] << " ";
//    cout << endl;
    for(int i = 0; i < n ;i++)
      s = add(s, a[i]);
    cout << s << endl;
  }
}