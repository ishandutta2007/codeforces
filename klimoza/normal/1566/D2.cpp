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

struct Seg {
  int i, l, r;
};

void solve() {
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    int k = n * m;
    map<int, vector<Seg>> f;
    vector<int> a(k);
    for(int i = 0; i < k; i++)
      cin >> a[i];
    vector<int> b = a;
    sort(all(b));
    vector<pair<int, int>> ed;
    for(int i : b) {
      if(ed.empty() || ed.back().first != i)
        ed.push_back({i, 0});
      ed.back().second++;
    }
    reverse(all(ed));
    int lvl = 0;
    int cnt = 0;
    while(!ed.empty()) {
      int x = min(ed.back().second, m - cnt);
      f[ed.back().first].push_back({lvl, cnt, cnt + x - 1});
      cnt += x;
      ed.back().second -= x;
      if(!ed.back().second) ed.pop_back();
      if(cnt == m) {
        cnt = 0;
        lvl++;
      }
    }
    vector<vector<bool>> used(n, vector<bool>(m, false));
    for(auto &u : f) {
      reverse(all(u.second));
//      cout << u.first << endl;
//      for(auto v : u.second)
//        cout << v.i << " " << v.l << " " << v.r << endl;
    }
    ll ans = 0;
    for(int i = 0; i < k; i++) {
      auto v = f[a[i]].back();
//      cout << i << " " << v.i << " " << v.l << " " << v.r << endl;
      for(int j = 0; j < v.r; j++)
        if(used[v.i][j])
          ans++;
      used[v.i][v.r] = true;
      f[a[i]].back().r--;
      if(v.l == v.r)
        f[a[i]].pop_back();
    }
    cout << ans << endl;
  }
}