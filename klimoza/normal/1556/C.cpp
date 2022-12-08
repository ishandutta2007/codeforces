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

int intersect(pair<int, int> x1, pair<int, int> x2) {
  if(x1.first > x1.second || x2.first > x2.second) return 0;
  if(x1 >= x2) swap(x1, x2);
  if(x1.second < x2.first) return 0;
  if(x1.second >= x2.first && x1.second <= x2.second)
    return x1.second - x2.first + 1;
  return x2.second - x2.first + 1;
}

void solve() {
  int n; cin >> n;
  vector<int> c(n);
  for(int i = 0; i < n; i++) {
    cin >> c[i];
  }
  ll ans = 0;
  for(int i = 0; i < n; i += 2) {
    ll mm = 0;
    ll ff = 0;
    ll cur = 0;
    for(int j = i + 1; j < n; j++) {
      if(j % 2 == 0) {
        cur += c[j];
        ff += c[j];
        ff = max(ff, 0ll);
        continue;
      } else {
        pair<int, int> x1 = {0ll, c[i] - mm};
        pair<int, int> x2 = {0ll, c[j] - ff};
        ll an = intersect(x1, x2);
        if(mm == 0 || ff == 0)
          an = max(0ll, an - 1);
        ans += an;
        cur -= c[j];
        ff -= c[j];
        ff = max(ff, 0ll);
        mm = max(mm, -cur);
//        cout << x1.first << " " << x1.second << " " << x2.first << " " << x2.second << endl;
//        cout << i << " " << j << " " << ans << endl;
      }
    }
  }
  cout << ans << endl;
}