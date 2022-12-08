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

const int M = 1e3 + 2;
ll dp[M][M][2];

ll stupid(int n, int k) {
  dp[0][0][0] = 1;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j <= k; j++) {
      dp[i][j][0] = (dp[i - 1][j][0] * 3 + dp[i - 1][j][1]) % mod;
      dp[i][j][1] = 0;
      if(j)
        dp[i][j][1] = (dp[i - 1][j - 1][0] + 3 * dp[i - 1][j - 1][1]) % mod;
    }
  }
  return dp[n][k][0] + dp[n][k][1];
}

const int N = 1e6 + 2;
ll fac[N], rev[N];

ll add(ll a, ll b) {
  a += b;
  if(a >= mod)
    a -= mod;
  return a;
}

ll mul(ll a, ll b) {
  return a * b % mod;
}

ll bp(ll a, ll k){
  if(k < 0) return 0;
  ll res = 1;
  while(k) {
    if(k & 1)
      res = mul(res, a);
    a = mul(a, a);
    k >>= 1;
  }
  return res;
}

void build() {
  fac[0] = 1;
  for(int i = 1; i < N; i++)
    fac[i] = mul(fac[i - 1], i);
  rev[N - 1] = bp(fac[N - 1], mod - 2);
  for(int i = N - 2; i >= 0; i--)
    rev[i] = mul(rev[i +  1], i + 1);
}

ll C(ll n, ll k) {
  if(n < 0 || k < 0) return 0;
  if(n < k) return 0;
  return mul(fac[n], mul(rev[n - k], rev[k]));
}

ll smart(ll n, ll k) {
  if(k == 0)
    return bp(3, n);
  build();
  ll ans = 0;
  for(int i = 1; i <= k; i++) {
    ll red = C(k - 1, i - 1);
    ll left = n - k + 1;
    ll blue = C(left - 1, i - 1);
    ll pwr = bp(3, (n + 1 - 2 * i));
    ans = add(ans, mul(pwr, mul(red, blue)));

    blue = C(left - 1, i);
    pwr = bp(3, (n - 2 * i));
    ans = add(ans, mul(pwr, mul(red, blue)));
  }
  return ans;
}

void solve() {
  int n, k; cin >> n >> k;
  cout << smart(n, k) << endl;
}