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

struct Seg {
  int l, r;
};

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll &i : a)
      cin >> i;
    sort(all(a));
    vector<Seg> ed(m);
    vector<vector<Seg>> f(n + 1);
    for (int i = 0; i < m; i++) {
      cin >> ed[i].l >> ed[i].r;
      int j = lower_bound(all(a), ed[i].l) - a.begin();
      if (j == n)
        f.back().push_back(ed[i]);
      else if (a[j] <= ed[i].r)
        continue;
      else
        f[j].push_back(ed[i]);
    }
    for (int i = 0; i < n; i++)
      f[i].push_back({a[i], a[i]});
    for (int i = 1; i < n + 1; i++)
      f[i].push_back({a[i - 1], a[i - 1]});
//    for(auto v : f.back())
//      cout << v.l << " " << v.r << " LOL\n";
    for (auto &v : f)
      sort(all(v), [](Seg x, Seg y) { return mp(x.l, x.r) < mp(y.l, y.r); });
    vector<vector<ll>> dp(n + 1);
    for(int i = 0; i < n + 1; i++)
      dp[i].resize(f[i].size());
    for (int i = 0; i < f[0].size(); i++)
      dp[0][i] = 0;
    for (int i = 0; i < n; i++) {
      if (!i) {
        ll mn = inf;
        for (auto j : f[i])
          mn = min(mn, (ll) j.r);
        for (int j = 0; j < f[i + 1].size(); j++) {
          dp[i + 1][j] = 2 * min(f[i + 1][j].l - a[i], a[i] - mn) + max(f[i + 1][j].l - a[i], a[i] - mn);
        }
      } else {
        {
          ll mn = inf;
          ll x = f[i].back().r;
          for (int j = (int) (f[i].size()) - 2; j >= 0; j--) {
            mn = min(mn, dp[i][j] - x);
            x = min(x, f[i][j].r);
          }
//          cout << i << " " << mn << endl;
          for (int j = 0; j < f[i + 1].size(); j++) {
            dp[i + 1][j] = a[i] + mn + 2 * (f[i + 1][j].l - a[i]);
//            cout << dp[i + 1][j] << " " << i + 1 << " " << j << endl;
          }
        }
        {
          ll mn = inf;
          ll x = f[i].back().r;
          for (int j = (int) (f[i].size()) - 2; j >= 0; j--) {
            mn = min(mn, dp[i][j] - 2 * x);
            x = min(x, f[i][j].r);
          }
          for (int j = 0; j < f[i + 1].size(); j++)
            dp[i + 1][j] = min(dp[i + 1][j], 2 * a[i] + mn + (f[i + 1][j].l - a[i]));
        }
      }
    }
    cout << dp.back().back() << endl;
  }
}