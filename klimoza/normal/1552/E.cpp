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

const double PI = acos((double) -1);
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = 4e18;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

void solve();
void scan();
signed main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
  cout << fixed; cout.precision(15);
  solve();
  return 0;
}

void solve() {
  int n, k; cin >> n >> k;
  int m = n * k;
  vector<int> a(m);
  vector<vector<int>> c(n, vector<int>());
  vector<int> p(n);
  for(int i = 0; i < n ;i++)
    p[i] = i;
  vector<bool> used(n, false);
  for(int i = 0; i < m; i++) {
    cin >> a[i]; a[i]--;
    c[a[i]].push_back(i);
  }
  vector<pair<int, int>> ans(n);
  int step = (n + k - 2) / (k - 1);
  int tot = 0;
  for (int i = 1;; i++) {
    if(tot == n) break;
    int diff = min(n - tot, step);
    tot += diff;
    sort(all(p), [&](int x, int y) { return c[x][i] < c[y][i]; });
    for(int j : p) {
      if(!diff) break;
      if(used[j]) continue;
      used[j] = true;
      ans[j] = mp(c[j][i - 1], c[j][i]);
      diff--;
    }
  }
  for(auto u : ans)
    cout << u.first + 1 << " " << u.second + 1 << endl;
}