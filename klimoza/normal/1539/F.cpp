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
const ll inf = inf0 * 1ll * inf0;
const ll mod = 1e9 + 7;
// const ll mod = 998244353;

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

struct T{
  vector<int> a, tmax, tmin, u;
  T(){}
  T(int n) {
    a.resize(4 * n);
    u.resize(4 * n);
    tmax.resize(4 * n);
    tmin.resize(4 * n);
  }
  void push(int v, int l, int r) {
    if(!u[v])
      return;
    if(r - l == 1) {
      tmax[v] += u[v];
      tmin[v] += u[v];
      u[v] = 0;
      return;
    }
    tmax[v] += u[v];
    tmin[v] += u[v];
    u[2 * v + 1] += u[v];
    u[2 * v + 2] += u[v];
    u[v] = 0;
  }
  void upd(int v, int l, int r, int vl, int vr, int x) {
    push(v, l, r);
    if(vl >= r || l >= vr)
      return;
    if(vl <= l && r <= vr) {
      u[v] = x;
      push(v, l, r);
      return;
    }
    upd(2 * v + 1, l, l + r >> 1, vl, vr, x);
    upd(2 * v + 2, l + r >> 1, r, vl, vr, x);
    tmax[v] = max(tmax[2 * v + 1], tmax[2 * v + 2]);
    tmin[v] = min(tmin[2 * v + 1], tmin[2 * v + 2]);
  }
  int get_max(int v, int l, int r, int vl, int vr) {
    push(v, l, r);
    if(vl >= r || l >= vr)
      return -inf0;
    if(vl <= l && r <= vr)
      return tmax[v];
    return max(get_max(2 * v + 1, l, l + r >> 1, vl, vr), get_max(2 * v + 2, l + r >> 1, r, vl, vr));
  }
  int get_min(int v, int l, int r, int vl, int vr) {
    push(v, l, r);
    if(vl >= r || l >= vr)
      return inf0;
    if(vl <= l && r <= vr)
      return tmin[v];
    return min(get_min(2 * v + 1, l, l + r >> 1, vl, vr), get_min(2 * v + 2, l + r >> 1, r, vl, vr));
  }
};

const int N = 2e5 + 2;
vector<int> id[N];
vector<int> cur;

int n;
T tpref, tsuff;

void upd(int i, int x) {
  for(int j : id[i]) {
    tpref.upd(0, 0, n, j, n, x - cur[j]);
    tsuff.upd(0, 0, n, 0, j + 1, x - cur[j]);
    cur[j] = x;
  }
}

int get_max(int i) {
  int l = tpref.get_max(0, 0, n, i, i + 1) - min(0, tpref.get_min(0, 0, n, 0, i + 1));
  if(i != n - 1) {
    int r = tsuff.get_max(0, 0, n, i + 1, i + 2) - min(0, tsuff.get_min(0, 0, n, i + 1, n));
    return l + r;
  }
  return l;
}

int get_min(int i) {
  int l = tpref.get_min(0, 0, n, i, i + 1) - max(0, tpref.get_max(0, 0, n, 0, i + 1));
  if(i != n - 1) {
    int r = tsuff.get_min(0, 0, n, i + 1, i + 2) - max(0, tsuff.get_max(0, 0, n, i + 1, n));
    return l + r;
  }
  return l;
}

void solve() {
  cin >> n;
  cur.resize(n);
  tpref = T(n);
  tsuff = T(n);
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    id[a[i]].push_back(i);
  }
  for(int i = 0; i < N; i++)
    upd(i, 1);
  vector<int> ans(n);
  for(int i = 1; i <= n; i++) {
    upd(i, 1);
    for(int j : id[i])
      ans[j] = max(ans[j], (get_max(j)) / 2);
    upd(i, -1);
    for(int j : id[i])
      ans[j] = max(ans[j], (-get_min(j) - 1) / 2);
  }
  for(int i : ans)
    cout << i << " ";
  cout << endl;
}