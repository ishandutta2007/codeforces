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

signed main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
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
  vector<pair<int, int>> t;
  vector<pair<int, int>> u;

  T() {}

  T(int n) {
    t.resize(4 * n, mp(1, -1));
    u.resize(4 * n, mp(inf0, inf0));
  }

  void push(int v, int l, int r) {
    if (u[v].first == inf0)
      return;
    if (r - l == 1) {
      t[v] = min(t[v], u[v]);
      return;
    }
    t[v] = min(t[v], u[v]);
    u[2 * v + 1] = min(u[2 * v + 1], u[v]);
    u[2 * v + 2] = min(u[2 * v + 2], u[v]);
    u[v] = mp(inf0, inf0);
  }

  void upd(int v, int l, int r, int vl, int vr, pair<int, int> d) {
    push(v, l, r);
    if (l >= vr || vl >= r)
      return;
    if (vl <= l && r <= vr) {
      u[v] = d;
      push(v, l, r);
      return;
    }
    upd(2 * v + 1, l, l + r >> 1, vl, vr, d);
    upd(2 * v + 2, l + r >> 1, r, vl, vr, d);
    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
  }

  pair<int, int> get(int v, int l, int r, int vl, int vr) {
    push(v, l, r);
    if (l >= vr || vl >= r)
      return mp(inf0, inf0);
    if (vl <= l && r <= vr)
      return t[v];
    return min(get(2 * v + 1, l, l + r >> 1, vl, vr), get(2 * v + 2, l + r >> 1, r, vl, vr));
  }
};

const int N = 6e5 + 2;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> kek(n);
  vector<int> ed;
  for (int i = 0; i < m; i++) {
    int j, l, r;
    cin >> j >> l >> r;
    j--;
    ed.push_back(l);
    ed.push_back(r);
    kek[j].push_back(mp(l, r));
  }
  sort(all(ed));
  ed.erase(unique(all(ed)), ed.end());
  map<int, int> f;
  for (int i = 0; i < ed.size(); i++)
    f[ed[i]] = i;
  for (auto &v : kek) {
    for (auto &u : v) {
      u.first = f[u.first];
      u.second = f[u.second];
    }
  }
  T t(N);
  vector<pair<int, int>> dp(n, mp(inf0, -1));
  pair<int, int> ans = mp(n, -1);
  for (int i = 0; i < n; i++) {
    dp[i] = mp(i, -1);
    for (auto u : kek[i]) {
      pair<int, int> x = t.get(0, 0, N, u.first, u.second + 1);
      x.first += i - 1;
      dp[i] = min(dp[i], x);
    }
    for (auto u : kek[i])
      t.upd(0, 0, N, u.first, u.second + 1, mp(dp[i].first - i, i));
    pair<int, int> x = dp[i];
    x.first += n - i - 1;
    x.second = i;
    ans = min(ans, x);
  }
  set<int> good;
  while (ans.second != -1) {
    good.insert(ans.second);
    ans.second = dp[ans.second].second;
  }
  vector<int> q;
  for (int i = 0; i < n; i++)
    if (good.find(i) == good.end())
      q.push_back(i);
  cout << q.size() << endl;
  for (int i : q)
    cout << i + 1 << " ";
}