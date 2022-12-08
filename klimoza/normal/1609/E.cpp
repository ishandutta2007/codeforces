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

struct DP {
  int a, b, c, ab, bc, abc;
};

DP operator+(DP& x, DP& y) {
  return {x.a + y.a, x.b + y.b, x.c + y.c, min(x.a + y.ab, x.ab + y.b), min(x.b + y.bc, x.bc + y.c), min(min(x.a + y.abc, x.abc + y.c), x.ab + y.bc)};
}

DP zr(char c) {
  if(c == 'a')
    return {1, 0, 0, 0, 0 ,0};
  else if(c == 'b')
    return {0, 1, 0, 0, 0 ,0};
  else
    return {0, 0, 1, 0, 0 ,0};
}

struct T {
  string s;
  vector<DP> t;
  T() {}
  T(string s) : s(s) {
    t.resize(4 * s.size());
    build(0, 0, s.size());
  }
  void build(int v, int l, int r) {
    if(r - l == 1) {
      t[v] = zr(s[l]);
      return;
    }
    build(2 * v + 1, l, l + r >> 1);
    build(2 * v + 2, l + r >> 1, r);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
  }
  void upd(int v, int l, int r, int i, char c) {
    if(i >= r || i < l)
      return;
    if(r - l == 1) {
      t[v] = zr(c);
      return;
    }
    upd(2 * v + 1, l, l + r >> 1,i, c);
    upd(2 * v + 2, l + r >> 1, r, i, c);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
  }
};

void solve() {
  int n, q; cin >> n >> q;
  string s; cin >> s;
  T t(s);
  while(q--) {
    int i; char c; cin >> i >> c; i--;
    t.upd(0, 0, s.size(), i, c);
    cout << t.t[0].abc << endl;
  }
}