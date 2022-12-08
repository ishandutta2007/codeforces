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

int gcd(int a, int b) {
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}

struct T {
  vector<int> a, t;

  T() {}

  T(vector<int> a) : a(a) {
    t.resize(4 * a.size());
    build(0, 0, a.size());
  }

  void build(int v, int l, int r) {
    if (r - l == 1) {
      t[v] = a[l];
      return;
    }
    build(2 * v + 1, l, l + r >> 1);
    build(2 * v + 2, l + r >> 1, r);
    t[v] = gcd(t[2 * v + 1], t[2 * v + 2]);
  }

  int get(int v, int l, int r, int vl, int vr) {
    if (l >= vr || vl >= r)
      return 0;
    if (vl <= l && r <= vr)
      return t[v];
    return gcd(get(2 * v + 1, l, l + r >> 1, vl, vr), get(2 * v + 2, l + r >> 1, r, vl, vr));
  }

  int get_hard(int v, int l, int r, int vl, int vr, int g = 0) {
    if (l >= vr || vl >= r) return vl;
    if (vl <= l && r <= vr && gcd(g, t[v]) == g)
      return vl;
    if (r - l == 1)
      return l;
    int a1 = get_hard(2 * v + 2, l + r >> 1, r, vl, vr, g);
    if (a1 == vl)
      return get_hard(2 * v + 1, l, l + r >> 1, vl, vr, g);
    return a1;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  T t(a);
  vector<pair<int, int>> dp(n);
  if (a[0] == 1)
    dp[0] = {1, 0};
  else
    dp[0] = {0, -1};
  cout << dp[0].first << " ";
  for (int i = 1; i < n; i++) {
    int x = dp[i - 1].second;
    int s = i;
    int g = a[i];
    bool fl = false;
    while (true) {
      if (s == x) break;
      int id = t.get_hard(0, 0, n, x, i, g) + 1;
      if (i - s + 1 <= g && g <= i - id + 1) {
        fl = true;
        break;
      }
      g = gcd(g, a[id - 1]);
      s = id - 1;
    }
    if (fl)
      dp[i] = {dp[i - 1].first + 1, i};
    else
      dp[i] = dp[i - 1];
    cout << dp[i].first << " ";
  }
  cout << endl;
}