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

struct T {
  vector<int> t;
  T(){}
  T(int n) {
    t.assign(4 * n, -inf0);
  }
  int get(int v, int l, int r, int vl, int vr) {
    if(l >= vr || vl >= r)
      return -inf0;
    if(vl <= l && r <= vr)
      return t[v];
    return max(get(2 * v + 1, l, l + r >> 1, vl, vr), get(2 * v + 2, l + r >> 1, r, vl, vr));
  }
  void upd(int v, int l, int r, int i, int x) {
    if(l > i || i >= r)
      return;
    if(r - l == 1) {
      t[v] = x;
      return;
    }
    upd(2 * v + 1, l, l + r >> 1, i, x);
    upd(2 * v + 2, l + r >> 1, r, i, x);
    t[v] = max(t[2 * v + 1], t[2 * v + 2]);
  }
};

int fun(int x) {
  if(x > 0) return 1;
  if(x == 0) return 0;
  return -1;
}

void solve() {
  int t; cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
      cin >> a[i];
    vector<pair<ll, int>> pref(n + 1);
    pref[0] = {0, 0};
    for (int i = 1; i <= n; i++)
      pref[i] = {pref[i - 1].first + a[i - 1], i};
    vector<int> ord(n);
    sort(all(pref));
    int m = pref.size();
    T t = T(m);
    vector<int> p(m, 0);
    for (int i = 0; i < m; i++) {
      if (pref[i].second) {
        ord[pref[i].second - 1] = i;
      } else {
        t.upd(0, 0, m, i, 1);
      }
    }
    for(int i = 1; i < m; i++) {
      if(pref[i - 1].first == pref[i].first)
        p[i] = p[i - 1];
      else
        p[i] = i;
    }
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
      int prv = 0;
      if (i) prv = dp[i - 1];
      dp[i] = prv + fun(a[i]);
      int kek = t.get(0, 0, m, 0, p[ord[i]]);
      dp[i] = max(dp[i], kek + i);
//      cout << i << " " << dp[i] << " " << kek << " " << ord[i] << endl;
      if(i + 1 == n || a[i + 1] != a[i]) {
        for(int j = i; j >= 0; j--) {
          if(a[j] != a[i]) break;
          t.upd(0, 0, m, ord[j], dp[j] - j);
        }
      }
    }
    cout << dp.back() << endl;
  }
}