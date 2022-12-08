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
typedef double ld;

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
  freopen(PATH1, "r", stdin);
  freopen(PATH2, "w", stdout);
#endif
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed;
  cout.precision(15);
  solve();
  return 0;
}

ll number_of_odd(ll N) {
  if(N <= 2)
    return 0;
  else if (N & 1) {
    return (N / 2);
  } else {
    return (N / 2) - 1;
  }
}

ll number_of_good_below(ll N) {
  if(N <= 2)
    return 0;
  else if(N <= 4)
    return 1;
  else
    return N - 3 - number_of_odd(N / 2);
}

void solve() {
  ll n; cin >> n;
  ll l = 0, r = 1e17;
  while(r - l > 1) {
    ll m = l + r >> 1;
    if(number_of_good_below(m) >= n)
      r = m;
    else
      l = m;
  }
  cout << r << endl;
}