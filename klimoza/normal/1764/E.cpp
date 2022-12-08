#include <cmath>
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

void solve() {
  int t; cin >> t;
  while(t--) {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    vector<pair<int, int>> c(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      c[i] = mp(a[i], b[i]);
    }
    if(a[0] >= k)
      cout << "YES\n";
    else if(a[0] + b[0] < k)
      cout << "NO\n";
    else {
      reverse(all(c));
      c.pop_back();
      sort(all(c), [&](pair<int, int> x, pair<int, int> y) {return x.first + x.second > y.first + y.second;});
      k -= b[0];
      bool fl = false;
      for(int i = 0; i < c.size(); i++) {
        auto v = c[i];
        if(k <= v.first) {
          fl = true;
          break;
        }
        if(k > v.first + v.second) {
          fl = false;
          break;
        }
        if(i + 1 < c.size() && c[i + 1].first + c[i + 1].second >= k) {
          fl = true;
          break;
        }
        k -= v.second;
      }
      if(fl)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}