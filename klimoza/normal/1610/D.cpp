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

int getkek(int a) {
  int ans = 0;
  while(a % 2 == 0) {
    ans++;
    a >>= 1;
  }
  return ans;
}

ll mul(ll a, ll b) {
  return a * b % mod;
}

ll bp(ll a, ll k) {
  ll res = 1;
  while(k) {
    if(k & 1)
      res = mul(res, a);
    a = mul(a, a);
    k >>= 1;
  }
  return res;
}

ll sub(ll a, ll b) {
  a -= b;
  if(a < 0)
    a += mod;
  return a;
}

ll add(ll a, ll b) {
  a += b;
  if(a >= mod)
    a -= mod;
  return a;
}

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  int c1 = 0;
  int c2 = 0;
  vector<int> f2(31, 0);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if(a[i] & 1)
      c1++;
    else {
      f2[getkek(a[i])]++;
      c2++;
    }
  }
  ll ans = mul(sub(bp(2, c1), 1), bp(2, c2));
  ll up = 0;
  for(int i = 30; i >= 0; i--) {
    if(!f2[i]) continue;
    ans = add(ans, mul(bp(2, up), sub(bp(2, f2[i] - 1), 1)));
    up += f2[i];
  }
  cout << ans << endl;
}