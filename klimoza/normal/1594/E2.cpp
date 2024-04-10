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

#define int long long

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

map<string, int> id = {{"white",  0},
                       {"yellow", 1},
                       {"green",  2},
                       {"blue",   3},
                       {"red",    4},
                       {"orange", 5}};

struct Item {
  int x;
  int d[6];
};

struct Point {
  int x, col;
};

ll add(ll a, ll b) {
  a += b;
  if (a >= mod)
    a -= mod;
  return a;
}

ll sub(ll a, ll b) {
  a -= b;
  if(a < 0)
    a += mod;
  return a;
}

ll mul(ll a, ll b) {
  return a * b % mod;
}

ll sum(Item &x) {
  ll s = 0;
  for (int i = 0; i < 6; i++)
    s = add(s, x.d[i]);
  return s;
}

void solve() {
  int k;
  cin >> k;
  vector<vector<Point>> p(k);
  int n;
  cin >> n;
  while (n--) {
    int x;
    string s;
    cin >> x >> s;
    int l = -1;
    int y = x;
    while (y) {
      l++;
      y >>= 1;
    }
    p[l].push_back({x, id[s]});
  }
  vector<Item> cur;
  ll fr = 1;
  for (int l = k - 1; l >= 0; l--) {
    vector<Item> ncur;
    for (auto v : p[l]) {
      ll cc = 1;
      int cnt = 0;
      for (auto u : cur) {
        if (((u.x) >> 1) == v.x) {
          cc = mul(cc, sub(sum(u), add(u.d[v.col], u.d[v.col ^ 1])));
          cnt++;
        }
      }
      if (cnt == 1 && l != (k - 1))
        cc = mul(cc, mul(4, fr));
      if (cnt == 0 && l != (k - 1))
        cc = mul(cc, mul(16, mul(fr, fr)));
      ncur.push_back({v.x, {0, 0, 0, 0, 0, 0}});
      ncur.back().d[v.col] = cc;
    }

    for(auto v : cur) {
      bool fl = false;
      for(auto u : p[l]) {
        if(u.x == (v.x >> 1)) {
          fl = true;
          break;
        }
      }
      for(auto u : cur) {
        if((u.x == (v.x ^ 1)) && (v.x & 1)) {
          fl = true;
          break;
        }
      }
      if(fl) continue;
      Point tmp = Point{v.x >> 1, -1};

      vector<Item> kek;
      for (auto u : cur) {
        if (((u.x) >> 1) == tmp.x) {
          kek.push_back(u);
        }
      }
      ncur.push_back({tmp.x, {0, 0, 0, 0, 0, 0}});
      for(int i = 0; i < 6; i++) {
        if(kek.size() == 1) {
          ncur.back().d[i] = mul(mul(4, fr), sub(sum(kek[0]), add(kek[0].d[i], kek[0].d[i ^ 1])));
        } else {
          ncur.back().d[i] = mul(sub(sum(kek[1]), add(kek[1].d[i], kek[1].d[i ^ 1])), sub(sum(kek[0]), add(kek[0].d[i], kek[0].d[i ^ 1])));
        }
      }
    }

    if(l != (k - 1))
      fr = mul(mul(4, fr), mul(4, fr));
    cur = ncur;
//    cout << l << ":" << endl;
//    for(auto u : cur) {
//      cout << u.x << " -- ";
//      for(int i = 0; i < 6; i++)
//        cout << u.d[i] << " ";
//      cout << endl;
//    }
//    cout << "fr -- " << fr << endl;
  }
  assert(cur.size() < 2);
  if(!cur.empty())
    cout << sum(cur[0]) << endl;
  else
    cout << mul(6, fr) << endl;
}