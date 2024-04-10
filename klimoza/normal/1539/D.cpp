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
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
const ll mod = 1e9 + 7;
// const ll mod = 998244353;

void solve();
void scan();

signed main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
  cout << fixed; cout.precision(15);
  solve();
  return 0;
}

void solve() {
  int n; cin >> n;
  deque<pair<ll, ll>> a;
  for(int i = 0 ; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    a.push_back(mp(y, x));
  }
  sort(all(a));
  ll tot = 0;
  ll ans = 0;
  while(!a.empty()) {
    while(!a.empty() && !a.front().second)
      a.pop_front();
    while(!a.empty() && !a.back().second)
      a.pop_back();
    if(a.empty())
      break;
    if(tot >= a.front().first) {
      tot += a.front().second;
      ans += a.front().second;
      a.pop_front();
    } else {
      ll l = a.front().first - tot;
      ll x = min(l, a.back().second);
      tot += x;
      ans += 2 * x;
      a.back().second -= x;
    }
  }
  cout << ans << endl;
}