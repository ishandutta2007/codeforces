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
const ll inf = 4e18;
//const ll mod = 1e9 + 7;
const ll mod = 998244353;

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

ll add(ll a, ll b) {
  return (a + b) % mod;
}

ll sub(ll a, ll b) {
  return (a - b + mod) % mod;
}

void solve() {
  int n; cin >> n;
  vector<int> x(n), y(n), s(n);
  vector<ll> pref(n + 1, 0);
  vector<ll> f(n, 0);
  for(int i = 0; i < n; i++)
    cin >> x[i] >> y[i] >> s[i];
  for(int i = 0; i < n; i++) {
    int j = upper_bound(all(x), y[i]) - x.begin();
    f[i] = add(sub(pref[i], pref[j]), sub(x[i], y[i]));
    pref[i + 1] = add(pref[i], f[i]);
  }
  ll ans = (x[n - 1] + 1) % mod;
  for(int i = 0; i < n; i++)
    if(s[i])
      ans = add(ans, f[i]);
  cout << ans << endl;
}