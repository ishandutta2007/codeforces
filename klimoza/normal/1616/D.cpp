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
const ld eps = 5e-7;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = 4e18;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

void solve();
signed main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
  cout << fixed; cout.precision(15);
  solve();
  return 0;
}

struct T {
  vector<ll> t;
  T(int n) {
    t.assign(4 * n, -inf);
  }
  int get(int v, int l, int r, ll d) {
    if(d - t[v] >= 0) return -1;
    if(r - l == 1)
      return l;
    int m1 = get(2 * v + 2, l + r >> 1, r, d);
    if(m1 == -1) return get(2 * v + 1, l, l + r >> 1, d);
    return m1;
  }
  void upd(int v, int l, int r, int i, ll d) {
    if(i >= r || i < l) return;
    if(r - l == 1) {
      t[v] = d;
      return;
    }
    upd(2 * v + 1, l, l + r >> 1, i ,d);
    upd(2 * v + 2, l + r >> 1, r, i, d);
    t[v] = max(t[2 * v + 1], t[2 * v + 2]);
  }
};

void solve() {
  int tp; cin >> tp;
  while(tp--) {
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
      cin >> a[i];
    ll x; cin >> x;
    for(ll &i : a)
      i -= x;
    T t(n + 1);
    vector<ll> pref(n + 1, 0);
    for(int i = 0; i < n; i++)
      pref[i + 1] = pref[i] + a[i];
    vector<int> prv(n, -1);
    for(int i = 1; i < n; i++) {
      t.upd(0, 0, n + 1, i - 1, pref[i - 1]);
      prv[i] = t.get(0, 0, n + 1, pref[i + 1]);
      prv[i] = max(prv[i], prv[i - 1]);
    }
    if(prv.back() == -1) {
      cout << n << endl;
      continue;
    }
    vector<int> dp(n, inf0);
    multiset<int> vl = {};
    int l = 0, r = 0;
    while(r < n) {
      int p = -1;
      if(r)
        p = prv[r - 1];
//      cout << r << endl;
      if(p == -1) {
        dp[r] = 1;
      } else {
        while(l < p) {
          vl.erase(vl.find(dp[l]));
          l++;
        }
//        if(r == 6)
//          cout << l << " lol " << p << endl;
        dp[r] = 1 + (*vl.begin());
      }
      vl.insert(dp[r]);
      r++;
    }
    int p = prv.back();
    while(l < p) {
      vl.erase(vl.find(dp[l]));
      l++;
    }
//    cout << prv[2] << endl;
//    for(int i = 0; i < n; i++)
//      cout << i << " " << dp[i] << endl;
    int ans = n - (*vl.begin());
    cout << ans << endl;
  }
}