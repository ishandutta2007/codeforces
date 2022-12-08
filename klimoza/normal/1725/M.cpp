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
typedef double ld;

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
  freopen(PATH1, "r", stdin);
  freopen(PATH2, "w", stdout);
#endif
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed;
  cout.precision(15);
  solve();
  return 0;
}

const int N = 1e5 + 2;

vector<pair<int, ll>> g[N];
vector<pair<int, ll>> rev[N];

ll d[N][2];

void djikstra() {
  for(int i = 0; i < N; i++) {
    d[i][0] = d[i][1] = inf;
  }
  d[0][0]  = 0;
  set<pair<ll, pair<int, int>>> qu;
  qu.insert({0, {0, 0}});
  while(!qu.empty()) {
    auto u = *qu.begin();
    qu.erase(qu.begin());
//    cout << u.first << " " << u.second.first << " " << u.second.second << endl;
    for(auto[v, w] : rev[u.second.first]){
      if(d[v][1] > u.first + w) {
        qu.erase({d[v][1], {v, 1}});
        d[v][1] = u.first + w;
        qu.insert({d[v][1], {v, 1}});
      }
    }
    if(u.second.second == 0) {
      for(auto [v, w] : g[u.second.first]) {
        if(d[v][0] > u.first + w) {
          qu.erase({d[v][0], {v, 0}});
          d[v][0] = u.first + w;
          qu.insert({d[v][0], {v, 0}});
        }
      }
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  while(m--) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--; v--;
    g[u].push_back({v, w});
    rev[v].push_back({u, w});
  }
  djikstra();
  for(int i = 1; i < n; i++) {
    ll mn = min(d[i][0], d[i][1]);
    if(mn == inf)
      cout << -1 << " ";
    else
      cout << mn << " ";
  }
}