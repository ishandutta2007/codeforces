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

const int N = 3e5 + 2;

struct T {
  vector<ll> t, u;
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
    u[2 * v + 1] += u[v];
    u[2 * v + 2] += u[v];
    t[v] += u[v];
    u[v] = 0;
  }
  void upd(int v, int l, int r, int vl, int vr, ll d) {
    push(v, l, r);
    if(l >= vr || vl >= r)
      return;
    if(vl <= l && r <= vr) {
      u[v] += d;
      push(v, l, r);
      return;
    }
    upd(2 * v + 1, l, l + r >> 1, vl, vr, d);
    upd(2 * v + 2, l + r >> 1, r, vl, vr, d);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
  }
  void upd(int v, int l, int r, int i, int d) {
    upd(v, l, r, i, i + 1, d);
  }
  ll get(int v, int l, int r, int i) {
    push(v, l, r);
    if(l > i || i >= r)
      return 0;
    if(r - l == 1)
      return t[v];
    return get(2 * v + 1, l, l + r >> 1, i) + get(2 * v + 2, l + r >> 1, r, i);
  }
  ll get(int v, int l, int r, int vl, int vr) {
    push(v, l, r);
    if(vl >= r || l >= vr)
      return 0;
    if(vl <= l && r <= vr)
      return t[v];
    return get(2 * v + 1, l, l + r >> 1, vl, vr) + get(2 * v + 2, l + r >> 1, r, vl, vr);
  }
};

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];
  vector<ll> pref(n, 0);
  pref[0] = a[0];
  for(int i = 1; i < n; i++)
    pref[i] = pref[i - 1] + a[i];
  vector<ll> s(n, 0);
  T tr(N);
  for(int i = 0; i < n; i++) {
    s[i] = a[i] * 1ll * i + tr.get(0, 0, N, a[i]);
    if(i) s[i] += s[i - 1];
    for(int j = 1; j * a[i] < N; j++) {
      tr.upd(0, 0, N, j * a[i], min((j + 1) * a[i], N), -j * a[i]);
    }
  }
  tr = T(N);
  vector<ll> t(n, 0);
  for(int i = 0; i < n; i++) {
    if(i) t[i] += t[i - 1] + pref[i - 1];
    for(int j = 1; j * a[i] < N; j++) {
      t[i] += (-j * a[i]) * 1ll * tr.get(0, 0, N, j * a[i], min((j + 1) * a[i], N));
    }
    tr.upd(0, 0, N, a[i], 1);
  }
  for(int i = 0; i < n; i++) {
    cout << s[i] + t[i] << " ";
  }
}