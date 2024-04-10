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

const int N = 501;

vector<int> g[N];

void solve() {
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    vector<pair<pair<int ,int>, ll>> ed(m);
    for(int i = 0; i <m; i++) {
      int v, u;
      ll w;
      cin >> v >> u >> w;
      v--; u--;
      g[v].push_back(u);
      g[u].push_back(v);
      ed[i] = mp(mp(v, u), w);
    }
    vector<vector<int>> d(n, vector<int>(n, inf0));
    for(int i = 0; i < n; i++) {
      d[i][i] = 0;
      queue<int> q = {};
      q.push(i);
      while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int u : g[v]) {
          if(d[i][u] > d[i][v] + 1) {
            d[i][u] = d[i][v] + 1;
            q.push(u);
          }
        }
      }
    }
    ll ans = inf;
    for(auto e : ed) {
      ans = min(ans, (d[e.first.first][0] + d[e.first.second][n - 1] + 1) * e.second);
      ans = min(ans, (d[e.first.second][0] + d[e.first.first][n - 1] + 1) * e.second);
      for(int v = 0; v < n; v++) {
        ll res = min(d[v][e.first.first], d[v][e.first.second]) + 2 + d[v][0] + d[v][n - 1];
        ans = min(ans, res * e.second);
      }
    }
    for(int i = 0; i < n; i++)
      g[i].clear();
    cout << ans << endl;
  }
}