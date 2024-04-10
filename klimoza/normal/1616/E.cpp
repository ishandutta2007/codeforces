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

const int A = 26;
vector<int> c[A];

struct T {
  vector<int> t;
  T(int n) {
    t.assign(4 * n, 0);
  }
  void upd(int v, int l, int r, int i) {
    if(i >= r || i < l) return;
    if(r - l == 1) {
      t[v]++;
      return;
    }
    upd(2 * v + 1, l, l + r >> 1, i);
    upd(2 * v + 2, l + r >> 1, r, i);
    t[v] = t[2 * v+  1] + t[2 * v + 2];
  }
  int get(int v, int l, int r, int vl, int vr) {
    if(vl >= r|| l >= vr) return 0;
    if(vl <= l && r <= vr) return t[v];
    return get(2 * v + 1, l, l + r >> 1, vl, vr) + get(2 * v + 2, l + r >> 1, r, vl, vr);
  }
};

void solve() {
  int q; cin >> q;
  while(q--) {
    int n; cin >> n;
    string s; cin >> s;
    string t; cin >> t;
    for(int i = 0; i < A; i++)
      c[i].clear();
    for(int i = 0; i < n; i++)
      c[s[i] - 'a'].push_back(i);
    for(int i = 0; i < A; i++)
      reverse(all(c[i]));
    ll cur = 0;
    T tr(n);
    ll ans = inf;
    for(int i = 0; i < n; i++) {
      int cr = t[i] - 'a';
      for(int j = 0; j < cr; j++) {
        if(c[j].empty()) continue;
        int k = c[j].back();
        int sm = tr.get(0, 0, n, k, n);
        ans = min(ans, cur + abs(k + sm - i));
      }
      if(c[cr].empty()) {
        break;
      }
      int sm = tr.get(0, 0, n, c[cr].back(), n);
      cur += abs(c[cr].back() + sm - i);
      tr.upd(0, 0, n, c[cr].back());
      c[cr].pop_back();
    }
    if(ans == inf)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
}