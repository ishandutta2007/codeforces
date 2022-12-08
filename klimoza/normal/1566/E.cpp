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
int tp[N];
vector<int> g[N];
vector<int> kek;
int leaf = 0;

void dfs(int v, int p = -1) {
  int cnt = 0;
  for(int u : g[v]) {
    if(u != p) {
      dfs(u, v);
      if (tp[u] == 1)
        cnt++;
    }
  }
  if(p == -1) {
    leaf = cnt;
    return;
  }
  if(cnt) {
    kek.push_back(cnt);
    tp[v] = 0;
  } else {
    tp[v] = 1;
  }
}

void solve() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    fill(tp, tp + n, -1);
    for(int i = 0; i < n; i++)
      g[i].clear();
    for(int i = 1; i < n; i++) {
      int a, b; cin >> a >> b; a--; b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    leaf = 0;
    kek.clear();
    dfs(0);
    int ans = max(1, leaf);
    for(int v : kek) {
      ans += v - 1;
    }
    cout << ans << endl;
  }
}