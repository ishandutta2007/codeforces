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

//#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double pi = acos((double) -1);
const ld eps = 1e-8;
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

ll add(ll a, ll b) {
  a += b;
  if(a >= mod)
    a -= mod;
  return a;
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

void solve(){
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
      cin >> a[i];
    vector<int> b = a;
    sort(all(b));
    int c = 0;
    for(int i = 0; i < n; i++)
      if(a[i] != b[i])
        c++;
    if(c % 2 == 1)
      assert(false);
    c /= 2;
    ll ans = 0;
    ll T = mul(n, mul(n - 1, bp(2, mod - 2)));
    for(ll i = c; i >= 1; i--) {
      ans = add(ans, mul(T, bp(mul(i, i), mod - 2)));
    }
    cout << ans << endl;
  }
}