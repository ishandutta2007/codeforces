//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
//#pragma GCC target("avx2")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
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

//#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double PI = acos((double)-1);
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
const ll mod = 1e9 + 7;
// const ll mod = 998244353;

void solve();
void scan();

signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed;
  cout.precision(15);
  solve();
  return 0;
}

struct T {
  vector<pair<int, int>> t;
  vector<int> a, u;
  T() {}
  T(vector<int> a) : a(a) {
    t.resize(4 * a.size());
    u.assign(4 * a.size(), -inf0);
    build(0, 0, a.size());
  }
  void build(int v, int l, int r) {
    if(r - l == 1) {
      t[v] = mp(a[l], l);
      return;
    }
    build(2 * v + 1, l, l + r >> 1);
    build(2 * v + 2, l + r >> 1, r);
    t[v] = max(t[2 * v + 1], t[2 * v + 2]);
  }
  void push(int v, int l, int r) {
    if(u[v] == -inf0) return;
    if(r - l == 1) {
      t[v].first = u[v];
      u[v] = -inf0;
      return;
    }
    u[2 * v + 1] = u[2 * v + 2] = t[v].first = u[v];
    u[v] = -inf0;
  }
  void upd(int v, int l, int r, int vl, int vr, int x) {
    push(v, l, r);
    if(vl >= r || l >= vr) return;
    if(vl <= l && r <= vr) {
      u[v] = x;
      push(v, l, r);
      return;
    }
    upd(2 * v + 1, l, l + r >> 1, vl, vr, x);
    upd(2 * v + 2, l + r >> 1, r, vl, vr, x);
    t[v] = max(t[2 * v + 1], t[2 * v + 2]);
  }
  pair<int, int> get (int v, int l, int r, int vl, int vr) {
    push(v, l, r);
    if(vl >= r || l >= vr) return mp(-inf0, -inf0);
    if(vl <= l && r <= vr) return t[v];
    return max(get(2 * v + 1, l, l + r >> 1, vl, vr), get(2 * v + 2, l + r >> 1, r, vl, vr));
  }
};

T t;
vector<string> cur;
set<int> kek;
int n;

string get() {
  auto u = t.get(0, 0, n, 0, n);
  return cur[u.second];
}

void solve() {
  cin >> n;
  vector<int> a(n + 1);
  cur.resize(n + 1);
  a[0] = 1; cur[0] = "blue";
  int fl = 1;
  for(int i = 1; i <= n; i++) {
    cin >> cur[i];
    a[i] = fl;
    if(cur[i] == "lock") {
      a[i] = (fl ? -1 : -2);
      fl = 0;
      kek.insert(i);
    }
    else if(cur[i] == "unlock") {
      a[i] = (fl ? -1 : -2);
      fl = 1;
      kek.insert(i);
    }
  }
  n++;
  t = T(a);
  cout << get() << endl;
  int q; cin >> q;
  while(q--) {
    int i; string s;
    cin >> i >> s;
    if(cur[i] == "lock" || cur[i] == "unlock")
      kek.erase(kek.find(i));
    cur[i] = s;
    int was = 0;
    auto u = t.get(0, 0, n, i, i + 1);
    if(u.first == -1 || u.first == 1)
      was = 1;
    else
      was = 0;
    if(s != "lock" && s != "unlock") {
      auto it = kek.upper_bound(i);
      int r = n;
      if(it != kek.end())
        r = *it;
      t.upd(0, 0, n, i, r, was);
      if(r != n)
        t.upd(0, 0, n, r, r + 1, (was ? -1 : -2));
    } else {
      t.upd(0, 0, n, i, i + 1, (was ? -1 : -2));
      was = (s == "lock" ? 0 : 1);
      auto it = kek.upper_bound(i);
      int r = n;
      if(it != kek.end())
        r = *it;
      if(r != i + 1)
        t.upd(0, 0, n, i + 1, r, was);
      if(r != n)
        t.upd(0, 0, n, r, r + 1, (was ? -1 : -2));
      kek.insert(i);
    }
    cout << get() << endl;
  }
  return;
}