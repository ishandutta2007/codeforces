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

const int N = 3e5  + 2;

int n;
int a[N], b[N];
int d[N];
int p[N];

struct T {
  vector<pair<int, int>> t;
  vector<int> a;
  T(){}
  T(vector<int> a) : a(a) {
    t.resize(4 * a.size());
    build(0, 0, a.size());
  }
  void build(int v, int l, int r) {
    if(r - l == 1) {
      t[v] = {a[l], l};
      return;
    }
    build(2 * v + 1,l ,l + r >> 1);
    build(2 * v + 2,l + r >> 1, r);
    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
  }
  pair<int, int> get(int v, int l, int r, int vl, int vr) {
    if(vl >= r || l >= vr)
      return {inf0, inf0};
    if(vl <= l && r <= vr)
      return t[v];
    return min(get(2 * v + 1, l, l + r >> 1, vl, vr), get(2 * v + 2, l + r >> 1, r, vl, vr));
  }
  void upd(int v, int l, int r, int i) {
    if(i >= r || i < l) return;
    if(r - l == 1) {
      t[v] = {inf0, l};
      return;
    }
    upd(2 * v + 1, l, l + r >> 1, i);
    upd(2 * v + 2, l + r >> 1, r, i);
    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
  }
};

void bfs() {
  fill(d, d + N, inf0);
  deque<int> q;
  map<int, vector<int>> f;
  vector<int> tmp(n);
  for(int i = 0; i < n; i++)
    tmp[i] = i - a[i];
  T t(tmp);
  for(int i = 0; i < n; i++) {
    if(i - a[i] + 1 <= 0) {
      d[i] = 1;
      p[i] = -1;
      q.push_back(i);
      t.upd(0, 0, n, i);
    }
    f[i + b[i]].push_back(i);
  }
  while(!q.empty()) {
    int v = q.front();
    q.pop_front();
    for(int u : f[v]) {
      while(true) {
        auto[h, i] = t.get(0, 0, n, u, n);
        if (h > u) break;
        d[i] = d[v] + 1;
        p[i] = u;
        q.push_back(i);
        t.upd(0, 0, n, i);
      }
    }
  }
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  for(int i = 0; i < n ;i++)
    cin >> b[i];
  bfs();
  if(d[n - 1] == inf0)
    cout << -1 << endl;
  else {
    cout << d[n - 1] << endl;
    int cur = n - 1;
    while(true) {
      if(p[cur] == -1) {
        cout << 0 << endl;
        break;
      }
      cout << p[cur] + 1 << " ";
      cur = p[cur] + b[p[cur]];
    }
  }
}