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

const int N = 51;
int p[N], sz[N];

void build() {
  for (int i = 0; i < N; i++) {
    p[i] = i;
    sz[i] = 1;
  }
}

int get_par(int k) {
  if (p[k] == k) return k;
  return p[k] = get_par(p[k]);
}

void merge(int a, int b) {
  a = get_par(a);
  b = get_par(b);
  if (sz[a] < sz[b]) swap(a, b);
  p[b] = a;
  sz[a] += sz[b];
}

struct Edge {
  int v, u;
  ll w;
};

bool cmp(Edge x, Edge y) {
  return pair<ll, pair<ll, ll>>{x.w, {x.v, x.u}} < pair<ll, pair<ll, ll>>{y.w, {y.v, y.u}};
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<Edge> e(m);
  for (int i = 0; i < m; i++) {
    cin >> e[i].v >> e[i].u >> e[i].w;
    e[i].v--;
    e[i].u--;
  }
  sort(all(e), [](Edge x, Edge y) { return x.w < y.w; });
  vector<ll> kek;
  kek.push_back(-1);
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      kek.push_back((e[i].w + e[j].w) / 2 + 1);
    }
    kek.push_back(e[i].w);
  }
  sort(all(kek));
  kek.erase(unique(all(kek)), kek.end());
//  for(ll i : kek)
//    cout << i << " " ;
//  cout << endl;
  vector<pair<ll, ll>> ans(kek.size());
  for (int i = 0; i < kek.size(); i++) {
    vector<Edge> tmp = e;
    sort(all(tmp), [&](Edge x, Edge y) { return abs(kek[i] - x.w) < abs(kek[i] - y.w); });
    for (int j = 0; j < m; j++) {
      if( tmp[j].w <= kek[i])
        tmp[j] = {tmp[j].v, tmp[j].u, -tmp[j].w};
      else
        tmp[j] = {tmp[j].v, tmp[j].u, tmp[j].w};
    }
    build();
    for (int j = 0; j < m; j++) {
      if (get_par(tmp[j].v) == get_par(tmp[j].u)) continue;
//      if(kek[i] == 3)
//        cout << tmp[j].v + 1 << " " << tmp[j].u + 1 << " " << tmp[j].w << endl;
      ans[i].first += tmp[j].w;
      if ((tmp[j].w <= 0 && (-tmp[j].w) <= kek[i]))
        ans[i].second++;
      else
        ans[i].second--;
      merge(tmp[j].v, tmp[j].u);
    }
//    cout << kek[i] << " === " << ans[i].first << ", " << ans[i].second << endl;
  }
  ll p, k, a, b, c;
  cin >> p >> k >> a >> b >> c;
  ll lst = 0;
  ll an = 0;
  for (int i = 0; i < k; i++) {
    ll q;
    if (i < p) {
      cin >> q;
    } else {
      q = (lst * a + b) % c;
    }
    lst = q;
    int j = upper_bound(all(kek), q) - kek.begin() - 1;
    ll cur = (ans[j].first + (ans[j].second) * q);
//    cout << q << " " << cur << endl;
    an = an ^ cur;
  }
  cout << an << endl;
}