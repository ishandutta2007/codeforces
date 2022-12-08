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

//#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double pi = acos((double) -1);
//const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = 4e18;
//const ll mod = 1e9 + 7;
const ll mod = 998244353;

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
  vector<ll> a,t;
  T(){}
  T(vector<ll> a) : a(a) {
    t.resize(4 * a.size());
    build(0, 0, a.size());
  }
  void build(int v, int l, int r) {
    if(r - l == 1) {
      t[v] = a[l];
      return;
    }
    build(2 * v + 1, l, l + r >> 1);
    build(2 * v + 2, l + r >> 1, r);
    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
  }
  ll get(int v, int l, int r, int vl, int vr) {
    if(vl >= r || l >= vr)
      return inf;
    if(vl <= l && r <= vr)
      return t[v];
    return min(get(2 * v + 1, l, l + r >> 1, vl, vr), get(2 * v + 2, l + r >> 1, r, vl, vr));
  }
};

void solve() {
  int n, q; cin >> n >> q;
  vector<ll> a(n), b(n);
  for(ll &i : a)
    cin >> i;
  for(ll &i : b)
    cin >> i;
  vector<ll> pref(n);
  vector<ll> pp(n);
  pref[0] = b[0] - a[0];
  pp[0] = -pref[0];
  for(int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + b[i] - a[i];
    pp[i] = -pref[i];
  }
  T t(pref);
  T tt(pp);
  while(q--) {
    int l, r; cin >> l >> r; l--; r--;
    ll x = 0;
    if(l) x = pref[l - 1];
    if(t.get(0, 0, n, l, r + 1) < x) {
      cout << -1 << endl;
      continue;
    }
    if(pref[r] != x) {
      cout << -1 << endl;
      continue;
    }
    cout << -tt.get(0, 0, n, l, r + 1) - x << endl;
  }
}