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

vector<int> g[N];
int used[N];
int ans[N];

bool dfs(int v) {
  used[v] = 1;
  for(int u : g[v]) {
    if(used[u] == 1)
      return false;
    if(!used[u]) {
      if(!dfs(u))
        return false;
    }
    if(u < v)
      ans[v] = max(ans[v], ans[u]);
    else
      ans[v] = max(ans[v], ans[u] + 1);
  }
  used[v] = 2;
  return true;
}

void solve() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
      g[i].clear();
      int k; cin >> k;
      while(k--) {
        int x; cin >> x; x--;
        g[i].push_back(x);
      }
    }
    fill(used, used + n, 0);
    fill(ans, ans + n, 0);
    bool fl = true;
    for(int i = 0; i < n; i++) {
      if(!used[i]) {
        if(!dfs(i)) {
          fl = false;
          break;
        }
      }
    }
    if(!fl) cout << -1 << endl;
    else {
      int x = 0;
      for(int i = 0; i < n; i++)
        x = max(x, ans[i]);
      cout << x + 1 << endl;
    }
  }
}