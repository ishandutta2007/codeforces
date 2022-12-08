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

struct T {
  vector<int> t, u;
  T(){}
  T(int n) {
    t.assign(4 * n, 0);
    u.assign(4 * n, 0);
  }
  void push(int v, int l, int r) {
    if(!u[v]) return;
    if(r - l == 1) {
      t[v] += u[v];
      u[v] = 0;
      return;
    }
    t[v] += u[v];
    u[2 * v + 1] += u[v];
    u[2 * v + 2] += u[v];
    u[v] = 0;
  }
  void add(int v, int l, int r, int vl, int vr, int d) {
    push(v, l, r);
    if(vl >= r || l >= vr)
      return;
    if(vl <= l && r <= vr) {
      u[v] += d;
      push(v, l, r);
      return;
    }
    add(2 * v + 1, l, l + r >> 1, vl, vr, d);
    add(2 * v + 2, l + r >> 1, r, vl, vr, d);
    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
  }
  int get(int v, int l, int r, int vl, int vr) {
    push(v, l, r);
    if(vl >= r || l >= vr)
      return inf0;
    if(vl <= l && r <= vr)
      return t[v];
    return min(get(2 * v + 1, l, l + r >> 1, vl, vr), get(2 * v + 2, l + r >> 1, r, vl, vr));
  }
};

struct TT {
  vector<int> t;
  TT(){}
  TT(int n ){
    t.resize(4 * n);
  }
  void upd(int v, int l, int r, int i) {
    if(i >= r || i < l) return;
    if(r - l == 1){
      t[v] = 1;
      return;
    }
    upd(2 * v + 1, l, l + r >> 1, i);
    upd(2 * v + 2, l + r >> 1, r, i);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
  }
  int get(int v, int l, int r, int vl, int vr) {
    if(vl >= r || l >= vr)
      return 0;
    if(vl <= l && r <= vr)
      return t[v];
    return get(2 * v + 1, l, l + r >> 1, vl, vr) + get(2 * v + 2, l + r >> 1, r, vl, vr);
  }
};

ll calc_inv(vector<pair<int, int>> a) {
  ll ans = 0;
  TT t(a.size());
  for(int i = 0; i < a.size(); i++) {
    auto [x, j] = a[i];
    if(i && x != a[i - 1].first) {
      for(int h = i - 1; h >= 0; h--) {
        if(a[h].first != a[i - 1].first) break;
        t.upd(0, 0, a.size(), a[h].second);
      }
    }
    ans += t.get(0, 0, a.size(), j + 1, a.size());
  }
  return ans;
}

void solve() {
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> a(n);
    vector<int> b(m);
    for(int i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = i;
    }
    for(int i = 0; i < m; i++)
      cin >> b[i];
    sort(all(a));
    sort(all(b));
    T t(n + 1);
    for(auto [x, i] : a) {
      t.add(0, 0, n + 1, i + 1, n + 1, 1);
    }
    int l = 0, r = 0;
    ll ans = 0;
    ll prev = -1;
    while(true) {
      if(r == m) break;
      if(r && b[r] == b[r - 1]) {
        ans += prev;
        r++;
        continue;
      }
      while(l < n && a[l].first < b[r])  {
        t.add(0, 0, n + 1, a[l].second + 1, n + 1, -1);
        t.add(0, 0, n + 1, 0, a[l].second, 1);
        l++;
      }
      while(l < n && a[l].first == b[r]) {
        t.add(0, 0, n + 1, a[l].second + 1, n + 1, -1);
        l++;
      }
      prev = t.get(0, 0, n + 1, 0, n + 1);
      ans += prev;
      for(int i = l - 1; i>= 0; i--) {
        if(a[i].first != b[r]) break;
        t.add(0, 0, n + 1, 0, a[i].second, 1);
      }
      r++;
    }
//    cout << calc_inv(a) << endl;
    cout << ans + calc_inv(a) << endl;
  }
}